//miinwindows.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "led_ring_widget.h"
#include "serialmanager.h"
#include "motor_lens.h"
#include "cameramanager.h"
#include "fluorescence.h"
#include <QMessageBox>
#include <QDebug>
#include <QStandardPaths>
#include <QDateTime>
#include <QFile>
#include <QIODevice>
#include <QFileDialog>
#include <QSettings>
#include <QPainter>




SerialManager *serialManager;

QTimer* autoScanTimer = nullptr;
int currentLedIndex = 0;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    //串口初始化
    serialManager = new SerialManager(this);
    previousPortNames = QStringList();
    refreshSerialPorts();

    connect(serialManager, &SerialManager::dataReceived, this, &MainWindow::appendSerialData);

    //定时扫描串口
    portScanTimer = new QTimer(this);
    connect(portScanTimer, &QTimer::timeout, this, &MainWindow::refreshSerialPorts);
    portScanTimer->start(2000);

    //相机
    camera = new CameraManager(this);
    ui->pushButton_AutoExpo->setChecked(true);
    ui->spinBox_ExposureTime->setReadOnly(true);
    ui->spinBox_ExpoGain->setReadOnly(true);
    camera->setAutoExposure(true);
    connect(camera, &CameraManager::exposureChanged, this, &MainWindow::updateExposureDisplay);


    //led控件初始化
    ringWidget = new LedRingWidget(this, serialManager);  // 将其传给 LED 控件
    ui->verticalLayout->addWidget(ringWidget);

    //led颜色设置
    // 颜色模式列表
    struct ColorMode {
        QString name;
        QString hex; // 或 QColor
    };

    QVector<ColorMode> colorModes = {
        {"W",   "#ffffff"},
        {"R",   "#ff0000"},
        {"G",   "#00ff00"},
        {"B",   "#0000ff"},
    };

    // 添加到下拉框
    for (const auto& mode : colorModes) {
        QPixmap pix(20,20);
        pix.fill(Qt::transparent);
        QPainter p(&pix);
        p.setRenderHint(QPainter::Antialiasing);
        p.setBrush(QColor(mode.hex));
        p.setPen(Qt::NoPen);
        p.drawEllipse(0,0,20,20);
        ui->comboBox_LedColorMode->addItem(QIcon(pix), mode.name, mode.hex);
    }


    //镜头电机组件
    motorLens = new MotorLens(serialManager, this);

    //定时拍照
    snapshotTimer = new QTimer(this);
    connect(snapshotTimer, &QTimer::timeout, this, &MainWindow::on_pushButton_Snap_clicked);

    // 设置初始目录
    QSettings settings("YourCompany", "YourApp");
    QString lastDir = settings.value("lastSaveDir", QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)).toString();
    ui->lineEdit_FilePath->setText(lastDir);
    camera->setSaveDirectory(ui->lineEdit_FilePath->text());

    //荧光
    fluorescence = new FluorescenceControl(serialManager, this);

}

MainWindow::~MainWindow()
{

    delete ui;
    delete snapshotTimer;
    delete motorLens;
    delete ringWidget;
    delete camera;
    delete portScanTimer;
    delete serialManager;
}

void MainWindow::appendSerialData(const QByteArray &data)
{
    // 显示在 QTextEdit 控件中（例如 ui->textEdit_SerialMonitor）
    ui->textEdit_SerialMonitor->moveCursor(QTextCursor::End);
    ui->textEdit_SerialMonitor->insertPlainText(QString::fromUtf8(data));
}

// 图像到达通知：从相机中拉图像
void MainWindow::onImageArrived() {
    if (camera) {
        camera->fetchImage();
    }
}

// 图像准备好：显示到 UI
void MainWindow::onImageReady(const QImage& img) {
    ui->labeldisplay->setPixmap(QPixmap::fromImage(img).scaled(ui->labeldisplay->size(), Qt::KeepAspectRatio));

}

// 拍照完成通知：从相机中拉静态图像
void MainWindow::onStillImageArrived() {
    if (camera) {
        camera->fetchStillImage();
    }
}

void MainWindow::updateExposureDisplay() {
    unsigned exp = 0;
    unsigned short gain = 0;
    if (camera->getExposureTime(exp)) {
        ui->spinBox_ExposureTime->blockSignals(true); // 防止触发 valueChanged
        ui->spinBox_ExposureTime->setValue(exp / 1000);
        ui->spinBox_ExposureTime->blockSignals(false);
    }
    if (camera->getGain(gain)) {
        ui->spinBox_ExpoGain->blockSignals(true); // 防止触发 valueChanged
        ui->spinBox_ExpoGain->setValue(gain);
        ui->spinBox_ExpoGain->blockSignals(false);
    }
}

void MainWindow::on_pushButton_All_On_clicked()
{
    for (int i = 0; i <ringWidget->ledStates.size(); ++i) {
        ringWidget->ledStates[i].on = true;
    }
    ringWidget->refreshLed();
}

void MainWindow::on_pushButton_All_Off_clicked()
{
    for (int i = 0; i <ringWidget->ledStates.size(); ++i) {
        ringWidget->ledStates[i].on = false;
    }
    ringWidget->refreshLed();
}

void MainWindow::refreshSerialPorts()
{
    QStringList currentPortNames;
    const auto ports = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : ports) {
        currentPortNames << info.portName();
    }

    // 如果串口列表没有变化就不刷新
    if (currentPortNames == previousPortNames)
        return;

    previousPortNames = currentPortNames;

    ui->comboBox_Port->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        //QString fullName = QString("%1 %2").arg(info.portName(),info.description());
        //ui->comboBox_Port->addItem(fullName, info.portName()); // 使用显示名，但内部存储 portName
        ui->comboBox_Port->addItem(info.portName());
    }


}

void MainWindow::on_pushButton_PortSwitch_toggled(bool checked)
{

    if (checked) {
        QString portName = ui->comboBox_Port->currentText();

        if (ui->comboBox_Port){
            serialManager->openPort(portName, 115200);
            if (serialManager->isOpen()){
                ui->pushButton_PortSwitch->setText("关闭");
            }
            else
            {
                ui->pushButton_PortSwitch->blockSignals(true);
                ui->pushButton_PortSwitch->setChecked(false);
                ui->pushButton_PortSwitch->blockSignals(false);
            }
        }
    } else {
        serialManager->closePort();
        if (!serialManager->isOpen()){
            ui->pushButton_PortSwitch->setText("打开");
        }
        else{
            ui->pushButton_PortSwitch->blockSignals(true);
            ui->pushButton_PortSwitch->setChecked(true);
            ui->pushButton_PortSwitch->blockSignals(false);
        }
    }
}



void MainWindow::on_pushButton_HoldOFF_toggled(bool checked)
{
    motorLens->setEnabled(!checked);
}


void MainWindow::on_verticalSlider_LensSpeed_valueChanged(int value)
{
    int speed=abs(value);
    int frequency=speed>4 ? pow(1.13,((speed-5)/1.53)): 0;//int frequency=speed>4 ? pow(1.1,((speed-5)/1.53)): 0;
    if (frequency>2500) frequency=2500;
    if (frequency) motorLens->setDirection(value>0 ? 1 : 0);
    ui->lcdNumber_LensFreq->display(frequency);
    motorLens->setEnabled(!ui->pushButton_HoldOFF->isChecked());
    //qDebug()<<frequency;
    motorLens->setFrequency(frequency);
}





void MainWindow::on_verticalSlider_LensSpeed_sliderReleased()
{
    ui->verticalSlider_LensSpeed->setValue(0);
}


void MainWindow::on_pushButton_AutoExpo_toggled(bool checked)
{
    ui->spinBox_ExposureTime->setReadOnly(checked);
    ui->spinBox_ExpoGain->setReadOnly(checked);
    camera->setAutoExposure(checked);
    if (!checked) {
        camera->put_ExpoTime(ui->spinBox_ExposureTime->value());
    }

}


void MainWindow::on_spinBox_ExposureTime_valueChanged(int arg1)
{
    camera->put_ExpoTime(arg1);
}


void MainWindow::on_pushButton_CameraSwitch_toggled(bool checked)
{
    if (checked) {
        // 打开相机
        if (camera->open()) {
            // 连接图像信号（如未连接过）
            connect(camera, &CameraManager::imageArrived, this, &MainWindow::onImageArrived);
            connect(camera, &CameraManager::imageReady, this, &MainWindow::onImageReady);
            connect(camera, &CameraManager::stillImageArrived, this, &MainWindow::onStillImageArrived);
            ui->pushButton_CameraSwitch->setText("关闭相机");
        } else {
            QMessageBox::warning(this, "错误", "相机打开失败！");
            ui->pushButton_CameraSwitch->setChecked(false); // 打开失败时重置按钮状态
        }
    } else {
        // 关闭相机
        camera->close();
        ui->pushButton_CameraSwitch->setText("打开相机");
    }

}


void MainWindow::on_spinBox_ExpoGain_valueChanged(int arg1)
{
    camera->put_ExpoGain(arg1);
}

void MainWindow::on_pushButton_Snap_clicked()
{
    QString ledStateStr;
    if (ringWidget) {
        QVector<QPair<bool, QString>> states = ringWidget->getLedStates();

        quint64 binaryValue = 0;
        QString hexString;

        // 逻辑：将 states 视为一个超长的二进制数
        // 由于 43 位超过了 int (32位)，我们需要用 quint64 或分段处理i

        for (int i = 0; i < states.size(); ++i) {
            // 将布尔值转为 bit 存入临时变量
            if (states[i].first) {
                // 这里假设 states[0] 是最高位
                binaryValue |= (1ULL << i);
            }

            // 每处理完 4 位，或者处理到最后一位时，转一次十六进制（可选分段处理更安全）
        }

        // 直接利用 QString 转换输出
        // 43 位数据建议直接转为 16 进制字符串
        ledStateStr = QString::number(binaryValue, 16).toUpper();

        // 如果需要固定长度（不足 11 位补 0）
        ledStateStr = ledStateStr.rightJustified(11, '0');

        QString colorName = ui->comboBox_LedColorMode->currentText();
        ledStateStr += "_" + colorName;
    } else {
        ledStateStr = "UNKNOWN";
    }

    if (camera && camera->isOpen()) {
        camera->setLedStateString(ledStateStr);  // 把 LED 状态传给 CameraManager
        disconnect(camera, &CameraManager::stillImageArrived, nullptr, nullptr); // 先断开所有旧的连接，避免重复
        connect(camera, &CameraManager::stillImageArrived, this, [=]() {
            camera->fetchStillImageTif();
        });
        camera->snapImage();  // 发起静态图像拍摄
    } else {
        // -------- 无相机：模拟模式 --------
        qDebug() << "无相机连接，执行模拟拍照";

        // 1. 生成时间戳
        QString timestamp = QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss");

        // 3. 构造文件名
        QString filename = QString("snapshot_%1_LED%2.tif")
                               .arg(timestamp)
                               .arg(ledStateStr);

        QString saveDir = "D:/snap_test"; // ← 替换为实际保存路径
        QDir().mkpath(saveDir);
        QString filePath = QDir(saveDir).filePath(filename);

        // 4. 输出文件名
        qDebug() << "模拟保存文件名:" << filePath;

        // 5. 生成模拟图像保存
        QImage fake(640, 480, QImage::Format_RGB888);
        fake.fill(Qt::gray);
        fake.save(filePath, "TIFF");

        // 6. 发送信号以便 UI 显示
        if (camera)
            emit camera->imageReady(fake);
    }

}

void MainWindow::on_pushButton_SnapScheduled_toggled(bool checked)
{
    if (checked) {
        // 1. 进入定时扫描模式，关闭 UI 自动曝光（切换为手动控制）
        ui->pushButton_AutoExpo->setChecked(false);
        qDebug() << "Current AutoExpo state:" << ui->pushButton_AutoExpo->isChecked();

        // 2. 初始化索引
        currentLedIndex = 0;

        if (!snapshotTimer) {
            snapshotTimer = new QTimer(this);
        }
        disconnect(snapshotTimer, &QTimer::timeout, nullptr, nullptr);
        connect(snapshotTimer, &QTimer::timeout, this, &MainWindow::processNextScheduledStep);

        // 延迟一小会儿执行第一步，给相机切换模式留时间
        QTimer::singleShot(200, this, &MainWindow::processNextScheduledStep);
    } else {
        snapshotTimer->stop();
        qDebug() << "定时扫描已停止";
    }
}



void MainWindow::on_toolButton_FilePath_clicked()
{
    QSettings settings("YourCompany", "YourApp");
    QString lastDir = settings.value("lastSaveDir", QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)).toString();
    QString dir = QFileDialog::getExistingDirectory(this, "选择保存文件夹", lastDir, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!dir.isEmpty()) {
        ui->lineEdit_FilePath->setText(dir); // 显示到 LineEdit 中
        settings.setValue("lastSaveDir", dir); // 保存新的目录
    }
}

void MainWindow::on_lineEdit_FilePath_textChanged(const QString &arg1)
{
    camera->setSaveDirectory(arg1);
}


void MainWindow::on_pushButton_Laser365_toggled(bool checked)
{
    fluorescence->sendFluorescenceCommand(checked,ui->pushButton_Laser488->isChecked(),ui->pushButton_Laser532->isChecked());

}


void MainWindow::on_pushButton_Laser488_toggled(bool checked)
{
    fluorescence->sendFluorescenceCommand(ui->pushButton_Laser365->isChecked(),checked,ui->pushButton_Laser532->isChecked());
}


void MainWindow::on_pushButton_Laser532_toggled(bool checked)
{
    fluorescence->sendFluorescenceCommand(ui->pushButton_Laser365->isChecked(),ui->pushButton_Laser488->isChecked(),checked);
}


void MainWindow::on_horizontalSlider_FliterSpeed_sliderReleased()
{
    ui->horizontalSlider_FliterSpeed->setValue(0);
}


void MainWindow::on_horizontalSlider_FliterSpeed_valueChanged(int value)
{
    int speed=abs(value);
    int frequency=speed>4 ? pow(1.14,((speed-5)/1.537)): 0;//int frequency=speed>4 ? pow(1.1,((speed-5)/1.53)): 0;
    //if (frequency>2500) frequency=2500;
    if (frequency) fluorescence->setDirection(value>0 ? 1 : 0);
    ui->lcdNumber_FliterFreq->display(frequency);
    fluorescence->setEnabled(ui->pushButton_MotorFliter_ENA->isChecked());
    //qDebug()<<frequency;
    fluorescence->setFrequency(frequency);
}


void MainWindow::on_pushButton_MotorFliter_ENA_toggled(bool checked)
{
    fluorescence->setEnabled(checked);
}




void MainWindow::on_comboBox_LedColorMode_currentIndexChanged(int index)
{
    QString hex = ui->comboBox_LedColorMode->currentData().toString();

    // 设置所有 LED 为统一颜色
    for (int i = 0; i < ringWidget->ledStates.size(); i++) {
        ringWidget->ledStates[i].color = hex;
    }

    ringWidget->refreshLed(); // 刷新 LED 环显示并发送串口
}

void MainWindow::processNextScheduledStep()
{
    int totalLeds = ringWidget->ledStates.size();

    if (currentLedIndex >= totalLeds) {
        ui->pushButton_SnapScheduled->setChecked(false);
        return;
    }

    // 停止主定时器，由内部的 singleShot 驱动下一步
    snapshotTimer->stop();

    // --- 步骤 1: 物理硬件切换 (灯光 & 参数) ---
    // 关灯
    for (int i = 0; i < totalLeds; ++i) ringWidget->ledStates[i].on = false;
    // 开当前的灯
    ringWidget->ledStates[currentLedIndex].on = true;
    ringWidget->refreshLed();

    // 设定对应的参数
    int targetExp = 0;
    int targetGain = 0;
    if (currentLedIndex < 7) {
        targetExp = ui->spinBox_ExposureTime_C->value();
        targetGain = ui->spinBox_ExpoGain_C->value();
    } else if (currentLedIndex < 19) {
        targetExp = ui->spinBox_ExposureTime_M->value();
        targetGain = ui->spinBox_ExpoGain_M->value();
    } else {
        targetExp = ui->spinBox_ExposureTime_O->value();
        targetGain = ui->spinBox_ExpoGain_O->value();
    }

    // 更新 UI（这会触发 valueChanged 发送指令给相机）
    ui->spinBox_ExposureTime->setValue(targetExp);
    ui->spinBox_ExpoGain->setValue(targetGain);

    // 强制处理事件队列，确保串口数据和 UI 刷新立即执行
    QCoreApplication::processEvents();

    // --- 步骤 2: 等待硬件稳定后拍照 ---
    // 等待时间 = 3倍曝光时间 + 100ms 串口传输缓冲
    int waitTime = qMax(600, (targetExp * 3) + 100);

    QTimer::singleShot(waitTime, this, [=]() {
        if (!ui->pushButton_SnapScheduled->isChecked()) return;

        qDebug() << "正在拍摄第" << (currentLedIndex + 1) << "号灯";

        // 执行拍照 (此处会调用 snapImage 并 fetchStillImageTif)
        on_pushButton_Snap_clicked();

        // 索引递增
        currentLedIndex++;

        // 步骤 3: 拍照后给一点缓冲时间再处理下一个灯 (防止相机缓冲区溢出)
        QTimer::singleShot(200, this, [=](){
            if (ui->pushButton_SnapScheduled->isChecked()) {
                processNextScheduledStep(); // 递归调用处理下一个
            }
        });
    });
}


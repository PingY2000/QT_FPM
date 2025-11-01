// led_ring_widget.cpp
#include "led_ring_widget.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsProxyWidget>
#include <QVBoxLayout>
#include <QtMath>
#include <QColor>
#include <QString>
#include <QDebug>

LedRingWidget::LedRingWidget(QWidget *parent, SerialManager *manager)
    : QWidget(parent), serialManager(manager)
{
    auto *layout = new QVBoxLayout(this);
    auto *view = new QGraphicsView(this);
    view->setRenderHint(QPainter::Antialiasing);

    auto *scene = new QGraphicsScene(this);
    view->setScene(scene);
    layout->addWidget(view);

    QVector<int> counts = {1, 6, 12, 24};
    QVector<int> radii = {0, 56, 120, 200};


    int centerX = 250;
    int centerY = 250;


    QPen pen(Qt::cyan);
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(10); // 线宽

    for (int radius : radii) {
        scene->addEllipse(centerX - radius, centerY - radius,
                          radius * 2, radius * 2,
                          pen);
    }

    //int currentIndex = 0;
    for (int r = 0; r < counts.size(); ++r) {
        for (int i = 0; i < counts[r]; ++i) {
            double angle = (360.0 / counts[r]) * i;
            if (r>1) angle=180-angle;
            double rad = qDegreesToRadians(angle);
            double x = centerX + radii[r] * cos(rad);
            double y = centerY + radii[r] * sin(rad);

            QPushButton *button = new QPushButton(QString::number(ledButtons.size() + 1));
            button->setProperty("ledIndex", ledButtons.size());
            button->setFixedSize(30, 30);
            button->setStyleSheet("background-color: #000000; border-radius: 15px; border: 5px solid gray;color:  gray;");
            connect(button, &QPushButton::clicked, this, &LedRingWidget::handleLedButtonClicked);


            QGraphicsProxyWidget *proxy = scene->addWidget(button);
            proxy->setPos(x - 15, y - 15);

            ledButtons.append(button);
        }
    }


    int totalLeds = 1 + 6 + 12 + 24;
    ledStates.resize(totalLeds);

    // 初始化状态
    for (int i = 0; i < totalLeds; ++i) {
        ledStates[i].on = false;
        ledStates[i].color = "#ffffff"; // 默认白色
    }

}


void LedRingWidget::refreshLed()
{

    for (int i = 0; i < ledButtons.size(); ++i) {
        if (ledStates[i].on)
            ledButtons[i]->setStyleSheet(QString("background-color:%1; border-radius: 15px; border: 5px solid gray;color: gray;").arg(ledStates[i].color));
        else
            ledButtons[i]->setStyleSheet("background-color:#000000; border-radius: 15px; border: 5px solid gray;color: gray;");
    }
    QByteArray data;
    data.append(0xA5);  // HEADER
    data.append(0x5A);
    data.append(0x01);
    data.append(0x06);
    for (int i = 0; i < 6; i++){
        quint8 result = 0;
        if (i)
            for (int j = 0; j < qMin(8, ledStates.size()-i*8); ++j) {
                if (ledStates[i*8+j].on) {
                    result |= (1 << j);
                }
            }
        else{
            for (int j = 0; j < 7; ++j) {
                if (ledStates[(j+1)%7].on) {
                    result |= (1 << j);
                }
            }
            if (ledStates[7].on) result |= (1 << 7);
        }

        data.append(result);
    }

    if (serialManager && serialManager->isOpen()) {
        serialManager->sendDatawithCRC(data);
    }


}

void LedRingWidget::handleLedButtonClicked() {
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    if (!senderButton) return;

    int index = senderButton->property("ledIndex").toInt();  // 获取索引

    // 切换状态示例：开启->关闭->开启
    ledStates[index].on = !ledStates[index].on;
    refreshLed();

}

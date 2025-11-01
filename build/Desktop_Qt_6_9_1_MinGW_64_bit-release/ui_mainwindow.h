/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_All_Off;
    QPushButton *pushButton_All_On;
    QPushButton *pushButton_PortSwitch;
    QComboBox *comboBox_Port;
    QLabel *labeldisplay;
    QPushButton *pushButton_Snap;
    QPushButton *pushButton_AutoExpo;
    QSlider *verticalSlider_LensSpeed;
    QPushButton *pushButton_CameraSwitch;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLCDNumber *lcdNumber_LensFreq;
    QPushButton *pushButton_HoldOFF;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpinBox *spinBox_ExpoGain;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *spinBox_ExposureTime;
    QLabel *label_4;
    QPushButton *pushButton_SnapScheduled;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QSpinBox *spinBox_SnapScheduledTime;
    QLabel *label_5;
    QTextEdit *textEdit_SerialMonitor;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QWidget *layoutWidget6;
    QHBoxLayout *FilePathLayout;
    QLineEdit *lineEdit_FilePath;
    QToolButton *toolButton_FilePath;
    QPushButton *pushButton_Laser365;
    QPushButton *pushButton_Laser488;
    QPushButton *pushButton_Laser532;
    QLCDNumber *lcdNumber_FliterFreq;
    QLabel *label_14;
    QSlider *horizontalSlider_FliterSpeed;
    QPushButton *pushButton_MotorFliter_ENA;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1376, 834);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(50, 60, 511, 451));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(70, 600, 169, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_All_Off = new QPushButton(layoutWidget);
        pushButton_All_Off->setObjectName("pushButton_All_Off");

        horizontalLayout->addWidget(pushButton_All_Off);

        pushButton_All_On = new QPushButton(layoutWidget);
        pushButton_All_On->setObjectName("pushButton_All_On");

        horizontalLayout->addWidget(pushButton_All_On);

        pushButton_PortSwitch = new QPushButton(centralwidget);
        pushButton_PortSwitch->setObjectName("pushButton_PortSwitch");
        pushButton_PortSwitch->setGeometry(QRect(157, 560, 80, 24));
        pushButton_PortSwitch->setCheckable(true);
        comboBox_Port = new QComboBox(centralwidget);
        comboBox_Port->setObjectName("comboBox_Port");
        comboBox_Port->setGeometry(QRect(70, 560, 72, 24));
        labeldisplay = new QLabel(centralwidget);
        labeldisplay->setObjectName("labeldisplay");
        labeldisplay->setGeometry(QRect(640, 40, 683, 512));
        labeldisplay->setStyleSheet(QString::fromUtf8("border: 3px solid gray;color:black"));
        labeldisplay->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton_Snap = new QPushButton(centralwidget);
        pushButton_Snap->setObjectName("pushButton_Snap");
        pushButton_Snap->setGeometry(QRect(1100, 610, 92, 28));
        pushButton_AutoExpo = new QPushButton(centralwidget);
        pushButton_AutoExpo->setObjectName("pushButton_AutoExpo");
        pushButton_AutoExpo->setGeometry(QRect(1010, 640, 80, 28));
        pushButton_AutoExpo->setCheckable(true);
        verticalSlider_LensSpeed = new QSlider(centralwidget);
        verticalSlider_LensSpeed->setObjectName("verticalSlider_LensSpeed");
        verticalSlider_LensSpeed->setGeometry(QRect(360, 560, 51, 211));
        verticalSlider_LensSpeed->setStyleSheet(QString::fromUtf8("QSlider::handle:vertical {\n"
"    background: white;\n"
"    border: 1px solid gray;\n"
"    height: 10px;              /* \345\212\240\345\256\275\346\273\221\345\235\227\351\253\230\345\272\246 */\n"
"    width: 16px;               /* \345\212\240\345\256\275\346\273\221\345\235\227\345\256\275\345\272\246 */\n"
"    margin: 0 -11px;           /* \346\260\264\345\271\263\345\261\205\344\270\255\357\274\214(30-8)/2=11 */\n"
"    border-radius: 3px;       /* \345\234\206\345\275\242\346\273\221\345\235\227 */\n"
"}\n"
"\n"
"/* \345\217\226\346\266\210\350\277\233\345\272\246\346\235\241\345\241\253\345\205\205 */\n"
"QSlider::sub-page:vertical,\n"
"QSlider::add-page:vertical {\n"
"    background: transparent;\n"
"    border: none;\n"
"}\n"
""));
        verticalSlider_LensSpeed->setMinimum(-105);
        verticalSlider_LensSpeed->setMaximum(105);
        verticalSlider_LensSpeed->setOrientation(Qt::Orientation::Vertical);
        verticalSlider_LensSpeed->setTickPosition(QSlider::TickPosition::TicksBothSides);
        pushButton_CameraSwitch = new QPushButton(centralwidget);
        pushButton_CameraSwitch->setObjectName("pushButton_CameraSwitch");
        pushButton_CameraSwitch->setGeometry(QRect(1210, 610, 92, 28));
        pushButton_CameraSwitch->setCheckable(true);
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(250, 650, 82, 113));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setSpacing(36);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(layoutWidget1);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        verticalLayout_2->addWidget(label);

        lcdNumber_LensFreq = new QLCDNumber(layoutWidget1);
        lcdNumber_LensFreq->setObjectName("lcdNumber_LensFreq");
        lcdNumber_LensFreq->setDigitCount(4);

        verticalLayout_2->addWidget(lcdNumber_LensFreq);


        verticalLayout_3->addLayout(verticalLayout_2);

        pushButton_HoldOFF = new QPushButton(layoutWidget1);
        pushButton_HoldOFF->setObjectName("pushButton_HoldOFF");
        pushButton_HoldOFF->setCheckable(true);

        verticalLayout_3->addWidget(pushButton_HoldOFF);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(860, 640, 131, 30));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setSpacing(8);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        spinBox_ExpoGain = new QSpinBox(layoutWidget2);
        spinBox_ExpoGain->setObjectName("spinBox_ExpoGain");
        spinBox_ExpoGain->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        spinBox_ExpoGain->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBox_ExpoGain->setMinimum(100);
        spinBox_ExpoGain->setMaximum(500);
        spinBox_ExpoGain->setSingleStep(20);

        horizontalLayout_2->addWidget(spinBox_ExpoGain);

        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(860, 600, 175, 32));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName("label_2");

        horizontalLayout_4->addWidget(label_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        spinBox_ExposureTime = new QSpinBox(layoutWidget3);
        spinBox_ExposureTime->setObjectName("spinBox_ExposureTime");
        spinBox_ExposureTime->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        spinBox_ExposureTime->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBox_ExposureTime->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::UpDownArrows);
        spinBox_ExposureTime->setMinimum(50);
        spinBox_ExposureTime->setMaximum(15000);
        spinBox_ExposureTime->setSingleStep(50);
        spinBox_ExposureTime->setValue(200);

        horizontalLayout_3->addWidget(spinBox_ExposureTime);

        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        pushButton_SnapScheduled = new QPushButton(centralwidget);
        pushButton_SnapScheduled->setObjectName("pushButton_SnapScheduled");
        pushButton_SnapScheduled->setGeometry(QRect(1110, 670, 80, 24));
        pushButton_SnapScheduled->setCheckable(true);
        layoutWidget4 = new QWidget(centralwidget);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(1220, 670, 81, 30));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        spinBox_SnapScheduledTime = new QSpinBox(layoutWidget4);
        spinBox_SnapScheduledTime->setObjectName("spinBox_SnapScheduledTime");
        spinBox_SnapScheduledTime->setMinimum(1);
        spinBox_SnapScheduledTime->setMaximum(200);

        horizontalLayout_5->addWidget(spinBox_SnapScheduledTime);

        label_5 = new QLabel(layoutWidget4);
        label_5->setObjectName("label_5");

        horizontalLayout_5->addWidget(label_5);

        textEdit_SerialMonitor = new QTextEdit(centralwidget);
        textEdit_SerialMonitor->setObjectName("textEdit_SerialMonitor");
        textEdit_SerialMonitor->setGeometry(QRect(70, 660, 141, 91));
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(420, 680, 38, 90));
        verticalLayout_5 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_5->setSpacing(4);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget_2);
        label_10->setObjectName("label_10");
        label_10->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_5->addWidget(label_10);

        label_11 = new QLabel(layoutWidget_2);
        label_11->setObjectName("label_11");
        label_11->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_5->addWidget(label_11);

        label_12 = new QLabel(layoutWidget_2);
        label_12->setObjectName("label_12");
        label_12->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_5->addWidget(label_12);

        label_13 = new QLabel(layoutWidget_2);
        label_13->setObjectName("label_13");
        label_13->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_5->addWidget(label_13);

        layoutWidget5 = new QWidget(centralwidget);
        layoutWidget5->setObjectName("layoutWidget5");
        layoutWidget5->setGeometry(QRect(420, 560, 38, 90));
        verticalLayout_4 = new QVBoxLayout(layoutWidget5);
        verticalLayout_4->setSpacing(4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget5);
        label_6->setObjectName("label_6");
        label_6->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_4->addWidget(label_6);

        label_7 = new QLabel(layoutWidget5);
        label_7->setObjectName("label_7");
        label_7->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_4->addWidget(label_7);

        label_8 = new QLabel(layoutWidget5);
        label_8->setObjectName("label_8");
        label_8->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_4->addWidget(label_8);

        label_9 = new QLabel(layoutWidget5);
        label_9->setObjectName("label_9");
        label_9->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_4->addWidget(label_9);

        layoutWidget6 = new QWidget(centralwidget);
        layoutWidget6->setObjectName("layoutWidget6");
        layoutWidget6->setGeometry(QRect(1030, 720, 271, 29));
        FilePathLayout = new QHBoxLayout(layoutWidget6);
        FilePathLayout->setSpacing(0);
        FilePathLayout->setObjectName("FilePathLayout");
        FilePathLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_FilePath = new QLineEdit(layoutWidget6);
        lineEdit_FilePath->setObjectName("lineEdit_FilePath");
        lineEdit_FilePath->setReadOnly(true);

        FilePathLayout->addWidget(lineEdit_FilePath);

        toolButton_FilePath = new QToolButton(layoutWidget6);
        toolButton_FilePath->setObjectName("toolButton_FilePath");

        FilePathLayout->addWidget(toolButton_FilePath);

        pushButton_Laser365 = new QPushButton(centralwidget);
        pushButton_Laser365->setObjectName("pushButton_Laser365");
        pushButton_Laser365->setGeometry(QRect(540, 580, 61, 31));
        pushButton_Laser365->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"        background-color: gray;\n"
"	    border: 2px solid black;\n"
"        border-radius: 5px;\n"
"        padding: 5px;\n"
"    }\n"
"QPushButton:checked {\n"
"        background-color: rgb(102, 26, 255); \n"
"    }"));
        pushButton_Laser365->setCheckable(true);
        pushButton_Laser488 = new QPushButton(centralwidget);
        pushButton_Laser488->setObjectName("pushButton_Laser488");
        pushButton_Laser488->setGeometry(QRect(610, 580, 61, 31));
        pushButton_Laser488->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"        background-color: gray;\n"
"		border: 2px solid black;\n"
"        border-radius: 5px;\n"
"        padding: 5px;\n"
"    }\n"
"QPushButton:checked {\n"
"        background-color: rgb(144, 188, 255); \n"
"    }"));
        pushButton_Laser488->setCheckable(true);
        pushButton_Laser532 = new QPushButton(centralwidget);
        pushButton_Laser532->setObjectName("pushButton_Laser532");
        pushButton_Laser532->setGeometry(QRect(680, 580, 61, 31));
        pushButton_Laser532->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"        background-color: gray;\n"
"		border: 2px solid black;\n"
"        border-radius: 5px;\n"
"        padding: 5px;\n"
"    }\n"
"QPushButton:checked {\n"
"        background-color: rgb(139, 255, 44); \n"
"    }"));
        pushButton_Laser532->setCheckable(true);
        lcdNumber_FliterFreq = new QLCDNumber(centralwidget);
        lcdNumber_FliterFreq->setObjectName("lcdNumber_FliterFreq");
        lcdNumber_FliterFreq->setGeometry(QRect(640, 662, 81, 31));
        lcdNumber_FliterFreq->setDigitCount(4);
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(640, 640, 78, 19));
        label_14->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);
        horizontalSlider_FliterSpeed = new QSlider(centralwidget);
        horizontalSlider_FliterSpeed->setObjectName("horizontalSlider_FliterSpeed");
        horizontalSlider_FliterSpeed->setGeometry(QRect(530, 710, 311, 41));
        horizontalSlider_FliterSpeed->setStyleSheet(QString::fromUtf8("QSlider::handle:horizontal {\n"
"    background: white;\n"
"    border: 1px solid gray;\n"
"    height: 16px;              /* \345\212\240\345\256\275\346\273\221\345\235\227\351\253\230\345\272\246 */\n"
"    width: 10px;               /* \345\212\240\345\256\275\346\273\221\345\235\227\345\256\275\345\272\246 */\n"
"    margin: 0 -11px;           /* \346\260\264\345\271\263\345\261\205\344\270\255\357\274\214(30-8)/2=11 */\n"
"    border-radius: 3px;       /* \345\234\206\345\275\242\346\273\221\345\235\227 */\n"
"}\n"
"\n"
"/* \345\217\226\346\266\210\350\277\233\345\272\246\346\235\241\345\241\253\345\205\205 */\n"
"QSlider::sub-page:vertical,\n"
"QSlider::add-page:vertical {\n"
"    background: transparent;\n"
"    border: none;\n"
"}"));
        horizontalSlider_FliterSpeed->setMinimum(-105);
        horizontalSlider_FliterSpeed->setMaximum(105);
        horizontalSlider_FliterSpeed->setOrientation(Qt::Orientation::Horizontal);
        horizontalSlider_FliterSpeed->setInvertedAppearance(false);
        horizontalSlider_FliterSpeed->setInvertedControls(false);
        horizontalSlider_FliterSpeed->setTickPosition(QSlider::TickPosition::TicksBothSides);
        pushButton_MotorFliter_ENA = new QPushButton(centralwidget);
        pushButton_MotorFliter_ENA->setObjectName("pushButton_MotorFliter_ENA");
        pushButton_MotorFliter_ENA->setGeometry(QRect(540, 660, 80, 28));
        pushButton_MotorFliter_ENA->setCheckable(true);
        pushButton_MotorFliter_ENA->setChecked(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1376, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_All_Off->setText(QCoreApplication::translate("MainWindow", "\345\205\250\347\201\255", nullptr));
        pushButton_All_On->setText(QCoreApplication::translate("MainWindow", "\345\205\250\344\272\256", nullptr));
        pushButton_PortSwitch->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        labeldisplay->setText(QCoreApplication::translate("MainWindow", "Dispaly", nullptr));
        pushButton_Snap->setText(QCoreApplication::translate("MainWindow", "\345\277\253\347\205\247", nullptr));
        pushButton_AutoExpo->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\346\233\235\345\205\211", nullptr));
        pushButton_CameraSwitch->setText(QCoreApplication::translate("MainWindow", "\347\233\270\346\234\272\345\274\200\345\205\263", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\351\242\221\347\216\207", nullptr));
        pushButton_HoldOFF->setText(QCoreApplication::translate("MainWindow", "\350\247\243\351\231\244", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\233\235\345\205\211\345\242\236\347\233\212", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\233\235\345\205\211\346\227\266\351\227\264", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "ms", nullptr));
        pushButton_SnapScheduled->setText(QCoreApplication::translate("MainWindow", "\345\256\232\346\227\266\346\213\215\347\205\247", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "s", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "40", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "300", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "2500", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "2500", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "300", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "40", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        toolButton_FilePath->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        pushButton_Laser365->setText(QCoreApplication::translate("MainWindow", "365nm", nullptr));
        pushButton_Laser488->setText(QCoreApplication::translate("MainWindow", "488nm", nullptr));
        pushButton_Laser532->setText(QCoreApplication::translate("MainWindow", "532nm", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\351\242\221\347\216\207", nullptr));
        pushButton_MotorFliter_ENA->setText(QCoreApplication::translate("MainWindow", "\344\275\277\350\203\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

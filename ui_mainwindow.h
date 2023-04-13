/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_activity;
    QPushButton *play_pushButton_2;
    QPushButton *pushButton_2;
    QSpinBox *min_frame_spinBox;
    QSlider *actual_framehorizontalSlider;
    QSpinBox *max_frame_spinBox_2;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLCDNumber *lcd_PointNum;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QSpinBox *actual_frame_spinBox;
    QLabel *label_4;
    QLabel *label_2;
    QGraphicsView *graphicsView;
    QWidget *tab_2;
    QListWidget *datFiles_listWidget;
    QCheckBox *checkBox;
    QListWidget *csvFiles_listWidget;
    QLabel *typeofLW_Label;
    QLabel *notification;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(798, 497);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(600, 400));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 801, 601));
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayoutWidget = new QWidget(tab);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 741, 60));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(9);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(pushButton);

        pushButton_activity = new QPushButton(verticalLayoutWidget);
        pushButton_activity->setObjectName("pushButton_activity");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_activity->sizePolicy().hasHeightForWidth());
        pushButton_activity->setSizePolicy(sizePolicy1);
        pushButton_activity->setMaximumSize(QSize(40, 20));
        pushButton_activity->setFlat(false);

        horizontalLayout->addWidget(pushButton_activity);

        play_pushButton_2 = new QPushButton(verticalLayoutWidget);
        play_pushButton_2->setObjectName("play_pushButton_2");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(play_pushButton_2->sizePolicy().hasHeightForWidth());
        play_pushButton_2->setSizePolicy(sizePolicy2);
        play_pushButton_2->setMaximumSize(QSize(60, 20));

        horizontalLayout->addWidget(play_pushButton_2);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMaximumSize(QSize(40, 20));

        horizontalLayout->addWidget(pushButton_2);

        min_frame_spinBox = new QSpinBox(verticalLayoutWidget);
        min_frame_spinBox->setObjectName("min_frame_spinBox");
        min_frame_spinBox->setMaximumSize(QSize(16777215, 20));
        min_frame_spinBox->setMaximum(10000);

        horizontalLayout->addWidget(min_frame_spinBox);

        actual_framehorizontalSlider = new QSlider(verticalLayoutWidget);
        actual_framehorizontalSlider->setObjectName("actual_framehorizontalSlider");
        actual_framehorizontalSlider->setMaximumSize(QSize(16777215, 20));
        actual_framehorizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(actual_framehorizontalSlider);

        max_frame_spinBox_2 = new QSpinBox(verticalLayoutWidget);
        max_frame_spinBox_2->setObjectName("max_frame_spinBox_2");
        max_frame_spinBox_2->setMaximumSize(QSize(16777215, 20));
        max_frame_spinBox_2->setMaximum(10000);

        horizontalLayout->addWidget(max_frame_spinBox_2);

        doubleSpinBox = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setMaximum(2.000000000000000);
        doubleSpinBox->setSingleStep(0.100000000000000);
        doubleSpinBox->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        horizontalLayout->addWidget(doubleSpinBox);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 20));

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName("label_6");
        label_6->setMaximumSize(QSize(50, 20));

        horizontalLayout_2->addWidget(label_6);

        lcd_PointNum = new QLCDNumber(verticalLayoutWidget);
        lcd_PointNum->setObjectName("lcd_PointNum");
        lcd_PointNum->setMaximumSize(QSize(50, 20));
        lcd_PointNum->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_2->addWidget(lcd_PointNum);

        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(70, 20));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_3);

        actual_frame_spinBox = new QSpinBox(verticalLayoutWidget);
        actual_frame_spinBox->setObjectName("actual_frame_spinBox");
        actual_frame_spinBox->setMaximumSize(QSize(50, 20));
        actual_frame_spinBox->setMaximum(99999);

        horizontalLayout_2->addWidget(actual_frame_spinBox);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(100, 20));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_4);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(80, 20));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_2);

        graphicsView = new QGraphicsView(tab);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(10, 70, 741, 331));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy3);
        graphicsView->setMouseTracking(true);
        graphicsView->setFocusPolicy(Qt::ClickFocus);
        graphicsView->setLayoutDirection(Qt::LeftToRight);
        graphicsView->setAutoFillBackground(false);
        graphicsView->setFrameShape(QFrame::Box);
        graphicsView->setFrameShadow(QFrame::Plain);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        graphicsView->setAlignment(Qt::AlignCenter);
        graphicsView->setTransformationAnchor(QGraphicsView::NoAnchor);
        graphicsView->setResizeAnchor(QGraphicsView::NoAnchor);
        graphicsView->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        datFiles_listWidget = new QListWidget(tab_2);
        datFiles_listWidget->setObjectName("datFiles_listWidget");
        datFiles_listWidget->setGeometry(QRect(10, 60, 391, 231));
        checkBox = new QCheckBox(tab_2);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(10, 0, 171, 24));
        csvFiles_listWidget = new QListWidget(tab_2);
        csvFiles_listWidget->setObjectName("csvFiles_listWidget");
        csvFiles_listWidget->setGeometry(QRect(10, 60, 391, 231));
        typeofLW_Label = new QLabel(tab_2);
        typeofLW_Label->setObjectName("typeofLW_Label");
        typeofLW_Label->setGeometry(QRect(12, 30, 241, 20));
        typeofLW_Label->setAlignment(Qt::AlignCenter);
        notification = new QLabel(tab_2);
        notification->setObjectName("notification");
        notification->setGeometry(QRect(440, 70, 241, 131));
        QFont font;
        font.setPointSize(12);
        notification->setFont(font);
        notification->setLineWidth(1);
        notification->setScaledContents(false);
        notification->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        notification->setWordWrap(true);
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 798, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        pushButton_activity->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        play_pushButton_2->setText(QCoreApplication::translate("MainWindow", "tst", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "||", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Pos multiplier", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "NumPoints:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "actual Value", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Max Value", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "val*pos{X.,Y}", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Vizual.", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "RAW dat/ old parsed dat", nullptr));
        typeofLW_Label->setText(QCoreApplication::translate("MainWindow", "Parsed csv data", nullptr));
        notification->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "DatOp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

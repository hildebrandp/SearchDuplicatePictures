/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *lineEdit_Directory;
    QPushButton *pushButton_Sel_Folder;
    QCheckBox *checkBox_Include_SubDir;
    QFrame *line;
    QLabel *label_2;
    QLabel *label_SubDir_Found;
    QLabel *label_4;
    QLabel *label_Pic_Found;
    QCheckBox *checkBox_Compare_SubDir;
    QPushButton *pushButton_Start;
    QFrame *line_2;
    QLabel *picture_1;
    QLabel *picture_2;
    QLabel *picture_3;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_Dimension_Pic_1;
    QLabel *label_Dimension_Pic_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_Size_Pic_1;
    QLabel *label_Size_Pic_2;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_Name_Pic_1;
    QLabel *label_Name_Pic_2;
    QPushButton *pushButton_Keep_Both;
    QPushButton *pushButton_Keep_Left;
    QPushButton *pushButton_Keep_Right;
    QLabel *label_10;
    QLabel *label_Image_Match;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 750);
        MainWindow->setMinimumSize(QSize(1200, 750));
        MainWindow->setMaximumSize(QSize(1200, 750));
        QFont font;
        font.setPointSize(14);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 280, 30));
        label->setFont(font);
        lineEdit_Directory = new QLineEdit(centralwidget);
        lineEdit_Directory->setObjectName(QString::fromUtf8("lineEdit_Directory"));
        lineEdit_Directory->setGeometry(QRect(300, 20, 560, 30));
        pushButton_Sel_Folder = new QPushButton(centralwidget);
        pushButton_Sel_Folder->setObjectName(QString::fromUtf8("pushButton_Sel_Folder"));
        pushButton_Sel_Folder->setGeometry(QRect(885, 20, 50, 30));
        checkBox_Include_SubDir = new QCheckBox(centralwidget);
        checkBox_Include_SubDir->setObjectName(QString::fromUtf8("checkBox_Include_SubDir"));
        checkBox_Include_SubDir->setGeometry(QRect(20, 70, 280, 30));
        checkBox_Include_SubDir->setLayoutDirection(Qt::LeftToRight);
        checkBox_Include_SubDir->setCheckable(true);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(20, 150, 1160, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 110, 280, 30));
        label_2->setFont(font);
        label_SubDir_Found = new QLabel(centralwidget);
        label_SubDir_Found->setObjectName(QString::fromUtf8("label_SubDir_Found"));
        label_SubDir_Found->setGeometry(QRect(300, 110, 75, 30));
        label_SubDir_Found->setFont(font);
        label_SubDir_Found->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(400, 110, 280, 30));
        label_4->setFont(font);
        label_Pic_Found = new QLabel(centralwidget);
        label_Pic_Found->setObjectName(QString::fromUtf8("label_Pic_Found"));
        label_Pic_Found->setGeometry(QRect(680, 110, 75, 30));
        label_Pic_Found->setFont(font);
        label_Pic_Found->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_Compare_SubDir = new QCheckBox(centralwidget);
        checkBox_Compare_SubDir->setObjectName(QString::fromUtf8("checkBox_Compare_SubDir"));
        checkBox_Compare_SubDir->setGeometry(QRect(300, 70, 280, 30));
        pushButton_Start = new QPushButton(centralwidget);
        pushButton_Start->setObjectName(QString::fromUtf8("pushButton_Start"));
        pushButton_Start->setEnabled(false);
        pushButton_Start->setGeometry(QRect(960, 20, 220, 120));
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(20, 60, 915, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        picture_1 = new QLabel(centralwidget);
        picture_1->setObjectName(QString::fromUtf8("picture_1"));
        picture_1->setGeometry(QRect(20, 170, 300, 300));
        picture_1->setFrameShape(QFrame::Box);
        picture_1->setLineWidth(1);
        picture_2 = new QLabel(centralwidget);
        picture_2->setObjectName(QString::fromUtf8("picture_2"));
        picture_2->setGeometry(QRect(880, 170, 300, 300));
        picture_2->setFrameShape(QFrame::Box);
        picture_2->setLineWidth(1);
        picture_3 = new QLabel(centralwidget);
        picture_3->setObjectName(QString::fromUtf8("picture_3"));
        picture_3->setGeometry(QRect(440, 330, 300, 300));
        picture_3->setFrameShape(QFrame::Box);
        picture_3->setLineWidth(1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 560, 300, 30));
        label_3->setFont(font);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(880, 560, 300, 30));
        label_5->setFont(font);
        label_Dimension_Pic_1 = new QLabel(centralwidget);
        label_Dimension_Pic_1->setObjectName(QString::fromUtf8("label_Dimension_Pic_1"));
        label_Dimension_Pic_1->setGeometry(QRect(20, 590, 300, 30));
        label_Dimension_Pic_1->setFont(font);
        label_Dimension_Pic_1->setAlignment(Qt::AlignCenter);
        label_Dimension_Pic_2 = new QLabel(centralwidget);
        label_Dimension_Pic_2->setObjectName(QString::fromUtf8("label_Dimension_Pic_2"));
        label_Dimension_Pic_2->setGeometry(QRect(880, 600, 300, 30));
        label_Dimension_Pic_2->setFont(font);
        label_Dimension_Pic_2->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 640, 300, 30));
        label_6->setFont(font);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(880, 640, 300, 30));
        label_7->setFont(font);
        label_Size_Pic_1 = new QLabel(centralwidget);
        label_Size_Pic_1->setObjectName(QString::fromUtf8("label_Size_Pic_1"));
        label_Size_Pic_1->setGeometry(QRect(20, 680, 300, 30));
        label_Size_Pic_1->setFont(font);
        label_Size_Pic_1->setAlignment(Qt::AlignCenter);
        label_Size_Pic_2 = new QLabel(centralwidget);
        label_Size_Pic_2->setObjectName(QString::fromUtf8("label_Size_Pic_2"));
        label_Size_Pic_2->setGeometry(QRect(880, 680, 300, 30));
        label_Size_Pic_2->setFont(font);
        label_Size_Pic_2->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 480, 300, 30));
        label_8->setFont(font);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(880, 480, 300, 30));
        label_9->setFont(font);
        label_Name_Pic_1 = new QLabel(centralwidget);
        label_Name_Pic_1->setObjectName(QString::fromUtf8("label_Name_Pic_1"));
        label_Name_Pic_1->setGeometry(QRect(20, 520, 300, 30));
        label_Name_Pic_1->setFont(font);
        label_Name_Pic_1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_Name_Pic_2 = new QLabel(centralwidget);
        label_Name_Pic_2->setObjectName(QString::fromUtf8("label_Name_Pic_2"));
        label_Name_Pic_2->setGeometry(QRect(880, 520, 300, 30));
        label_Name_Pic_2->setFont(font);
        label_Name_Pic_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pushButton_Keep_Both = new QPushButton(centralwidget);
        pushButton_Keep_Both->setObjectName(QString::fromUtf8("pushButton_Keep_Both"));
        pushButton_Keep_Both->setGeometry(QRect(440, 250, 300, 30));
        pushButton_Keep_Left = new QPushButton(centralwidget);
        pushButton_Keep_Left->setObjectName(QString::fromUtf8("pushButton_Keep_Left"));
        pushButton_Keep_Left->setGeometry(QRect(440, 170, 300, 30));
        pushButton_Keep_Right = new QPushButton(centralwidget);
        pushButton_Keep_Right->setObjectName(QString::fromUtf8("pushButton_Keep_Right"));
        pushButton_Keep_Right->setGeometry(QRect(440, 210, 300, 30));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(440, 290, 150, 30));
        label_10->setFont(font);
        label_Image_Match = new QLabel(centralwidget);
        label_Image_Match->setObjectName(QString::fromUtf8("label_Image_Match"));
        label_Image_Match->setGeometry(QRect(590, 290, 150, 30));
        label_Image_Match->setFont(font);
        label_Image_Match->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 31));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Select Directory:", nullptr));
        pushButton_Sel_Folder->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        checkBox_Include_SubDir->setText(QCoreApplication::translate("MainWindow", "Include Subdirectries", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Subdirectories found:", nullptr));
        label_SubDir_Found->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Pictures found:", nullptr));
        label_Pic_Found->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        checkBox_Compare_SubDir->setText(QCoreApplication::translate("MainWindow", "Compare All Pictures", nullptr));
        pushButton_Start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        picture_1->setText(QString());
        picture_2->setText(QString());
        picture_3->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Dimensions:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Dimensions:", nullptr));
        label_Dimension_Pic_1->setText(QCoreApplication::translate("MainWindow", "0 x 0", nullptr));
        label_Dimension_Pic_2->setText(QCoreApplication::translate("MainWindow", "0 x 0", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Size:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Size:", nullptr));
        label_Size_Pic_1->setText(QCoreApplication::translate("MainWindow", "0 MB", nullptr));
        label_Size_Pic_2->setText(QCoreApplication::translate("MainWindow", "0 MB", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        label_Name_Pic_1->setText(QCoreApplication::translate("MainWindow", "foo.jpg", nullptr));
        label_Name_Pic_2->setText(QCoreApplication::translate("MainWindow", "bar.jpg", nullptr));
        pushButton_Keep_Both->setText(QCoreApplication::translate("MainWindow", "<- Keep Both ->", nullptr));
        pushButton_Keep_Left->setText(QCoreApplication::translate("MainWindow", "<- Keep Left Picture", nullptr));
        pushButton_Keep_Right->setText(QCoreApplication::translate("MainWindow", "Keep Right Picture ->", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Match:", nullptr));
        label_Image_Match->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

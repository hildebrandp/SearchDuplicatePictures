#include <iostream>
#include <stdlib.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
#include <chrono>
#include <cmath>

#include <opencv4/opencv2/opencv.hpp>

#include <QFileDialog>
#include <QTreeView>
#include <QtGui/QPainter>
#include <QtGui/QPicture>
#include <QElapsedTimer>

#include "ui_mainwindow.h"
#include "./mainwindow.h"
#include "pictureTypes.h"
#include "fileHelper.h"
#include "imageProccessingHelper.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    std::cout.setf(std::ios::boolalpha);

    ui->setupUi(this);

    const QString windowTitle = application_Name + " - Version: " + application_Version;
    setWindowTitle(windowTitle);

    cout << "Startet -> " << windowTitle.toStdString() << endl;

    // Connect UI Buttons
    connect(ui->pushButton_Sel_Folder,      SIGNAL(clicked()), this, SLOT(on_Select_Directory_clicked()));
    connect(ui->pushButton_Start,           SIGNAL(clicked()), this, SLOT(on_Start_clicked()));
    connect(ui->pushButton_Keep_Both,       SIGNAL(clicked()), this, SLOT(on_Keep_Both_clicked()));

    // Connect UI Edit-Texts
    connect(ui->lineEdit_Directory,         SIGNAL(textChanged(QString)), this, SLOT(on_Directory_textChanged(QString)));

    // Connect UI Check-Boxes
    connect(ui->checkBox_Include_SubDir,    SIGNAL(clicked(bool)), this, SLOT(on_Include_SubDir_stateChanged(bool)));
    connect(ui->checkBox_Compare_SubDir,    SIGNAL(clicked(bool)), this, SLOT(on_Compare_SubDir_stateChanged(bool)));

    ui->picture_1->setScaledContents( true );
    ui->picture_1->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    ui->picture_2->setScaledContents( true );
    ui->picture_2->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    // Set a border for the QLabel using style sheet
    ui->picture_1->setStyleSheet("border: 2px solid black; padding: 5px;");
    ui->picture_2->setStyleSheet("border: 2px solid black; padding: 5px;");

    set_Select_Button_State(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Select_Directory_clicked()
{
    cout << "Clicked() -> on_Select_Directory_clicked()" << endl;

    QFileDialog *fd = new QFileDialog;
    QTreeView *tree = fd->findChild <QTreeView*>();
    if (tree)
    {
        tree->setRootIsDecorated(true);
        tree->setItemsExpandable(true);
    }
    fd->setFileMode(QFileDialog::Directory);
    fd->setOption(QFileDialog::ShowDirsOnly);
    fd->setViewMode(QFileDialog::Detail);

    cout << "path -> bla" << endl;
    const auto path = ui->lineEdit_Directory->text();
    if (path != "")
    {
        fd->setDirectory(path);
    }
    else
    {
        fd->setDirectory(QDir::home());
    }

    int result = fd->exec();
    QString directory;
    if (result)
    {
        directory = fd->selectedFiles()[0];
        ui->lineEdit_Directory->setText(directory);
    }
}

void MainWindow::on_Start_clicked()
{
    if (startButtonIsStart)
    {
        cout << "on_Start_clicked(): Start generating image data" << endl;
        ui->pushButton_Start->setText(startButtonTextStop);
        startButtonIsStart = false;
        stopPictureCompare = false;

        qApp->processEvents();

        pictureListIterator_1 = pictureList.begin();
        pictureListIterator_2 = pictureListIterator_1 + 1;

        // Generate Image Data for first Picture
        picture_1_Data = generate_SIFT_Data_For_Picture(*pictureListIterator_1);

        // Start Picture compare
        compare_Pictures();
    }
    else
    {
        cout << "on_Start_clicked(): Stop comparing images" << endl;
        ui->pushButton_Start->setText(startButtonTextStart);
        startButtonIsStart = true;
        stopPictureCompare = true;
    }
}

void MainWindow::on_Directory_textChanged(const QString& lineEditText)
{
    cout << "textChanged(QString) -> on_Directory_Text_Changed(" << lineEditText.toStdString() << ")" << endl;
    ui->pushButton_Start->setEnabled(false);

    if (timeout_thread_running)
    {
        cout << "on_Directory_textChanged() -> Thread canceled" << endl;
        pthread_cancel(timeout_thread_id);
        timeout_thread_running = false;
    }

    if (QDir(lineEditText).exists())
    {
        ui->lineEdit_Directory->setStyleSheet("color: green;");

        // Path is valid so check file count
        pthread_create(&timeout_thread_id, NULL, timeout, this);
        cout << "on_Directory_textChanged() -> Thread started" << endl;
    }
    else
    {
        ui->lineEdit_Directory->setStyleSheet("color: red;");
    }
}

void MainWindow::on_Include_SubDir_stateChanged(const bool& checked)
{
    cout << "stateChanged(int) -> on_Include_SubDir_State_Changed(" << checked << ")" << endl;

    if (timeout_thread_running)
    {
        cout << "on_Directory_textChanged() -> Thread canceled" << endl;
        pthread_cancel(timeout_thread_id);
        timeout_thread_running = false;
    }

    const QString folderPath = ui->lineEdit_Directory->text();
    if (folderPath != "" && QDir(folderPath).exists())
    {
        // Path is valid so check file count
        pthread_create(&timeout_thread_id, NULL, timeout, this);
        cout << "on_Directory_textChanged() -> Thread started" << endl;
    }
}

void MainWindow::on_Compare_SubDir_stateChanged(const bool& checked)
{
    cout << "stateChanged(int) -> on_Compare_SubDir_State_Changed(" << checked << ")" << endl;
}

void MainWindow::check_Folder()
{
    cout << "check_File_Count() -> Counting files..." << endl;
    const QString folderPath = ui->lineEdit_Directory->text();
    const bool includeSubdirectories = ui->checkBox_Include_SubDir->isChecked();

    QDir folderDir(folderPath);

    // Check once again if the folder exists
    if (!folderDir.exists()) return;

    pictureList.clear();
    FileCount fileCount = check_File_Count(folderDir, includeSubdirectories, pictureList);

    ui->label_Pic_Found->setText(QString::number(fileCount.fileCount));
    ui->label_SubDir_Found->setText(QString::number(fileCount.subDirectoriesCount));
    // Only enable start button if more than 2 files found
    if (fileCount.fileCount >= 2) ui->pushButton_Start->setEnabled(true);
}

void MainWindow::compare_Pictures()
{
    cout << "compare_Pictures(): Start comparing images" << endl;

    for (; pictureListIterator_1 != pictureList.end();)
    {
        // Check if comparing should be stopped
        if (stopPictureCompare) return;

        const auto pic_1 = *pictureListIterator_1;
        QPicture conv_Pic_1 = convert_CvImage_To_QPicture(picture_1_Data.imageObj);
        ui->picture_1->setPicture(conv_Pic_1);
        ui->label_Name_Pic_1->setText(pic_1.fileName);
        ui->label_Dimension_Pic_1->setText(QString::number(picture_1_Data.image_Height) + "x" + QString::number(picture_1_Data.image_Width));
        ui->label_Size_Pic_1->setText(picture_1_Data.image_Size);

        for (; pictureListIterator_2 != pictureList.end();)
        {
            // Check if comparing should be stopped
            if (stopPictureCompare) return;

            const auto pic_2 = *pictureListIterator_2;
            PictureSFITData picture_2_Data = generate_SIFT_Data_For_Picture(*pictureListIterator_2);
            cout << "compare_Pictures() -> Compare [ " << pic_1.fileName.toStdString() << " ] against [ " << pic_2.fileName.toStdString() << " ]" << endl;

            QPicture conv_Pic_2 = convert_CvImage_To_QPicture(picture_2_Data.imageObj);
            ui->picture_2->setPicture(conv_Pic_2);
            ui->label_Name_Pic_2->setText(pic_2.fileName);
            ui->label_Dimension_Pic_2->setText(QString::number(picture_2_Data.image_Height) + "x" + QString::number(picture_2_Data.image_Width));
            ui->label_Size_Pic_2->setText(picture_2_Data.image_Size);

            float matchValue = computeIoU(picture_1_Data, picture_2_Data);
            // Format the float value with full precision
            QString matchValueString = QString::number(matchValue, 'f', 8);

            ui->label_Image_Match->setText(matchValueString);
            qApp->processEvents();
            pictureListIterator_2++;

            // Return if MatchValue is creater than defined Value
            if (matchValue >= minMatchValue) {
                cout << "compare_Pictures(): Found possible match" << endl;
                set_Select_Button_State(true);
                return; // TODO: Get User attention
            }
        }

        pictureListIterator_1++;
        picture_1_Data = generate_SIFT_Data_For_Picture(*pictureListIterator_1);
        pictureListIterator_2 = pictureListIterator_1 + 1;
    }

    ui->pushButton_Start->setText(startButtonTextStart);
    startButtonIsStart = true;
    stopPictureCompare = false;
    cout << "compare_Pictures(): Finished" << endl;
}

void* MainWindow::timeout(void *This)
{
    ((MainWindow *)This)->timeout_thread_running = true;
    sleep(1);
    ((MainWindow *)This)->check_Folder();
    ((MainWindow *)This)->timeout_thread_running = false;
    return NULL;
}

void MainWindow::on_Keep_Both_clicked()
{
    cout << "Selected Picture: [ both ]" << endl;

    set_Select_Button_State(false);
    compare_Pictures();
}

void MainWindow::on_pushButton_Keep_Left_clicked()
{
    cout << "Selected Picture: [ left ]" << endl;

    set_Select_Button_State(false);
    compare_Pictures();
}

void MainWindow::on_pushButton_Keep_Right_clicked()
{
    cout << "Selected Picture: [ right ]" << endl;

    set_Select_Button_State(false);
    compare_Pictures();
}

void MainWindow::set_Select_Button_State(bool value)
{
    ui->pushButton_Keep_Left->setEnabled(value);
    ui->pushButton_Keep_Right->setEnabled(value);
    ui->pushButton_Keep_Both->setEnabled(value);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    stopPictureCompare = true;

    // Accept the close event
    event->accept();

    // Uncomment the line below if you want to prevent the window from closing
    // event->ignore();
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "pictureTypes.h"

#include <map>
#include <vector>

#include <opencv4/opencv2/opencv.hpp>

#include <QMainWindow>
#include <QDir>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    const QString application_Name = "Search Duplicate Pictures";
    const QString application_Version = "0.1";

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    const int byteDivider = 1024;

    pthread_t timeout_thread_id;
    bool timeout_thread_running = false;

    bool startButtonIsStart = true;
    bool stopPictureCompare = false;
    QString startButtonTextStart = "Start";
    QString startButtonTextStop = "Stop";

    int processedPictures = 0;
    qint64 averageProcessingTimeSum = 0;

    std::vector<PictureInterface> pictureList;
    std::vector<PictureInterface>::iterator pictureListIterator_1;
    std::vector<PictureInterface>::iterator pictureListIterator_2;

    PictureSFITData picture_1_Data;
    float minMatchValue = 0.4;

    void check_Folder();

    void set_Select_Button_State(bool value);

    void compare_Pictures();

    static void* timeout(void *vargp);

public slots:
    void on_Select_Directory_clicked();
    void on_Start_clicked();
    void on_Keep_Both_clicked();
    void on_pushButton_Keep_Left_clicked();
    void on_pushButton_Keep_Right_clicked();

    void on_Directory_textChanged(const QString& lineEditText);

    void on_Include_SubDir_stateChanged(const bool& checked);
    void on_Compare_SubDir_stateChanged(const bool& checked);

    void closeEvent(QCloseEvent *event) override;
};
#endif // MAINWINDOW_H

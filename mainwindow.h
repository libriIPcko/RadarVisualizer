#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QResizeEvent>
#include <QEvent>
#include <QFileSystemModel>
#include <graphics.h>
#include <dataoperation.h>
#include <parseddata.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool event(QEvent *event);
    QFileSystemModel *rootPath = new QFileSystemModel;
    QGraphicsScene *scene = new QGraphicsScene();


    //Graphics grTest(scene);
    DataOperation *datOp = new DataOperation();
    Graphics *grTest = new Graphics(scene,datOp->parsed_data);


    int positionX = 0;
    int positionY = 0;
private: signals:
    void screenchanged();

private slots:
    void on_frame_graphic_refresh(int actualFrame);
    void on_pushButton_activity_released();
    void on_pushButton_released();

    void on_min_frame_spinBox_valueChanged(int arg1);

    void on_max_frame_spinBox_2_valueChanged(int arg1);

    void on_pushButton_2_released();

    void on_play_pushButton_2_released();

    void on_actual_frame_spinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    int min_frame_start = 0;
    int max_frame_start = 0;
};
#endif // MAINWINDOW_H

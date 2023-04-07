#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QResizeEvent>
#include <QEvent>
#include <QListWidgetItem>
#include <QDir>
#include <QFileInfo>


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
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

    QGraphicsScene *scene = new QGraphicsScene();

    //Graphics grTest(scene);
    DataOperation *datOp = new DataOperation();
    Graphics *grTest = new Graphics(scene,datOp->parsed_data);

    int positionX = 0;
    int positionY = 0;

    //Second Tab
    QListWidgetItem *item = new QListWidgetItem();
    QListWidgetItem *item_datFile = new QListWidgetItem();
    QListWidgetItem *item_csvFile = new QListWidgetItem();

    void update_csvFiles_listWidget();
    void update_datFiles_listWidget();
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

    void on_actual_framehorizontalSlider_sliderMoved(int position);

    void on_datFiles_listWidget_itemClicked(QListWidgetItem *item);

    void on_csvFiles_listWidget_itemClicked(QListWidgetItem *item);

    void on_checkBox_toggled(bool checked);

    void on_spinBox_editingFinished();

    void on_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
    int min_frame_start = 0;
    int max_frame_start = 0;
    int spinBox_counter = 100;
    int counter_MBR = 0;
};
#endif // MAINWINDOW_H

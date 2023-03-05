#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    grTest->bound_max_height = ui->centralwidget->size().height();
    grTest->bound_max_width = ui->centralwidget->size().width();

    //rootPath->setRootPath("C:/Users/bob/Documents/GitHub/RadarVisualizer/parse_script/CapturedData");
    rootPath->setRootPath("C:/Users/bob/Documents");
    ui->file_locat_treeView->setModel(rootPath);

    datOp->read_from_parsed_file(datOp->defaulthPath_outputCSV);
    ui->max_frame_spinBox_2->setValue(datOp->parsed_data->frame_data.size()-1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_activity_released()
{
    //grTest->drawPoint();
    /*
    grTest->drawPoint(positionX,positionY);
    positionX = positionX + 10;
    positionY = positionY + 10;
    qDebug() << "Test";
    */

    //datOp->to_CSV(datOp->parsed_data);
    //grTest->show_frame(datOp->parsed_data,0);
    grTest->show_CenterMarker();
    grTest->showData(ui->min_frame_spinBox->value(),ui->max_frame_spinBox_2->value(),20);
    connect(grTest,SIGNAL(frame(int)),this,SLOT(on_frame_graphic_refresh(int)));
}

void MainWindow::on_frame_graphic_refresh(int actualFrame){
    qDebug() << actualFrame;
    ui->actual_frame_spinBox->setValue(actualFrame);
    ui->actual_framehorizontalSlider->setValue(actualFrame);
}

bool MainWindow::event(QEvent *event){
    if(event->type() == QEvent::Resize){
        ui->tabWidget->resize(ui->centralwidget->size());
        //ui->graphicsView->resize(ui->centralwidget->size());
        int ax = ui->centralwidget->size().width();
        int ay = ui->centralwidget->size().height();
        grTest->viewWidget = ui->centralwidget->size();
        ui->graphicsView->resize(ax-80,ay-80);
        ui->graphicsView->move(30,40);

        qDebug() << "view was resized" << ui->centralwidget->size();

        return true;
    }
    else if(event->type() == QEvent::MouseButtonRelease){
        qDebug() << "MB was released";
        return true;
    }

    return QMainWindow::event(event);
}

void MainWindow::on_pushButton_released()
{
    MainWindow::scene->clear();
}


void MainWindow::on_min_frame_spinBox_valueChanged(int arg1){
    min_frame_start = arg1;
}


void MainWindow::on_max_frame_spinBox_2_valueChanged(int arg1){
    max_frame_start = arg1;
}


void MainWindow::on_pushButton_2_released()
{
    grTest->pause();
}


void MainWindow::on_play_pushButton_2_released()
{
    grTest->showData(ui->actual_frame_spinBox->value(),ui->max_frame_spinBox_2->value(),20);
    grTest->play();
}


void MainWindow::on_actual_frame_spinBox_valueChanged(int arg1)
{
    grTest->show_frame(arg1);
    grTest->show_Axis('a',ui->graphicsView->size(),10);
}


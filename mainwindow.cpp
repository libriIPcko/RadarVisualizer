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
    datOp->read_from_parsed_file(datOp->defaulthPath_outputCSV);
    //datOp->to_CSV(datOp->parsed_data);
    //grTest->show_frame(datOp->parsed_data,0);
    grTest->show_CenterMarker();
    grTest->showData(0,180,20);
}

bool MainWindow::event(QEvent *event){
    if(event->type() == QEvent::Resize){
        ui->tabWidget->resize(ui->centralwidget->size());
        //ui->graphicsView->resize(ui->centralwidget->size());
        int ax = ui->centralwidget->size().width();
        int ay = ui->centralwidget->size().height();
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


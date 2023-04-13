#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString appPath = QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("myproject.pro");
    qDebug() << "Application path:" << appPath;
    datOp->path_ParsedData =   QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("parse_script/ParsedData/");
    datOp->path_CapturedData = QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("parse_script/CapturedData/");
    datOp->path_py =  QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("parse_script/");
    qDebug() << datOp->path_ParsedData;
    qDebug() << datOp->path_CapturedData;
    qDebug() << datOp->path_py;


    ui->graphicsView->setScene(scene);
    QTransform trnsf;
    trnsf.rotate(180);
    trnsf.scale(20,20);
    trnsf.translate(-20,0);
    ui->graphicsView->setTransform(trnsf);


    grTest->bound_max_height = ui->centralwidget->size().height();
    grTest->bound_max_width = ui->centralwidget->size().width();

    //grTest->point_multiplier = ui->doubleSpinBox->value();

    ui->csvFiles_listWidget->setVisible(false);
    ui->datFiles_listWidget->setVisible(false);
    ui->typeofLW_Label->setVisible(false);
    ui->notification->setVisible(false);
    //update_csvFiles_listWidget();
    //for debug version
        QDir dir("C:/Users/bob/Documents/GitHub/RadarVisualizer/parse_script/ParsedData/");
    //for release version

        //QDir dir("../RadarVisualizer/");
        //QString relPath_ParsedData = "parse_script/ParsedData/";
        //QString relPath_CapturedData = "parse_script/CapturedData";
        //dir.setPath(relPath_ParsedData);

    for (const QFileInfo &file : dir.entryInfoList(QDir::Files))
    {
        QListWidgetItem *item_temp = new QListWidgetItem(file.fileName());
        item_temp->setData(Qt::UserRole, file.absolutePath()); // if you need absolute path of the file
        //listWidget->addItem(item);
        if(item_temp->text().contains(".cfg") == false){
            ui->csvFiles_listWidget->addItem(item_temp);
            item_csvFile = item_temp;
        }
    }
    //update_datFiles_listWidget();
    //for debug version
        dir.setPath("C:/Users/bob/Documents/GitHub/RadarVisualizer/parse_script/CapturedData/");
    //for release version
        //dir.setPath(relPath_CapturedData);

    for (const QFileInfo &file : dir.entryInfoList(QDir::Files))
    {
        QListWidgetItem *item_temp = new QListWidgetItem(file.fileName());
        item_temp->setData(Qt::UserRole, file.absolutePath()); // if you need absolute path of the file
        //listWidget->addItem(item);
        if(item_temp->text().contains(".cfg") == false){
            ui->datFiles_listWidget->addItem(item_temp);
            item_datFile = item_temp;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_datFiles_listWidget(){
    qDebug() << item_datFile->listWidget()->size();
    if(item_datFile->listWidget()->size().isEmpty() == false){
        item_datFile->listWidget()->clear();
    }
    //for Debug version
        //QDir dir("C:/Users/bob/Documents/GitHub/RadarVisualizer/parse_script/CapturedData/");

    //for release version
        //QDir dir = datOp->relativePath_DATFiles;
        QDir dir;
        //dir.setPath(datOp->path_CapturedData);
        //qDebug() << datOp->dir_CapturedData.absolutePath();
        //dir.setPath(datOp->dir_CapturedData.absolutePath());
        //dir.cdUp();
        dir.setPath(datOp->path_CapturedData);
        qDebug() << dir.absolutePath();

    for (const QFileInfo &file : dir.entryInfoList(QDir::Files))
    {
        QListWidgetItem *item_temp = new QListWidgetItem(file.fileName());
        item_temp->setData(Qt::UserRole, file.absolutePath()); // if you need absolute path of the file
        //listWidget->addItem(item);
        if(item_temp->text().contains(".cfg") == false){
            ui->datFiles_listWidget->addItem(item_temp);
            item_datFile = item_temp;
        }
    }
}

void MainWindow::update_csvFiles_listWidget(){
    qDebug() << item_csvFile->listWidget()->size();
    if(item_csvFile->listWidget()->size().isEmpty() == false){
        item_csvFile->listWidget()->clear();
    }
    //for Debug Version
        //QDir dir("C:/Users/bob/Documents/GitHub/RadarVisualizer/parse_script/ParsedData/");

    //for release version
        //QDir dir = datOp->relativePath_CSVFiles;
        QDir dir;
        //dir.setPath(datOp->path_ParsedData);
        //qDebug() << datOp->dir_ParsedData.absolutePath();
        //dir.setPath(datOp->dir_ParsedData.absolutePath());
        //dir.cdUp();

        dir.setPath(datOp->path_ParsedData);
        qDebug() << dir.absolutePath();

    for (const QFileInfo &file : dir.entryInfoList(QDir::Files))
    {
        QListWidgetItem *item_temp = new QListWidgetItem(file.fileName());
        item_temp->setData(Qt::UserRole, file.absolutePath()); // if you need absolute path of the file
        //listWidget->addItem(item);
        if(item_temp->text().contains(".cfg") == false){
            ui->csvFiles_listWidget->addItem(item_temp);
            item_csvFile = item_temp;
        }
    }
}

void MainWindow::on_pushButton_activity_released(){
    //grTest->show_frame(datOp->parsed_data,0);
    //grTest->show_CenterMarker();

    //grTest->showData(ui->min_frame_spinBox->value(),ui->max_frame_spinBox_2->value(),20);
    grTest->showData(ui->actual_frame_spinBox->value(),ui->max_frame_spinBox_2->value(),20);
    connect(grTest,SIGNAL(frame_sig(int)),this,SLOT(on_frame_graphic_refresh(int)));
}

void MainWindow::on_frame_graphic_refresh(int actualFrame){
    int value = datOp->parsed_data->frame_data[actualFrame].size();
    ui->lcd_PointNum->display(QString::number(value));
    ui->actual_frame_spinBox->setValue(actualFrame);
    ui->actual_framehorizontalSlider->setValue(actualFrame);
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
    //grTest->generateData(100);
    //Test of relative path
    QDir dir_parse_script;
    QDir dir_CapturedData;
    QDir dir_ParsedData;
    dir_parse_script.setPath("RadarVisualizer/parse_script");
    dir_CapturedData.setPath("RadarVisualizer/parse_script/CapturedData");
    dir_ParsedData.setPath("RadarVisualizer/parse_script/ParsedData");
    qDebug() << "Current path:" << dir_ParsedData.currentPath();
    qDebug() << "Absolute path:" << dir_ParsedData.absolutePath();
}



/*
void MainWindow::on_actual_frame_spinBox_valueChanged(int arg1)
{
    ui->actual_framehorizontalSlider->setValue(arg1);
    ui->lcd_PointNum->display(QString::number(datOp->parsed_data->frame_data[ui->actual_framehorizontalSlider->value()].size()));
    //grTest->show_frame(arg1);
    //grTest->show_Axis('a',ui->graphicsView->size(),10);
}
*/

/*
void MainWindow::on_actual_framehorizontalSlider_sliderMoved(int position)
{
    ui->actual_frame_spinBox->setValue(position);
    //grTest->show_frame(position);
    //grTest->show_Axis('a',ui->graphicsView->size(),10);
}
*/

void MainWindow::on_datFiles_listWidget_itemClicked(QListWidgetItem *item_datFile)
{
    ui->notification->setText("Parsing in progres...");
    ui->notification->setVisible(true);
    auto path = item_datFile->data(Qt::UserRole).toString();
    auto fileName = ui->datFiles_listWidget->currentItem()->text();
    QString absolutePath = path+"/"+fileName;
    QString finalPath;
    if(absolutePath.contains(".cfg") == true  || absolutePath.contains(".csv") == true){
        qDebug() << "It was chosen configuration file";
    }
    else{
        qDebug() << "path: " << absolutePath;
                //POSITION FOR IMPLEMENTATION ALGORITHM
            //Clear parsedData
        datOp->parsed_data->frame_data.clear();
            //Algorithm: parse, loadFromParseToTLVtempDat
        //datOp->call_py_parse(datOp->defaulthPath_inputDAT); //Here have to be modification to seeking actual file
        finalPath = datOp->call_py_parse_outFile(absolutePath);
        QFile csvFile(finalPath);
        while(csvFile.exists() == false){

        }
        /*
        datOp->read_from_parsed_file(finalPath);
        //datOp->read_from_parsed_file(absolutePath);
        //datOp->read_from_parsed_file(datOp->defaulthPath_outputCSV);
        ui->max_frame_spinBox_2->setValue(datOp->parsed_data->frame_data.size()-1);
        ui->actual_frame_spinBox->setMaximum(datOp->parsed_data->frame_data.size()-1);
        ui->actual_framehorizontalSlider->setMaximum(datOp->parsed_data->frame_data.size()-1);
        */
    }
    QString temp = "Data was parsed as: " + finalPath;
    //temp.append(finalPath);
    ui->notification->setText("Data was parsed as" + finalPath);
}


void MainWindow::on_csvFiles_listWidget_itemClicked(QListWidgetItem *item_csvFile){
    auto path = item_csvFile->data(Qt::UserRole).toString();
    auto fileName = ui->csvFiles_listWidget->currentItem()->text();
    QString absolutePath = path+"/"+fileName;
    if(absolutePath.contains(".cfg") == true || absolutePath.contains(".dat") == true){
        qDebug() << "It was chosen wrong file";
    }
    else{
        //Clear parsedData
        datOp->parsed_data->frame_data.clear();
        qDebug() << absolutePath;
        datOp->read_from_parsed_file(absolutePath);
        //datOp->read_from_parsed_file(datOp->defaulthPath_outputCSV);
        ui->max_frame_spinBox_2->setValue(datOp->parsed_data->frame_data.size()-1);
        ui->actual_frame_spinBox->setMaximum(datOp->parsed_data->frame_data.size()-1);
        ui->actual_framehorizontalSlider->setMaximum(datOp->parsed_data->frame_data.size()-1);

        //setup maximal dimension of view
        grTest->find_MinMax_pos();
        /*
        datOp->DatUnification_v0(datOp->parsed_data,1);
        datOp->to_CSV_UnificatedData_v0(datOp->parsed_data);
        */
        //grTest->showData(ui->actual_frame_spinBox->value(),ui->max_frame_spinBox_2->value(),10);
    }
    ui->notification->setText("Data are visualized ... do not trust me");
}


void MainWindow::on_checkBox_toggled(bool checked)
{
    ui->typeofLW_Label->setVisible(true);
    if(checked == true){
        update_datFiles_listWidget();
        ui->typeofLW_Label->setText("RAW radar data file");
        ui->csvFiles_listWidget->setVisible(false);
        ui->datFiles_listWidget->setVisible(true);
    }
    else{
        update_csvFiles_listWidget();
        ui->typeofLW_Label->setText("Parsed csv data");
        ui->csvFiles_listWidget->setVisible(true);
        ui->datFiles_listWidget->setVisible(false);
    }
}


void MainWindow::on_doubleSpinBox_editingFinished()
{
    //grTest->point_multiplier = ui->spinBox->value();
    //qDebug() << QString::number(grTest->point_multiplier);
    QTransform currentTransform = ui->graphicsView->transform();
    currentTransform.scale(ui->doubleSpinBox->value(),ui->doubleSpinBox->value());
    ui->graphicsView->setTransform(currentTransform);
    qDebug() << "dx: " << ui->graphicsView->transform().dx() << "dy" << ui->graphicsView->transform().dy();
}

void MainWindow::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        qDebug() << "Do something when the left mouse button is clicked on this item";
    } else if (event->button() == Qt::RightButton) {
        qDebug() << "// Do something when the right mouse button is clicked on this item";
    }
}

bool MainWindow::event(QEvent *event){
    if(event->type() == QEvent::Resize){
        ui->tabWidget->resize(ui->centralwidget->size());
        //ui->graphicsView->resize(ui->centralwidget->size());
        int ax = ui->centralwidget->size().width();
        int ay = ui->centralwidget->size().height();
        QSize viewSiz;
        viewSiz.setWidth(ax-50);
        viewSiz.setHeight(ay-100);
        grTest->viewWidget = viewSiz;
        //grTest->viewWidget = ui->centralwidget->size();
        ui->graphicsView->resize(ax-50,ay-100);
            //ui->graphicsView->move(30,40);
        ui->graphicsView->move(10,70);

        //qDebug() << "GraphicsView was resized" << ui->graphicsView->size();

        return true;
    }
    else if(event->type() == QEvent::MouseButtonRelease){
        grTest->removeItem();
        qDebug() << "MB was released" << counter_MBR++;// << "/" <<seedFTime;
        for(int i = 0;i<6;i++){
            QDateTime currTime = QDateTime::currentDateTime();
            int seedFTime = currTime.time().second()+currTime.time().minute();
            QRandomGenerator randX;
            randX.seed(seedFTime+i);
            float posX = randX.generateDouble() * 100;
            randX.seed(posX+i);
            float posY = randX.generateDouble() * 100;
            grTest->loadPoint(posX,posY,grTest->point_multiplier);
            qDebug() << i << " : " << "x: " << posX << " y:" << posY;
        }
        grTest->renderPoints();

        QDir directory;
        qDebug() << directory.root();
        return true;
    }
    else if(event->type() == QEvent::Wheel){
        qDebug() << "Weeeeeeeeee";
        return true;
    }


    return QMainWindow::event(event);
}

void MainWindow::on_actual_frame_spinBox_editingFinished()
{
    int newVal = ui->actual_frame_spinBox->value();
    ui->actual_framehorizontalSlider->setValue(newVal);
    ui->actual_framehorizontalSlider->setValue(newVal);
    ui->lcd_PointNum->display(QString::number(datOp->parsed_data->frame_data[newVal].size()));
    grTest->show_frame(newVal);
}

void MainWindow::on_actual_framehorizontalSlider_sliderMoved(int position)
{
    //int newVal = ui->actual_framehorizontalSlider->value();
    int newVal = position;
    qDebug() << "frameHorizontalSlide: " << newVal;
    ui->actual_framehorizontalSlider->setValue(newVal);
    ui->actual_frame_spinBox->setValue(newVal);
    ui->lcd_PointNum->display(QString::number(datOp->parsed_data->frame_data[newVal].size()));
    grTest->show_frame(newVal);
}

void MainWindow::on_actual_framehorizontalSlider_sliderReleased()
{

}

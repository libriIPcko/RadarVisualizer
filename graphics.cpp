#include "graphics.h"
#include <QGraphicsScene>


Graphics::Graphics(QGraphicsScene *scene, ParsedData *parDat) : m_scene(scene), m_parDat(parDat){

}


void Graphics::drawSomething(){
    QPainter paint;
    int radius = 20;
    paint.drawEllipse(QPointF(10,10),radius,radius);

    QLine ln;
    ln.setLine(10,10,120,180);
    QPen pen;
    QColor black;
    black.black();

    pen.setColor(black);
    pen.setWidth(20);
    m_scene->addLine(ln,pen);
    QRectF rect;
    rect.setHeight(10);
    rect.setWidth(10);
    m_scene->addEllipse(rect,pen);
}

void Graphics::drawPoint(){
    QRandomGenerator Gen_width;
    QRandomGenerator Gen_height;
    QPainter paint;
    QRectF rect;
    rect.setX(5);
    rect.setY(5);
    ell = m_scene->addEllipse(rect);
    connect(tim_move,SIGNAL(timeout()),SLOT(on_move_timeout()));
    tim_move->setInterval(400);
    tim_move->start();
}

void Graphics::drawPoint(int posX,int posY){
    QRandomGenerator Gen_width;
    QRandomGenerator Gen_height;
    //QPainter paint;
    QPen pen;
    pen.setColor(Qt::red);
    QBrush brush;
    brush.setColor(Qt::red);
    QRectF rect;
    rect.setX(4);
    rect.setY(4);
    QPointF pos;
    pos.setX(posX);
    pos.setY(posY);
    rect.moveTo(pos);
    ell = m_scene->addEllipse(rect,pen,brush);
    //qDebug() << ell->pos();
    /*
    connect(tim_move,SIGNAL(timeout()),SLOT(on_move_timeout()));
    tim_move->setInterval(400);
    tim_move->start();
    */
}
void Graphics::show_CenterMarker(){
    QPen line_type;
    line_type.setStyle(Qt::DotLine);
    line_type.setBrush(Qt::red);
    QLine vert;
    vert.setLine(viewWidget.width()*-1,0,viewWidget.width(),0);
    QLine hori;
    hori.setLine(0,0,0,viewWidget.height());
    m_scene->addLine(vert,line_type);
    m_scene->addLine(hori,line_type);
}

//@direction y or x
//@maxVal  == maximal value of direction weight or height
//@step    == step of line on belonging to direction
void Graphics::show_Axis(char direction,QSize size, int step){
    QPen line_type;
    line_type.setColor(Qt::gray);
    line_type.setStyle(Qt::SolidLine);
    line_type.setWidth(1);
    QLine line;
    //Draw y axis
    int maxVal = size.height();
    if(direction == 'y'){
        int i = 0;
        while(i<maxVal){
            //x1 y1 x2 y2
            line.setLine(-10,i,10,i);
            i = i + step;
            m_scene->addLine(line,line_type);
        }
    }
    //Draw x axis
    else if(direction == 'x'){
        int maxVal = size.width();
        int i = maxVal*-1;
        while(i<maxVal){
            //x1 y1 x2 y2
            line.setLine(i,-10,i,10);
            i = i + step;
            m_scene->addLine(line,line_type);
        }
    }
    //Draw booth axis
    else{
        int maxVal = size.height();
        int i = 0;
        while(i<maxVal){
            //x1 y1 x2 y2
            line.setLine(maxVal*-1,i,maxVal,i);
            i = i + step;
            m_scene->addLine(line,line_type);
        }
        maxVal = size.width();
        i = maxVal*-1;
        while(i<maxVal){
            //x1 y1 x2 y2
            line.setLine(i,0,i,maxVal);
            i = i + step;
            m_scene->addLine(line,line_type);
        }
    }
}

void Graphics::show_frame(ParsedData *parDat, int frame){
    //size of graphicsView
        //*100 for test
    //take coordinations from parDat for chosen frame
        //parDat.frame_data
        for(int i=0;i < (int)parDat->frame_data[frame].size();i++){
            int posX = parDat->frame_data[frame][i].posX *100;
            int posY = parDat->frame_data[frame][i].posY *100;
            drawPoint(posX,posY);
        }
    //recalculate coordinations
}
void Graphics::show_frame(int frame){
    m_scene->clear();
    for(int i=0;i < (int)m_parDat->frame_data[frame].size();i++){
        int posX = m_parDat->frame_data[frame][i].posX *100;
        int posY = m_parDat->frame_data[frame][i].posY *100;
        drawPoint(posX,posY);
    }
    show_Axis('a',viewWidget,10);
    show_CenterMarker();
}


void Graphics::showData(int start_Frame, int end_Frame,int fps){
    actualFrame = start_Frame;
    endFrame = end_Frame;
    tim_showData = new QTimer;
    connect(tim_showData,SIGNAL(timeout()),this,SLOT(on_showData_next()));
    float interval = 10000/fps;
    //float interval = 678.123456;
    qDebug() << interval << "[ms]";
    tim_showData->setInterval(interval);
    tim_showData->start();
}
void Graphics::pause(){
    tim_showData->stop();
}

void Graphics::play(){
    tim_move->setInterval(500);
    qDebug() << "In progress the FPS value is not shared with this method";
    tim_move->start();

}

void Graphics::on_move_timeout(){
    ell->moveBy(10,10);
}
void Graphics::on_showData_next(){
    //qDebug() << "interval: " << tim_showData->interval() << "[ms]";
    m_scene->clear();
    for(int i=0;i<(int) m_parDat->frame_data[actualFrame].size();i++){
        int posX = m_parDat->frame_data[actualFrame][i].posX *100;
        int posY = m_parDat->frame_data[actualFrame][i].posY *100;
        drawPoint(posX,posY);
    }
    if(actualFrame >= endFrame && actualFrame >= (int)m_parDat->frame_data.size()){
        actualFrame = 0;
        tim_showData->stop();
    }
    else{
        actualFrame++;
    }
    show_Axis('a',viewWidget,10);
    show_CenterMarker();
    emit frame_sig(actualFrame-1);


}

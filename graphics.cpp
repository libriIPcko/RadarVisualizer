#include "graphics.h"
#include <QGraphicsScene>


Graphics::Graphics(QGraphicsScene *scene) : m_scene(scene){

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
    QPainter paint;
    QRectF rect;
    rect.setX(4);
    rect.setY(4);
    QPointF pos;
    pos.setX(posX);
    pos.setY(posY);
    rect.moveTo(pos);
    ell = m_scene->addEllipse(rect);
    qDebug() << ell->pos();
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
    vert.setLine(-50,0,50,0);
    QLine hori;
    hori.setLine(0,-50,0,50);
    m_scene->addLine(vert,line_type);
    m_scene->addLine(hori,line_type);
}
void Graphics::show_frame(ParsedData *parDat, int frame){
    //size of graphicsView
        //*100 for test
    //take coordinations from parDat for chosen frame
        //parDat.frame_data
        for(int i=0;i<parDat->frame_data[frame].size();i++){
            int posX = parDat->frame_data[frame][i].posX *100;
            int posY = parDat->frame_data[frame][i].posY *100;
            drawPoint(posX,posY);
        }
    //recalculate coordinations
}

void Graphics::on_move_timeout(){
    ell->moveBy(10,10);
}

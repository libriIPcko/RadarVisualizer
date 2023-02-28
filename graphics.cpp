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

void Graphics::on_move_timeout(){
    ell->moveBy(10,10);
}

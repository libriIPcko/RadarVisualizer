#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "QGraphicsObject"
#include "QGraphicsScene"
#include "QPainter"
#include <QRandomGenerator>
#include <QTimer>

#include <dataoperation.h>
#include <parseddata.h>

class Graphics : QObject

{
    Q_OBJECT
public:
    Graphics(QGraphicsScene *scene);
    void drawPoint();
    void drawPoint(int posX,int posY);
    void drawSomething();
    int bound_max_height = 0;
    int bound_max_width = 0;
    QTimer *tim_move = new QTimer();
    QGraphicsEllipseItem *ell = new QGraphicsEllipseItem();

    void show_frame(ParsedData *parDat, int frame);
    void show_CenterMarker();
private:
    QGraphicsScene *m_scene = new QGraphicsScene();

private slots:
    void on_move_timeout();
private: signals:
    void timeout();

};

#endif // GRAPHICS_H

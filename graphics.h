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
    Graphics(QGraphicsScene *scene, ParsedData *parDat);
    void drawPoint();
    void drawPoint(int posX,int posY);
    void drawSomething();
    int bound_max_height = 0;
    int bound_max_width = 0;
    QTimer *tim_move = new QTimer();
    QGraphicsEllipseItem *ell = new QGraphicsEllipseItem();

    QTimer *tim_showData;
    void showData(int startFrame, int endFrame,int fps);
    void show_frame(ParsedData *parDat, int frame);
    void show_CenterMarker();
    void show_Axis(char direction,int maxVal, int step);
private:
    QGraphicsScene *m_scene = new QGraphicsScene();
    ParsedData *m_parDat = new ParsedData();

    int actualFrame = 0;
    int endFrame = 0;

private slots:
    void on_move_timeout();
    void on_showData_next();
private: signals:
    void timeout();

};

#endif // GRAPHICS_H

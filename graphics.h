#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "QGraphicsObject"
#include "QGraphicsScene"
#include "QPainter"
#include <QRandomGenerator>
#include <QTimer>
#include <QEvent>
#include <QGraphicsSceneEvent>

#include <dataoperation.h>
#include <parseddata.h>

class Graphics : public QObject

{
    Q_OBJECT
public:
    Graphics(QGraphicsScene *scene, ParsedData *parDat);
    void drawPoint();
    void loadPoint(float posX,float posY,float multiplier);
    void renderPoints();
    void removeItem();


    void drawPoint(float posX,float posY, int multiplier);
    void drawSomething();
    int bound_max_height = 0;
    int bound_max_width = 0;

    int  point_multiplier = 100;
    QTimer *tim_move = new QTimer();
    QGraphicsEllipseItem *ell = new QGraphicsEllipseItem(); //global variable for drawPoint(), it is recommended for without layer approachb
    QList<QGraphicsItem*> items_list;
    QGraphicsItemGroup *group = new QGraphicsItemGroup();


    QTimer *tim_showData;
    void showData(int startFrame, int endFrame,int fps);
    void pause();
    void play();
    void show_frame(int frame);
    void show_frame(ParsedData *parDat, int frame);
    void show_CenterMarker();

    void show_Axis(char direction,QSize size, int step);
    void find_MinMax_pos();

    QSize viewWidget;
private:
    QGraphicsScene *m_scene = new QGraphicsScene();
    ParsedData *m_parDat = new ParsedData();
    bool event(QEvent *event);

    int actualFrame = 0;
    int endFrame = 0;

    float min_pos_Y = 0;
    float min_pos_X = 0;
    float max_pos_Y = 0;
    float max_pos_X = 0;

    void mousePos(QGraphicsSceneMouseEvent* event);

private slots:
    void on_move_timeout();
    void on_showData_next();
private: signals:
    void timeout();
public: signals:
    void frame_sig(int actualFrame);

};

#endif // GRAPHICS_H

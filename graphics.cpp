#include "graphics.h"
#include <QGraphicsScene>


Graphics::Graphics(QGraphicsScene *scene, ParsedData *parDat) : m_scene(scene), m_parDat(parDat){

}

void Graphics::mousePos(QGraphicsSceneMouseEvent* event){
    qDebug() << "x: " << event->scenePos().x() << "\n";
    qDebug() << "y: " << event->scenePos().y() << "\n";
}

void Graphics::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (event->button() == Qt::LeftButton) {
        qDebug() << "Do something when the left mouse button is clicked on this item";
    } else if (event->button() == Qt::RightButton) {
        qDebug() << "// Do something when the right mouse button is clicked on this item";
    }
}

bool Graphics::event(QEvent *event){
    qDebug() << event->type();
    if(event->type() == QEvent::Resize){
        qDebug() << "view was resized" << event->type() ;
        return true;
    }
    else if(event->type() == QEvent::GraphicsSceneMouseRelease){
        qDebug() << "MB was released";
        return true;
    }
    else if(event->type() == QEvent::GraphicsSceneMouseDoubleClick){
        qDebug() << "Double-click";
        return true;
    }
    else if(event->type() == QEvent::GraphicsSceneWheel){
        qDebug() << "Wheeeeeee";
        return true;
    }
    return Graphics::event(event);
}

void Graphics::find_MinMax_pos(){
    for(int i=0;i<m_parDat->frame_data.size();i++){
        for(int j=0;j<m_parDat->frame_data[i].size();j++){
            if(max_pos_X < m_parDat->frame_data[i][j].posX){
                max_pos_X = m_parDat->frame_data[i][j].posX;
            }
            if(max_pos_Y < m_parDat->frame_data[i][j].posY){
                max_pos_Y = m_parDat->frame_data[i][j].posY;
            }
            if(min_pos_X > m_parDat->frame_data[i][j].posX){
                min_pos_X = m_parDat->frame_data[i][j].posX;
            }
            if(min_pos_Y > m_parDat->frame_data[i][j].posY){
                min_pos_Y = m_parDat->frame_data[i][j].posY;
            }
        }
    }
    qDebug() << "Min/Max X: " << min_pos_X << "/" << max_pos_X;
    qDebug() << "Min/Max Y: " << min_pos_Y << "/" << max_pos_Y;
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

void Graphics::loadPoint(float posX,float posY,float multiplier){
   float pos_X = posX * multiplier;
   float pos_Y = posY * multiplier;
   //original command without change of size
   //items_list.append(new QGraphicsEllipseItem(pos_X,pos_Y,2,2));
   //change size
   items_list.append(new QGraphicsEllipseItem(pos_X,pos_Y,0.1,0.1));
}

void Graphics::renderPoints(){
    // Loop through the items_list and add each ellipse to the scene
    for (int i = 0; i < items_list.size(); i++) {
        // Get the ellipse item from the list
        QGraphicsEllipseItem* ellipse = dynamic_cast<QGraphicsEllipseItem*>(items_list.at(i));

        // Add the ellipse item to the scene
        m_scene->addItem(ellipse);
        m_scene->items().at(i)->setOpacity(1);
//        m_scene->update();

        if(ellipse->scene() == nullptr){
            qDebug() << "The item num:" << i << "was not added";
        }
        //delete ellipse;
    }

}

void Graphics::removeItem(){
    if(m_scene->children().size() > 0){
        //m_scene->destroyItemGroup(group);
        for(int n=0;n<=items_list.size()-1;n++){
            m_scene->removeItem(items_list.at(n));
            //group->removeFromGroup(items_list.at(n));
        }
        items_list.clear();
    }
}

void Graphics::drawPoint(float posX,float posY, int multiplier){
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
    float pos_X = posX*multiplier;
    float pos_Y = posY*multiplier;
    pos.setX(pos_X);
    pos.setY(pos_Y);
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
    line_type.setWidthF(0.1);
    QLine vert;
    vert.setLine(0,0,0,viewWidget.height());

    QLine hori;
    hori.setLine(viewWidget.width()*-1,0,viewWidget.width(),0);

    m_scene->addLine(vert,line_type);
    m_scene->addLine(hori,line_type);
}

//@direction y or x
//@maxVal  == maximal value of direction weight or height
//@step    == step of line on belonging to direction
void Graphics::show_Axis(char direction,QSize size, int step){
    QColor line_color;
    line_color.setRgbF(372,366,363,0.1);
    QPen line_type;
    line_type.setColor(line_color);
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
/*
void Graphics::show_frame(ParsedData *parDat, int frame){
    //size of graphicsView
        //*100 for test
    //take coordinations from parDat for chosen frame
        //parDat.frame_data
        removeItem();
        for(int i=0;i < (int)parDat->frame_data[frame].size();i++){
            int posX = parDat->frame_data[frame][i].posX *100;
            int posY = parDat->frame_data[frame][i].posY *100;
            //drawPoint(posX,posY,point_multiplier);
            loadPoint(posX,posY,point_multiplier);
        }
        renderPoints();
    //recalculate coordinations
}
*/

/*
void Graphics::show_frame(int frame){
    //m_scene->clear();
    removeItem();
    for(int i=0;i < (int)m_parDat->frame_data[frame].size();i++){
        int posX = m_parDat->frame_data[frame][i].posX;//multiplier *100;
        int posY = m_parDat->frame_data[frame][i].posY;//multiplier *100;
        //drawPoint(posX,posY,point_multiplier);
        loadPoint(posX,posY,point_multiplier);
    }
    renderPoints();
    //show_Axis('a',viewWidget,10);
    show_CenterMarker();
}
*/

void Graphics::show_frame(int frame){
    if(items_list.size() != 0){
        for(int i=0;i<items_list.size();i++){
            m_scene->removeItem(items_list[i]);
        }
        items_list.clear();
        m_scene->destroyItemGroup(group);
    }
    else{
        show_CenterMarker();
    }

    counter_showData++;
    for(int i=0;i<(int) m_parDat->frame_data[actualFrame].size();i++){
        int posX = m_parDat->frame_data[actualFrame][i].posX; // multiplier*10;
        int posY = m_parDat->frame_data[actualFrame][i].posY; // multiplier*10;
        //drawPoint(posX,posY,point_multiplier);
        loadPoint(posX,posY,point_multiplier);
    }
    renderPoints();
    emit frame_sig(actualFrame-1);
    /*
    if(actualFrame >= endFrame && actualFrame >= (int)m_parDat->frame_data.size()){
        actualFrame = 0;
        counter_showData = 0;
        tim_showData->stop();
    }
    else{
        actualFrame++;
    }
    */
    //show_Axis('a',viewWidget,10);


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
    /*
    tim_move->setInterval(500);
    qDebug() << "In progress the FPS value is not shared with this method";
    tim_move->start();
    */
}

void Graphics::on_move_timeout(){
    ell->moveBy(10,10);
}
void Graphics::
on_showData_next(){
    /*
    if(counter_showData > 0){
        for(int i=0;i<items_list.size();i++){
            m_scene->removeItem(items_list[i]);
        }
        items_list.clear();
        //m_scene->destroyItemGroup(group);
    }
    counter_showData++;
    */
    // Get a list of all the items in the scene
    QList<QGraphicsItem*> all_items = m_scene->items();

    // Loop through the list and remove any ellipses that were previously added
    int var = m_scene->items().size();
    for (int i = 0; i < all_items.size(); i++) {
        if (all_items.at(i)->type() == QGraphicsEllipseItem::Type) {
            m_scene->removeItem(all_items.at(i));
            var = m_scene->items().size();
        }
        items_list.clear();
    }

    int size = m_parDat->frame_data[actualFrame].size()-1;
    for(int j=0;j<size;j++){
        int posX = m_parDat->frame_data[actualFrame][j].posX; // multiplier*10;
        int posY = m_parDat->frame_data[actualFrame][j].posY; // multiplier*10;
        //drawPoint(posX,posY,point_multiplier);
        loadPoint(posX,posY,point_multiplier);
    }
    renderPoints();
    if(actualFrame >= endFrame && actualFrame >= (int)m_parDat->frame_data.size()){
        actualFrame = 0;
        counter_showData = 0;
        tim_showData->stop();
    }
    else{
        actualFrame++;
    }
    //show_Axis('a',viewWidget,10);
    show_CenterMarker();
    emit frame_sig(actualFrame-1);

}

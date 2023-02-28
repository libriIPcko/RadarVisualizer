#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QResizeEvent>
#include <QEvent>
#include <graphics.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool event(QEvent *event);
    QGraphicsScene *scene = new QGraphicsScene();
    //Graphics grTest(scene);
    Graphics *grTest = new Graphics(scene);

    int positionX = 0;
    int positionY = 0;
private: signals:
    void screenchanged();

private slots:
    void on_pushButton_activity_released();
    void on_pushButton_released();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

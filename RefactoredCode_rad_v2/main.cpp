#include <QCoreApplication>
#include <cfgFiles.h>
#include <radar_v2.h>
#include <time_measure.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    radar_v2 rad;
    rad.parse_offline_data(raw_data,true);

    /*
    bool stat;
    stat = rad.init_AWR1843(); // Get path from MATLAB configuration procedure.
    qDebug() << "Stat of init" <<QString::number(stat) << "\n";
    */




    return a.exec();
}

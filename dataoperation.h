#ifndef DATAOPERATION_H
#define DATAOPERATION_H

#include <QObject>
#include <QProcess>
#include <vector>
#include <parseddata.h>
#include <QFile>
#include <QTextStream>

class DataOperation : QObject
{
    Q_OBJECT
public:
    DataOperation();
    void call_py_parse(QString path);
    void read_from_parsed_file(QString path);
    QString defaulthPath_outputCSV = "C:/Users/bob/Documents/GitHub/RadarVisualizer/parse_script/mmw_demo_output.csv";
    QString defaulthPath_inputDAT = "C:/Users/bob/Documents/GitHub/RadarVisualizer/parse_script/CapturedData/AWR1843_captured.dat";
};

#endif // DATAOPERATION_H

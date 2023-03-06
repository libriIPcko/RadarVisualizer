#ifndef DATAOPERATION_H
#define DATAOPERATION_H

#include <QObject>
#include <QProcess>
#include <vector>
#include <parseddata.h>
#include <QFile>
#include <QTextStream>

#include <parseddata.h>

class DataOperation : QObject
{
    Q_OBJECT
public:
    DataOperation();
    void call_py();
    void call_py_parse(QString path);

    void read_from_parsed_file(QString path);
    void load_toParsedData_dependentOnFrame(QString data, int column_pos);
    void to_CSV(ParsedData* parDat);
    int load_toParsedData_dependentOnFrame_COUNTER = 0;
    QString defaulthPath_outputCSV = "C:/Users/bob/Documents/GitHub/RadarVisualizer/parse_script/mmw_demo_output.csv";
    QString defaulthPath_inputDAT = "C:/Users/bob/Documents/GitHub/RadarVisualizer/parse_script/CapturedData/AWR1843_captured.dat";
    ParsedData *parsed_data = new ParsedData();
private:

};

#endif // DATAOPERATION_H

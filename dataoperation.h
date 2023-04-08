#ifndef DATAOPERATION_H
#define DATAOPERATION_H

#include <QObject>
#include <QProcess>
#include <vector>
#include <parseddata.h>
#include <QFile>
#include <QTextStream>
#include <QDir>

#include <parseddata.h>

class DataOperation : QObject
{
    Q_OBJECT
public:
    DataOperation();
    void call_py();
    void call_py_parse(QString path);
    QString call_py_parse_outFile(QString path);

    void read_from_parsed_file(QString path);
    void load_toParsedData_dependentOnFrame(QString data, int column_pos);
    void to_CSV(ParsedData* parDat);
    int load_toParsedData_dependentOnFrame_COUNTER = 0;

    QDir dir_parse_script;
    QDir dir_CapturedData;
    QDir dir_ParsedData;

    //Path for debug version:
    /*
    QString defaulthPath_outputCSV = "C:/Users/bob/Documents/GitHub/RadarVisualizer/parse_script/mmw_demo_output.csv";
    QString defaulthPath_inputDAT = "C:/Users/bob/Documents/GitHub/RadarVisualizer/parse_script/CapturedData/AWR1843_captured.dat";
    QString relativePath_DATFiles = "C:/Users/bob/Documents/GitHub/RadarVisualizer/parse_script/CapturedData/";
    QString relativePath_CSVFiles = "C:/Users/bob/Documents/GitHub/RadarVisualizer/parse_script/ParsedData/";

    QString path_py = "C:/Users/bob/Documents/GitHub/RadarVisualizer/parse_script/";
    QString path_ParsedData = "C:/Users/bob/Documents/GitHub/RadarVisualizer/parse_script/ParsedData/";
    QString path_CapturedData = "C:/Users/bob/Documents/GitHub/RadarVisualizer/parse_script/CapturedData/";
    */

    //Final version of path definition
    QString path_py;
    QString path_ParsedData;
    QString path_CapturedData;
        QString relativePath_DATFiles;
        QString relativePath_CSVFiles;

    //QString path_ParsedData =   "/parse_script/ParsedData/";
    //QString path_CapturedData = "/parse_script/CapturedData/";
    //QString path_ParseScript =  "/parse_script/";

    //Path for realease version:
    //QString relativePath_DATFiles = "parse_script/CapturedData/";
    //QString relativePath_CSVFiles = "parse_script/ParsedData/";
    //QString defaulthPath_outputCSV = "release/parse_script/mmw_demo_output.csv";
    //QString defaulthPath_inputDAT = "release/parse_script/CapturedData/AWR1843_captured.dat";

    ParsedData *parsed_data = new ParsedData();

    void DatUnification_v0(ParsedData *parDat, float limitRadius);
    void DatUnification_v1(ParsedData *parDat,int frame, float limitRadius);
    void to_CSV_UnificatedData_v0(ParsedData* parDat);

    void sortBy_X(ParsedData* parDat, int frame);
private:



};

#endif // DATAOPERATION_H

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

    //Final version of path definition
    QString path_py;
    QString path_ParsedData;
    QString path_CapturedData;
        QString relativePath_DATFiles;
        QString relativePath_CSVFiles;

    ParsedData *parsed_data = new ParsedData();

    void DatUnification_v0(ParsedData *parDat, float limitRadius);
    void DatUnification_v1(ParsedData *parDat,int frame, float limitRadius);
    void to_CSV_UnificatedData_v0(ParsedData* parDat);

    void sortBy_X(ParsedData* parDat, int frame);
private:



};

#endif // DATAOPERATION_H

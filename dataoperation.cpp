#include "dataoperation.h"
#include "qdebug.h"

DataOperation::DataOperation()
{

}


void DataOperation::call_py_parse(QString path){
    QString path_py = "C:/Users/bob/Documents/RadarVisualizer/parse_script";
    QString  command("python");
    QStringList params = QStringList() << "mmw_demo_example_script.py   " << path;

    QProcess *process = new QProcess();
    process->startDetached(command, params, path_py);
    process->waitForFinished();
    process->close();
}
void DataOperation::read_from_parsed_file(QString path){
    QFile file(path);
    QTextStream data(&file);
    if(file.open(QIODevice::ReadOnly | QIODevice::Truncate) == false){
        qDebug() << "Error during open file";
    }
    else{
        //QString fileData = data.readAll();
        //qDebug() << fileData;
        QString line;

        //line
        QFile output("C:/Users/bob/Documents/GitHub/RadarVisualizer/tst/outTxt.txt");
        QTextStream outStream(&output);
        output.open(QIODevice::ReadWrite | QIODevice::Truncate);
        while(data.readLineInto(&line)){
            //comma
            int comma_step = 0;
            int posColumn = 0;
            int pos_in_Line = 0;
            while(comma_step < line.length()){
                posColumn = line.indexOf(',',posColumn+1);
                //posColumn_next = line.indexOf(',',posColumn+1);
                QString out;
                while(pos_in_Line<posColumn){
                    out.append(line.at(pos_in_Line));
                    pos_in_Line++;
                }
                qDebug() << out << "\n";
                outStream << out << "\n";
                comma_step++;
            }
        }
    }
}

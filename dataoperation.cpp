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
        //line
        QFile output("C:/Users/bob/Documents/GitHub/RadarVisualizer/tst/outTxt.txt");
        QTextStream outStream(&output);
        output.open(QIODevice::ReadWrite | QIODevice::Truncate);
        QString line;

        while(data.readLineInto(&line)){
            int comma = 0;
            int next_comma = 0;
            while(comma < line.length()){
                if(next_comma == -1){
                    break;
                }
                else{
                    next_comma = line.indexOf(',',comma+1);
                }
                QString column;
                while(comma < next_comma){
                    column.append(line.at(comma));
                    comma++;
                }
                qDebug() << column << "----";
                column.clear();
            }
        }

    }
}

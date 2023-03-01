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

        int line_pos = 0;

        bool  headerRemove = true;
        while(data.readLineInto(&line)){
           if(headerRemove == true){
               headerRemove = false;
           }
           else{
               int comma = 0;
               int next_comma = 0;
               outStream << "\n";
               int column_pos = 0;
               while(comma < line.length()){
                   QString column;
                   next_comma = line.indexOf(',',comma+1);
                   while(comma < next_comma){
                       column.append(line.at(comma));
                       comma++;
                   }
                   if(next_comma == -1){
                       while(comma < line.length()){
                           column.append(line.at(comma));
                           comma++;
                       }
                       //comma++; //jump comma
                       //qDebug() << column << "----";
                       load_toParsedData(column,column_pos);
                       column_pos++;
                       column.clear();
                       break;
                   }
                   comma++; //jump comma
                   //qDebug() << column << "----";
                   load_toParsedData(column,column_pos);
                   column_pos++;

                   column.clear();
               }
           }
        }
        qDebug() << "The file was succesfull readed" << parsed_data->frame_data.size();
    }
}

void DataOperation::load_toParsedData(QString data, int data_pos){
    bool ok;
    switch(data_pos){
        case 0:    //frame
            parsed_data->temporary.frame = data.toInt(&ok,10);
            break;
        case 1: //detObj
            parsed_data->temporary.detObj = data.toInt(&ok,10);
            break;
        case 2: //posX
            parsed_data->temporary.posX = data.toFloat();
            break;
        case 3: //posY
            parsed_data->temporary.posY = data.toFloat();
            break;
        case 4: //posZ
            qDebug() << "for 2D it is useless column";
            break;
        case 5: //speed
            parsed_data->temporary.speed = data.toFloat();
            break;
        case 6: //snr
            parsed_data->temporary.snr = data.toInt(&ok,10);
            break;
        case 7: //noise
            parsed_data->temporary.noise = data.toInt(&ok,10);
            parsed_data->frame_data.push_back(parsed_data->temporary);
            break;
        default:
            qDebug() << "It give data_pos out of index";
            break;
    }
}

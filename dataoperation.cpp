#include "dataoperation.h"
#include "qdatetime.h"
#include "qdebug.h"

DataOperation::DataOperation()
{

}
void DataOperation::call_py(){

    QString path_py = "C:/Users/bob/Documents/GitHub/RadarVisualizer/parse_script/";
    QString  command("python");
    QStringList params = QStringList() << "mmw_demo_example_script.py";
    QProcess *process = new QProcess();
    process->startDetached(command, params, path_py);
    process->waitForFinished();
    process->close();
}

void DataOperation::call_py_parse(QString path){
    qDebug() << path;
    QString path_py = "C:/Users/bob/Documents/GitHub/RadarVisualizer/parse_script/";
    QString  command("python");
    /*
    QDate actualDate;
    QTime actualTime;
    QString date = QString::number(actualDate.day()) + "." + QString::number(actualDate.month()) + "__";
    QString time = QString::number(actualTime.hour()) +":"+ QString::number(actualTime.minute()) + ":" + QString::number(actualTime.minute());
    QString formatedPath = path + "/" + "parsOut" + "_" + date + time;
    */
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString formatedSuffixPath =
            "parsOut_"
            + QString::number(currentDateTime.date().day())+"."
            + QString::number(currentDateTime.date().month())
            + "__"
            + QString::number(currentDateTime.time().hour()) +"_"
            + QString::number(currentDateTime.time().minute()) +"_"
            + QString::number(currentDateTime.time().second()) +".csv";
    QString absoluteParsedPath = "C:/Users/bob/Documents/GitHub/RadarVisualizer/parse_script/ParsedData/" + formatedSuffixPath;
    qDebug() << "absoluteParsedPath: " << absoluteParsedPath;
    QStringList params = QStringList() << "mmw_demo_example_script.py" << path << formatedSuffixPath;

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
                       load_toParsedData_dependentOnFrame(column,column_pos);
                       column_pos++;
                       column.clear();
                       break;
                   }
                   comma++; //jump comma
                   //qDebug() << column << "----";
                   load_toParsedData_dependentOnFrame(column,column_pos);
                   column_pos++;
                   column.clear();
               }
           }
        }
        qDebug() << "The file was succesfull readed" << parsed_data->frame_data.size();
    }
}

/*
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
*/

void DataOperation::load_toParsedData_dependentOnFrame(QString data, int column_pos){
    bool ok;
    switch(column_pos){
        case 0:    //frame
            parsed_data->temp_detObj.frame = data.toInt(&ok,10);
            break;
        case 1: //detObj
            parsed_data->temp_detObj.detObj = data.toInt(&ok,10);
            break;
        case 2: //posX
            parsed_data->temp_detObj.posX = data.toFloat();
            break;
        case 3: //posY
            parsed_data->temp_detObj.posY = data.toFloat();
            break;
        case 4: //posZ
            //qDebug() << "for 2D it is useless column";
            parsed_data->temp_detObj.posZ = data.toFloat();
            break;
        case 5: //speed
            parsed_data->temp_detObj.speed = data.toFloat();
            break;
        case 6: //snr
            parsed_data->temp_detObj.snr = data.toInt(&ok,10);
            break;
        case 7: //noise
            parsed_data->temp_detObj.noise = data.toInt(&ok,10);
            parsed_data->detObj_data.push_back(parsed_data->temp_detObj);
            if(parsed_data->detObj_data.size()>1){
                if(parsed_data->temp_detObj.frame != parsed_data->detObj_data.at(parsed_data->detObj_data.size()-2).frame){
                    //if(parsed_data->detObj_data.at(parsed_data->detObj_data.size()).frame != parsed_data->detObj_data.at(parsed_data->detObj_data.size()-1).frame){
                    //The last item of detObj_data is from new frame it have to be removed and
                    //implemented to the new data frame. After second row is detObj_data cleare and appendet for last solved item
                    //Solved in section below.
                    parsed_data->detObj_data.pop_back();
                    parsed_data->frame_data.push_back(parsed_data->detObj_data);
                    parsed_data->detObj_data.clear();   //This invoke exit code 3 for debuger for feedback of processed data use DataOperation::to_CSV()
                    parsed_data->detObj_data.push_back(parsed_data->temp_detObj);
                }
            }
            break;
        default:
            qDebug() << "It give data_pos out of index";
            break;
    }

}

void DataOperation::to_CSV(ParsedData *parDat){
    QFile file("C:/Users/bob/Documents/GitHub/RadarVisualizer/tst/outFile.csv");
    QTextStream outFile(&file);
    file.open(QIODevice::ReadWrite |QIODevice::Append);
    for(int i=0;i<(int)parDat->frame_data.size();i++){
        for(int j=0;j<(int)parDat->frame_data[i].size();j++){
            outFile << parDat->frame_data[i][j].frame << ","
                    << parDat->frame_data[i][j].detObj << ","
                    << parDat->frame_data[i][j].posX << ","
                    << parDat->frame_data[i][j].posY << ","
                    << parDat->frame_data[i][j].speed << ","
                    << parDat->frame_data[i][j].snr << ","
                    << parDat->frame_data[i][j].noise << ",\n";
        }
    }
    file.close();
}

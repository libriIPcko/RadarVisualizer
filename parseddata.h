#ifndef PARSEDDATA_H
#define PARSEDDATA_H

#include <QObject>
#include <QString>
#include <deque>
#include <vector>

class ParsedData : QObject
{
    Q_OBJECT
public:
    ParsedData();
    struct parsed_data_struct{
        int frame;
        int detObj;
        float posX;
        float posY;
        float posZ;
        float speed;
        int snr;
        int noise;

    }temporary;

    struct detObj{
        int frame;
        int detObj;
        float posX;
        float posY;
        float posZ;
        float speed;
        int snr;
        int noise;
        int group;
    }temp_detObj;

    //std::deque<parsed_data_struct> frame_data;
    std::vector<detObj> detObj_data;
    std::vector<std::vector<detObj>> frame_data;

    //For Data Unification
    std::vector<std::vector<std::vector<int>>> unified_Points;
    //std::vector<std::vector<parsed_data_struct>> group;
    //std::vector<std::vector<parsed_data_struct>> outside_group;
};

#endif // PARSEDDATA_H

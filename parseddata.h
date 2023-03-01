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
    };

    std::deque<parsed_data_struct> frame_data;
};

#endif // PARSEDDATA_H

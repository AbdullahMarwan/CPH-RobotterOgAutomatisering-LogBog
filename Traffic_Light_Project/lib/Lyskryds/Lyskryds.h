#ifndef LYSKRYDS_H
#define LYSKRYDS_H

#include <Arduino.h>

class Lyskryds
{
public:
    Lyskryds(int redPin1, int yellowPin1, int greenPin1, int redPin2, int yellowPin2, int greenPin2);
    void setup();
    void update(long now);

private:
    int _redPin1, _yellowPin1, _greenPin1;
    int _redPin2, _yellowPin2, _greenPin2;

    unsigned long _nextChange = 0;
    int _state = 0;

    const long _pStateTime[11] = {
        3000, // RED
        2000, // RED_YELLOW
        3000, // GREEN
        2000, // YELLOW
        3000, // GREEN_YELLOW
        2000, // YELLOW_RED
        2000, // YELLOW_GREEN
        3000,
        2000,
        3000,
        2000,
    };

    void updateLights();
};

#endif
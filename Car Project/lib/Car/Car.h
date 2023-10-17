#ifndef CAR_H
#define CAR_H

#include <Arduino.h>

class Car {
public:
    Car(int m1EN, int m1A, int m1B, int m2EN, int m2A, int m2B);
    void setup();
    void moveForward();
    void moveBackward();
    void stop();

private:
    int motor1EN;
    int motor1A;
    int motor1B;
    int motor2EN;
    int motor2A;
    int motor2B;
};

#endif

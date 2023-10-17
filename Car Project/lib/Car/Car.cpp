#include "Car.h"

Car::Car(int m1EN, int m1A, int m1B, int m2EN, int m2A, int m2B) {
    motor1EN = m1EN;
    motor1A = m1A;
    motor1B = m1B;
    motor2EN = m2EN;
    motor2A = m2A;
    motor2B = m2B;
}

void Car::setup() {
    pinMode(motor1EN, OUTPUT);
    pinMode(motor1A, OUTPUT);
    pinMode(motor1B, OUTPUT);
    pinMode(motor2EN, OUTPUT);
    pinMode(motor2A, OUTPUT);
    pinMode(motor2B, OUTPUT);
    stop();
}

void Car::moveForward() {
    digitalWrite(motor1EN, HIGH);
    digitalWrite(motor1A, HIGH);
    digitalWrite(motor1B, LOW);
    
    digitalWrite(motor2EN, HIGH);
    digitalWrite(motor2A, HIGH);
    digitalWrite(motor2B, LOW);
}

void Car::moveBackward() {
    digitalWrite(motor1EN, HIGH);
    digitalWrite(motor1A, LOW);
    digitalWrite(motor1B, HIGH);
    
    digitalWrite(motor2EN, HIGH);
    digitalWrite(motor2A, LOW);
    digitalWrite(motor2B, HIGH);
}

void Car::stop() {
    digitalWrite(motor1EN, LOW);
    digitalWrite(motor1A, LOW);
    digitalWrite(motor1B, LOW);
    
    digitalWrite(motor2EN, LOW);
    digitalWrite(motor2A, LOW);
    digitalWrite(motor2B, LOW);
}

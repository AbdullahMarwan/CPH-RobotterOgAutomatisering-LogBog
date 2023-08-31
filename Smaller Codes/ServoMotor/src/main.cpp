#include <Servo.h>
#include <Arduino.h>

Servo myservo;
int val;

void setup()
{
  myservo.attach(D1);
}

void loop()
{
  val = analogRead(A0);
  val = map(val, 0, 1023, 0, 180);
  myservo.write(val);
  delay(15);
}
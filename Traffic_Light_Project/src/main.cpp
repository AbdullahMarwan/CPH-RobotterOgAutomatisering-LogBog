#include <Arduino.h>

const int redPin = D0;
const int yellowPin = D1;
const int greenPin = D2;

unsigned long previousMillis = 0;
const long intervalRed = 3000;       // Rød lysperiode
const long intervalGreen = 3000;     // Grøn lysperiode
const long intervalYellow = 2000;    // Gul lysperiode
const long intervalRedYellow = 2000; // Rød/gul lysperiode

enum TrafficState
{
  RED,
  RED_YELLOW,
  GREEN,
  YELLOW,
  GREEN_YELLOW,
  YELLOW_RED,
  YELLOW_GREEN,
};

TrafficState currentState = RED;
unsigned long stateInterval = intervalRed;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
}

void loop()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= stateInterval)
  {
    previousMillis = currentMillis;

    switch (currentState)
    {
    case RED:
      currentState = RED_YELLOW;
      stateInterval = intervalRedYellow;
      digitalWrite(redPin, HIGH);
      break;

    case RED_YELLOW:
      currentState = GREEN;
      stateInterval = intervalGreen;
      digitalWrite(redPin, HIGH);
      digitalWrite(yellowPin, HIGH);
      break;

    case GREEN:
      currentState = GREEN_YELLOW;
      stateInterval = intervalYellow;
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, LOW);
      digitalWrite(greenPin, HIGH);
      break;

    case GREEN_YELLOW:
      currentState = YELLOW;
      stateInterval = intervalYellow;
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, HIGH);
      break;

    case YELLOW:
      currentState = YELLOW_RED;
      stateInterval = intervalRed;
      digitalWrite(yellowPin, LOW);
      break;

    case YELLOW_RED:
      currentState = RED;
      stateInterval = intervalRed;
      digitalWrite(redPin, HIGH);
      digitalWrite(yellowPin, HIGH);
      break;

    case YELLOW_GREEN:
      currentState = RED;
      stateInterval = intervalRed;
      digitalWrite(yellowPin, LOW);
      break;
    }
  }
}
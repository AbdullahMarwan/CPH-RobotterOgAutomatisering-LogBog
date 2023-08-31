#include "Lyskryds.h"

Lyskryds::Lyskryds(int redPin1, int yellowPin1, int greenPin1, int redPin2, int yellowPin2, int greenPin2)
    : _redPin1(redPin1), _yellowPin1(yellowPin1), _greenPin1(greenPin1),
      _redPin2(redPin2), _yellowPin2(yellowPin2), _greenPin2(greenPin2) {}

void Lyskryds::setup()
{
    pinMode(_redPin1, OUTPUT);
    pinMode(_yellowPin1, OUTPUT);
    pinMode(_greenPin1, OUTPUT);
    pinMode(_redPin2, OUTPUT);
    pinMode(_yellowPin2, OUTPUT);
    pinMode(_greenPin2, OUTPUT);
}

void Lyskryds::update(long now)
{
    if (now < _nextChange)
        return;

    _state = (_state + 1) % 11;
    updateLights();

    _nextChange += _pStateTime[_state];
}

void Lyskryds::updateLights()
{
    switch (_state)
    {
    case 1:
        digitalWrite(_redPin1, HIGH);
        digitalWrite(_yellowPin1, LOW);
        digitalWrite(_greenPin1, LOW);
        digitalWrite(_redPin2, LOW);
        digitalWrite(_yellowPin2, LOW);
        digitalWrite(_greenPin2, HIGH);
        break;

    case 2:
        digitalWrite(_redPin1, HIGH);
        digitalWrite(_yellowPin1, LOW);
        digitalWrite(_greenPin1, LOW);
        digitalWrite(_redPin2, LOW);
        digitalWrite(_yellowPin2, HIGH);
        digitalWrite(_greenPin2, LOW);
        break;

    case 3:
        digitalWrite(_redPin1, HIGH);
        digitalWrite(_yellowPin1, LOW);
        digitalWrite(_greenPin1, LOW);
        digitalWrite(_redPin2, HIGH);
        digitalWrite(_yellowPin2, HIGH);
        digitalWrite(_greenPin2, LOW);
        break;
    case 4:
        digitalWrite(_redPin1, HIGH);
        digitalWrite(_yellowPin1, LOW);
        digitalWrite(_greenPin1, LOW);
        digitalWrite(_redPin2, HIGH);
        digitalWrite(_yellowPin2, LOW);
        digitalWrite(_greenPin2, LOW);
        break;

    case 5:
        digitalWrite(_redPin1, LOW);
        digitalWrite(_yellowPin1, HIGH);
        digitalWrite(_greenPin1, LOW);
        digitalWrite(_redPin2, HIGH);
        digitalWrite(_yellowPin2, LOW);
        digitalWrite(_greenPin2, LOW);
        break;

    case 6:
        digitalWrite(_redPin1, LOW);
        digitalWrite(_yellowPin1, LOW);
        digitalWrite(_greenPin1, HIGH);
        digitalWrite(_redPin2, HIGH);
        digitalWrite(_yellowPin2, LOW);
        digitalWrite(_greenPin2, LOW);
        break;

    case 7:
        digitalWrite(_redPin1, LOW);
        digitalWrite(_yellowPin1, HIGH);
        digitalWrite(_greenPin1, LOW);
        digitalWrite(_redPin2, HIGH);
        digitalWrite(_yellowPin2, LOW);
        digitalWrite(_greenPin2, LOW);
        break;

    case 8:
        digitalWrite(_redPin1, HIGH);
        digitalWrite(_yellowPin1, HIGH);
        digitalWrite(_greenPin1, LOW);
        digitalWrite(_redPin2, HIGH);
        digitalWrite(_yellowPin2, LOW);
        digitalWrite(_greenPin2, LOW);
        break;

    case 9:
        digitalWrite(_redPin1, HIGH);
        digitalWrite(_yellowPin1, LOW);
        digitalWrite(_greenPin1, LOW);
        digitalWrite(_redPin2, HIGH);
        digitalWrite(_yellowPin2, LOW);
        digitalWrite(_greenPin2, LOW);
        break;

    case 10:
        digitalWrite(_redPin1, HIGH);
        digitalWrite(_yellowPin1, LOW);
        digitalWrite(_greenPin1, LOW);
        digitalWrite(_redPin2, LOW);
        digitalWrite(_yellowPin2, HIGH);
        digitalWrite(_greenPin2, LOW);
        break;

    case 11:
        digitalWrite(_redPin1, HIGH);
        digitalWrite(_yellowPin1, LOW);
        digitalWrite(_greenPin1, LOW);
        digitalWrite(_redPin2, LOW);
        digitalWrite(_yellowPin2, LOW);
        digitalWrite(_greenPin2, HIGH);
        break;
    }
}
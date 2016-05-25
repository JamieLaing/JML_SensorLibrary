// 
// 
// 

#include "GenericSensor.h"

GenericSensor::GenericSensor(int activationPin, int readingPin)
{
	_readingPin = readingPin;
	_activationPin = activationPin;
}

void GenericSensor::activate() {
	pinMode(_activationPin, OUTPUT);
	digitalWrite(_activationPin, HIGH);
}

void GenericSensor::deactivate() {
	pinMode(_activationPin, OUTPUT);
	digitalWrite(_activationPin, LOW);
}

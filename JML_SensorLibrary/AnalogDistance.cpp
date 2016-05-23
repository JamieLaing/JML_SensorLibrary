// 
// 
// 

#include "AnalogDistance.h"

AnalogDistance::AnalogDistance(int activationPin, int readingPin)
{
	_readingPin = readingPin;
	_activationPin = activationPin;
}

void AnalogDistance::activate() {
	pinMode(_activationPin, OUTPUT);
	digitalWrite(_activationPin, HIGH);
}

void AnalogDistance::deactivate() {
	pinMode(_activationPin, OUTPUT);
	digitalWrite(_activationPin, LOW);
}

double AnalogDistance::readDistance() {
	int irValue = analogRead(_readingPin);
	double irDistance = 187754 * pow(irValue, -1.51);
	return irDistance;
}


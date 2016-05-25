// 
// 
// 

#include "AnalogDistance.h"

AnalogDistance::AnalogDistance(int activationPin, int readingPin)
	: GenericSensor(activationPin, readingPin) {}

double AnalogDistance::readDistance() {
	int irValue = analogRead(_readingPin);
	double irDistance = 187754 * pow(irValue, -1.51);
	return irDistance;
}


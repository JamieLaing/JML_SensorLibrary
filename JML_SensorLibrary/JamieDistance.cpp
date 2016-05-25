// 
// 
// 

#include "JamieDistance.h"

JamieDistance::JamieDistance(int activationPin, int readingPin)
	: GenericSensor(activationPin, readingPin) {}

double JamieDistance::readDistance() {
	int irValue = analogRead(_readingPin);
	double irDistance = 187754 * pow(irValue, -1.51);
	return irDistance;
}


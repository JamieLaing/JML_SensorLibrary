// 
// 
// 


#include "JamieDistance.h"

double JamieDistance::readDistance() {
	int irValue = analogRead(_readingPin);
	double irDistance = 187754 * pow(irValue, -1.51);
	return irDistance;
}

JamieDistance::JamieDistance(int activationPin, int readingPin)
	: GenericSensor(activationPin, readingPin) {}
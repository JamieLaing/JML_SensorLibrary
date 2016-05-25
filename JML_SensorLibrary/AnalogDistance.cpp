// 
// 
// 

#include "AnalogDistance.h"

AnalogDistance::AnalogDistance(int activationPin, int readingPin)
	: DistanceSensor(activationPin, readingPin) {}

double AnalogDistance::readDistance() {
	int irValue = analogRead(_readingPin);
	double irDistance = 187754 * pow(irValue, -1.51);
	return irDistance;
}


// 
// 
// 

#include "BinaryDistance.h"

BinaryDistance::BinaryDistance(int activationPin, int readingPin) 
	:DistanceSensor(activationPin, readingPin) {}

boolean BinaryDistance::objectDetected() {
	boolean reading = false;
	int irValue = analogRead(_readingPin);
	if (irValue < 500)
	{
		reading = true;
	}
	return reading;
}

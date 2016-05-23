// 
// 
// 

#include "BinaryDistance.h"

BinaryDistance::BinaryDistance(int activationPin, int readingPin) {
	_readingPin = readingPin;
	_activationPin = activationPin;
}

void BinaryDistance::activate() {
	pinMode(_activationPin, OUTPUT);
	digitalWrite(_activationPin, HIGH);
}

void BinaryDistance::deactivate() {
	pinMode(_activationPin, OUTPUT);
	digitalWrite(_activationPin, LOW);
}

boolean BinaryDistance::objectDetected() {
	boolean reading = false;
	int irValue = analogRead(_readingPin);
	if (irValue < 500)
	{
		reading = true;
	}
	return reading;
}

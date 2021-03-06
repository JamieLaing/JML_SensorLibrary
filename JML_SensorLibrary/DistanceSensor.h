// DistanceSensor.h

#ifndef _DISTANCESENSOR_h
#define _DISTANCESENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

class DistanceSensor {
public:
	int _readingPin;
	int _activationPin;
public:
	inline virtual void activate();
	inline virtual void deactivate();
	DistanceSensor(int activationPin, int readingPin);
};
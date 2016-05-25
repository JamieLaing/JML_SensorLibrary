// GenericSensor.h

#ifndef _GENERICSENSOR_h
#define _GENERICSENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

class GenericSensor {
public:
	int _readingPin;
	int _activationPin;
public:
	inline virtual void activate();
	inline virtual void deactivate();
	GenericSensor(int activationPin, int readingPin);
};
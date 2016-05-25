// JamieDistance.h

#ifndef _JAMIEDISTANCE_h
#define _JAMIEDISTANCE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "GenericSensor.h"

class JamieDistance: public GenericSensor {
public:
	double readDistance();
	JamieDistance(int activationPin, int readingPin);
};

#endif


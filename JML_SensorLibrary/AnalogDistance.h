// AnalogDistance.h

#ifndef _ANALOGDISTANCE_h
#define _ANALOGDISTANCE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#ifndef _DISTANCESENSOR_h
#include "DistanceSensor.h"
#endif // !_DISTANCESENSOR_h

class AnalogDistance: public DistanceSensor {
public:
	AnalogDistance(int activationPin, int readingPin);
	double readDistance();
};

#endif


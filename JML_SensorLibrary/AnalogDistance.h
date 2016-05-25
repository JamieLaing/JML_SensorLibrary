// AnalogDistance.h

#ifndef _ANALOGDISTANCE_h
#define _ANALOGDISTANCE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#ifndef _GENERICSENSOR_h
#include "GenericSensor.h"
#endif // !_GENERICSENSOR_h

class AnalogDistance: public GenericSensor {
public:
	AnalogDistance(int activationPin, int readingPin);
	double readDistance();
};

#endif


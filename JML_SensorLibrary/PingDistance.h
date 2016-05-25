// PingDistance.h

#ifndef _PINGDISTANCE_h
#define _PINGDISTANCE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#ifndef _GENERICSENSOR_h
#include "GenericSensor.h"
#endif // !_GENERICSENSOR_h

class PingDistance : public GenericSensor {
public:
	PingDistance(int activationPin, int readingPin);
	float readDistance();
};

#endif


// JamieDistance.h

#ifndef _JAMIEDISTANCE_h
#define _JAMIEDISTANCE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#ifndef _GENERICSENSOR_h
#include "GenericSensor.h"
#endif // !_GENERICSENSOR_h


class JamieDistance: public GenericSensor {
public:
	JamieDistance(int activationPin, int readingPin);
	double readDistance();
	
};

#endif


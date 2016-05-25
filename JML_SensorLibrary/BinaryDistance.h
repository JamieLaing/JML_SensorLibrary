// BinaryDistance.h

#ifndef _BINARYDISTANCE_h
#define _BINARYDISTANCE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#ifndef _DISTANCESENSOR_h
#include "DistanceSensor.h"
#endif // !_DISTANCESENSOR_h

class BinaryDistance: public DistanceSensor {
public:
	BinaryDistance(int activationPin, int readingPin);
	boolean objectDetected();
};

#endif


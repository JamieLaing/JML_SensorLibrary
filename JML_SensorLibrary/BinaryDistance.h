// BinaryDistance.h

#ifndef _BINARYDISTANCE_h
#define _BINARYDISTANCE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#ifndef _GENERICSENSOR_h
#include "GenericSensor.h"
#endif // !_GENERICSENSOR_h

class BinaryDistance: public GenericSensor {
public:
	BinaryDistance(int activationPin, int readingPin);
	boolean objectDetected();
};

#endif


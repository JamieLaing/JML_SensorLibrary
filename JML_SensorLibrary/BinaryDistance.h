// BinaryDistance.h

#ifndef _BINARYDISTANCE_h
#define _BINARYDISTANCE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class BinaryDistance {
private:
	int _readingPin;
	int _activationPin;
public:
	void activate();
	void deactivate();
	BinaryDistance(int activationPin, int readingPin);
	boolean objectDetected();
};

#endif


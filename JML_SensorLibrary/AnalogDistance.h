// AnalogDistance.h

#ifndef _ANALOGDISTANCE_h
#define _ANALOGDISTANCE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class AnalogDistance {
private:
	int _readingPin;
	int _activationPin;
public:
	void activate();
	void deactivate();
	AnalogDistance(int activationPin, int readingPin);
	double readDistance();
};

#endif


// pca9635.h
//Taken from https://github.com/rambo/pca9635

#ifndef _PCA9635_h
#define _PCA9635_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

// Stub extension for now
class pca9635 : public i2c_device
{
public:
	pca9635(); // We need this so we can set default address to the all-call one for the PCA9635 instance

	void begin(byte dev_addr, boolean wire_begin);
	void begin(byte dev_addr, boolean wire_begin, boolean init); // Variant to allow skipiing init (needed by the RGB board)
	boolean set_led_mode(byte ledno, byte mode);
	boolean set_led_mode(byte mode); // Variant to set all leds to same mode
	boolean set_led_pwm(byte ledno, byte cycle);
	boolean set_driver_mode(byte mode);
	boolean set_sleep(byte sleep);
	boolean enable_subaddr(byte addr);
	boolean reset(); // NOTE: This resets all PCA9635 devices on the bus
	byte autoincrement_bits;
};

extern pca9635 PCA9635;

#endif
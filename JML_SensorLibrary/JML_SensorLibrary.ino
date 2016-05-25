/*
 Name:		JML_SensorLibrary.ino
 Created:	5/19/2016 9:07:36 AM
 Author:	jlaing
 Editor:	http://www.visualmicro.com
*/


#include "PingDistance.h"
#include "Adafruit_Sensor.h"
#include "Adafruit_LSM9DS0.h"
#include "AnalogDistance.h"
#include "BinaryDistance.h"
#include <i2c.h>
#include <i2c_device.h>
#include <pca9635.h>
#include <Encoder.h>

byte intUnitID;
const byte enc1A = 2;
const byte enc1B = 3;
const byte pinButton = 5;
const byte pinSpeaker = 11;
const byte pinLED = 13;
const byte enc2A = 19;
const byte enc2B = 18;
const byte mtr1In2 = 22;
const byte mtr2In2 = 23;
const byte mtr1In1 = 24;
const byte mtr2In1 = 25;
const byte mtr1Enable = 44;
const byte mtr2Enable = 45;
const byte vs1053_miso = 50;
const byte vs1053_mosi = 51;
const byte vs1053_clk = 52;
const byte vs1053_dcs = 8;
const byte vs1053_reset = 9;
const byte vs1053_cs = 10;
const byte vs1053_dreq = 12;
const byte card_cs = 4;
const byte ampGain0 = 37;
const byte ampGain1 = 40;
const byte ampActivate = 41;  //Bring this pin low to activate amplifier
const byte pingPingFront = 6;
const byte pinActPingFront = 7;
const byte pinEdge1 = A0;
const byte pinActEdge1 = 27;
const byte pinEdge2 = A1;
const byte pinActEdge2 = 31;
const byte pinBatt = A2;
const byte pinPerim1 = A4;
const byte pinActPerim1 = 26;
const byte pinPerim2 = A5;
const byte pinActPerim2 = 28;
const byte pinPerim3 = A6;
const byte pinActPerim3 = 30;
const byte pinPerim4 = A7;
const byte pinActPerim4 = 32;
const byte pinFrntIr = A8;
const byte pinActFrntIR = 29;
const long WallTooNear = 30;  //Too near for saftey, in cm
const float fltDistAccThresh = 0.30;  //Distance Accuracy Threshold

Encoder motor1Enc(enc1A, enc1B);
Encoder motor2Enc(enc2A, enc2B);
long Mtr1OldPos = -999;
long Mtr2OldPos = -999;
int buttonState;
int lastButtonState = LOW;
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 10;
boolean blnCliffLeft = false;
boolean blnCliffRight = false;
boolean blnCliffDetected = false;
boolean blnObjectLeft = false;
boolean blnObjectRight = false;
boolean blnObjectDetected = false;
boolean blnMotorsOff = true;
boolean blnAutonomous = false;
boolean blnPlayerExists = false;

Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0();

BinaryDistance edgeLeft = BinaryDistance(pinActEdge1, pinEdge1);
BinaryDistance edgeRight = BinaryDistance(pinActEdge2, pinEdge2);
AnalogDistance perim1IR = AnalogDistance(pinActPerim1, pinPerim1);
AnalogDistance perim2IR = AnalogDistance(pinActPerim2, pinPerim2);
AnalogDistance frontIR = AnalogDistance(pinActFrntIR, pinFrntIr);
AnalogDistance perim3IR = AnalogDistance(pinActPerim3, pinPerim3);
AnalogDistance perim4IR = AnalogDistance(pinActPerim4, pinPerim4);
PingDistance frontPing = PingDistance(pinActPingFront, pingPingFront);



void setup() {
	if (!lsm.begin())
	{
		Serial.println("Oops ... unable to initialize the LSM9DS0. Check your wiring!");
	}
	else
	{
		setupIMU();
		Serial.println(F("LSM9DSO configured."));
	}

	edgeLeft.activate();
	perim1IR.activate();
	perim2IR.activate();
	frontIR.activate();
	perim3IR.activate();
	perim4IR.activate();
	edgeRight.activate();
}

// the loop function runs over and over again until power down or reset
void loop() {

	encoderReport();
	lsm.read();
	Serial.print("Accel X: "); Serial.print((int)lsm.accelData.x); Serial.print(" ");
	Serial.print("Y: "); Serial.print((int)lsm.accelData.y);       Serial.print(" ");
	Serial.print("Z: "); Serial.println((int)lsm.accelData.z);     Serial.print(" ");
	Serial.print("Mag X: "); Serial.print((int)lsm.magData.x);     Serial.print(" ");
	Serial.print("Y: "); Serial.print((int)lsm.magData.y);         Serial.print(" ");
	Serial.print("Z: "); Serial.println((int)lsm.magData.z);       Serial.print(" ");
	Serial.print("Gyro X: "); Serial.print((int)lsm.gyroData.x);   Serial.print(" ");
	Serial.print("Y: "); Serial.print((int)lsm.gyroData.y);        Serial.print(" ");
	Serial.print("Z: "); Serial.println((int)lsm.gyroData.z);      Serial.print(" ");
	Serial.print("Temp: "); Serial.print((int)lsm.temperature);    Serial.println(" ");
	Serial.println("");
	Serial.print("Edge left:");
	Serial.println(edgeLeft.objectDetected());
	Serial.print("Edge right:");
	Serial.println(edgeRight.objectDetected());
	Serial.print("Perimeter1IR: ");
	Serial.println(perim1IR.readDistance());
	Serial.print("Perimeter2IR: ");
	Serial.println(perim2IR.readDistance());
	Serial.print("FrontIR: ");
	Serial.println(frontIR.readDistance());
	Serial.print("Perimeter3IR: ");
	Serial.println(perim3IR.readDistance());
	Serial.print("Perimeter4IR: ");
	Serial.println(perim4IR.readDistance());
	Serial.print("Front Ping: ");
	Serial.println(frontPing.readDistance());
	/*Serial.print("Jamie1: ");
	Serial.println(jamie1.readDistance());*/
	Serial.println("");
	delay(1500);
  
}

void setupIMU()
{
	// 1.) Set the accelerometer range
	lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_2G);
	//lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_4G);
	//lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_6G);
	//lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_8G);
	//lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_16G);

	// 2.) Set the magnetometer sensitivity
	lsm.setupMag(lsm.LSM9DS0_MAGGAIN_2GAUSS);
	//lsm.setupMag(lsm.LSM9DS0_MAGGAIN_4GAUSS);
	//lsm.setupMag(lsm.LSM9DS0_MAGGAIN_8GAUSS);
	//lsm.setupMag(lsm.LSM9DS0_MAGGAIN_12GAUSS);

	// 3.) Setup the gyroscope
	lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_245DPS);
	//lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_500DPS);
	//lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_2000DPS);
}

void encoderReport() {
	long Mtr1NewPos = motor1Enc.read();
	if (Mtr1NewPos != Mtr1OldPos) {
		Mtr1OldPos = Mtr1NewPos;
		Serial.print("Motor1:");
		Serial.println(Mtr1NewPos);
	}
	long Mtr2NewPos = motor2Enc.read();
	if (Mtr2NewPos != Mtr2OldPos) {
		Mtr2OldPos = Mtr2NewPos;
		Serial.print("Motor2:");
		Serial.println(Mtr2NewPos);
	}
}

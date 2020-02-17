/*
  L298N_LE.h - Lombardi Engineering library for utilizing L298N motor drivers.
  Created by Joseph Lombardi 1/24/2020
  Released into the public domain.
*/

#ifndef LD298N_h
#define LD298N_h

#include "Arduino.h"

class L298N_LE 
{
  public:
    L298N_LE(int pwmPin, int in1Pin, int in2Pin);
    void drive(int value);
    void brake();
    void invert();
	void setDeadzone(int zone);
    int lastValue();
    
  private:
    int _pwmPin;
    int _in1Pin;
    int _in2Pin;
    int _value;
	int _deadzone;
	boolean _inverted = false;
};

#endif

/*
  L298N_LE.h - Lombardi Engineering Library for utilizing L298N motor drivers.
  Created by Joseph Lombardi 1/24/2020
  Released into the public domain.
*/

#include "Arduino.h"
#include "L298N_LE.h"

L298N_LE::L298N_LE(int pwmPin, int in1Pin, int in2Pin)
{
  analogWrite(pwmPin, 0);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  _pwmPin = pwmPin;
  _in1Pin = in1Pin;
  _in2Pin = in2Pin;
  _value = 0;
  _deadzone = 5;
}

void L298N_LE::drive(int value) //drive function takes in an int from 0 to 255 for drive speed. 127 would be 0. 
{
  _value = value;
  int val = _value;

  val = map(value, 0, 255, -255, 255); //pay careful attention to what is received as the drive value.
  val = constrain(val, -255, 255);
  boolean dir = _inverted;

  if ((abs(val) - _deadzone) < 0) {
	  val = 0;
  }

  if (val < 0) { //if the drive value is negative, invert normal direction and apply power.
	  dir = !_inverted; //invert direction
	  val = abs(val); //apply power (absolute value of drive power)
  }

  digitalWrite(_in1Pin, dir); //these two pins must be inverse for the h-bridge to function.
  digitalWrite(_in2Pin, !dir); //thus, they are always the value and (not)value
  analogWrite(_pwmPin, val); //pwm output

}

void L298N_LE::brake()
{
  analogWrite(_pwmPin,0);
  digitalWrite(_in1Pin, HIGH);
  digitalWrite(_in2Pin, HIGH);
}

void L298N_LE::invert(){
  _inverted = !_inverted;
}

int L298N_LE::lastValue()
{
  return _value;
}

void L298N_LE::setDeadzone(int zone) {
	_deadzone = zone;
}
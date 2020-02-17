/* Example sketch for L298N driver
 */

#include <L298N_LE.h>

#define pwmPin 6
#define in1 7
#define in2 8

//instantiate L298N object, with pwm pin and direction pins
L298N_LE motor(pwmPin, in1, in2);


void setup() {
  motor.invert(); //method to invert forward/backward directions
  motor.setDeadzone(10);
}

void loop() {
  
  int x = 1;

  //for loop will sweep through backward and forward motion
  for(int i = 1; i > 0; i = i + x){
    
    motor.drive(i); //drive method takes 0-255, 127 being no power
    
    if(i > 254){
      x = -1;
    }

    delay(10);
    
  }
  
}
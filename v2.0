/*
 * Easing
 * Pato
 * July 12, 2017
 *
 * Move a servo with easing (smooth)
 * 
  * Easing functions based on Robert Penner's work,
 * for more info see Easing.h or Easing.cpp
 */


#include <Servo.h>
int target;
int origin;

/* here you can change to any other type of easing from Easing.h */

float easeInOutQuad (float t, float b, float c, float d)
{
if ((t/=d/2) < 1) return c/2*t*t + b;
  return -c/2 * ((--t)*(t-2) - 1) + b;
}

Servo myServo; //create servo object

void setup(){
  myServo.attach(9); //attach servo at pin 8
  myServo.write(15);  //put servo at 165 degrees
  }

void loop(){
  moveServo(40);  /* the number inside represents the 'target' */
delay(150);
  moveServo(135);
 delay(150);
}

void moveServo(int target){
  origin = target;
  int dur = 100; //duration is 100 loops
  for (int pos=0; pos<dur; pos++){
    myServo.write(easeInOutQuad(pos, origin,target-origin , dur));
    delay(15); //wait for the servo to move
  }
   delay(1000);
 
}

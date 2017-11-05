/*
 * Easing
 * Tobias Toft <hello@tobiastoft.dk>
 * July 27, 2009
 *
 * Moves a servo motor back and forth between 0 and 140 degrees
 * when a button is pressed.
 *
 * This example is using the Servo.h library that comes
 * with the Arduino IDE.
 *
 * Easing functions based on Robert Penner's work,
 * for more info see Easing.h or Easing.cpp
 */

#include <Servo.h>
int pri;
int sec;

float easeInOutQuad (float t, float b, float c, float d)
{
  if ((t/=d/2) < 1) return c/2*t*t + b;
  return -c/2 * ((--t)*(t-2) - 1) + b;
}

Servo myServo; //create servo object


void setup(){
  myServo.attach(8); //attach servo at pin 9
  myServo.write(80);  //put servo at 0 degrees
  }

void loop(){
  pri=80;
  sec=170;
  moveServo();
  pri=170;
  sec=80;
  moveServo();
  delay(1500);
  
  
  
}

void moveServo(){
  int dur = 100; //duration is 100 loops
  for (int pos=0; pos<dur; pos++){
    //move servo from 0 and 140 degrees forward
    myServo.write(easeInOutQuad(pos, pri,sec-pri , dur));
    delay(15); //wait for the servo to move
  }
  
  delay(1000); //wait a second, then move back using "bounce" easing
  
 
 
}

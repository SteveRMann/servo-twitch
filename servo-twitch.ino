#include <Servo.h>

Servo myservo;
boolean state;

void setup()
{
  myservo.attach(D1);
}


void loop()
{ 
  state = random(2);
  if (state) myservo.write(90);   //open
  else myservo.write(0);          //close
  delay(random(200, 800));
}
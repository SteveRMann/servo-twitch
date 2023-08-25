#include <Servo.h>

Servo myservo;
boolean state;

void setup()
{
  myservo.attach(D1);
  for (int i = 0; i < 3; i++) {
    myservo.write(110);         //open
    delay(500);
    myservo.write(0);          //close
    delay(500);
  }
  delay(1000);
}


void loop()
{
  state = random(2);
  if (state) myservo.write(130);   //open
  else myservo.write(0);          //close
  delay(random(200, 800));
}

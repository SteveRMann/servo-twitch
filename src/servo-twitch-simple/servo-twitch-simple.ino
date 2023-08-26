#include <Servo.h>

Servo myservo;
boolean state;
const int UP = 75;
const int DOWN = 140;


void setup()
{
  myservo.attach(2);            //GPIO2
  //NOTE- Wemos D1, disconnect servo from GPIO2 to flash.

  for (int i = 0; i < 3; i++) {
    myservo.write(DOWN);
    delay(500);
    myservo.write(UP);
    delay(500);
  }
  myservo.write(DOWN);
  delay(1000);
}


void loop()
{
  state = random(2);
  if (state) myservo.write(DOWN);
  else myservo.write(UP);
  delay(random(200, 800));
}

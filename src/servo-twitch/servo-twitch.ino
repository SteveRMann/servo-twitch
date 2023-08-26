#define SKETCH "servo-twitch"
#define VERSION "2.0"

#include <ArduinoOTA.h>
#include <Servo.h>
Servo myservo;

//--------------- WiFi declarations ---------------
// WiFi declarations
#include <Kaywinnet.h>          // WiFi credentials
char macBuffer[24];             // Holds the last three digits of the MAC, in hex.
char hostName[24];              // Holds nodeName + the last three bytes of the MAC address.
char nodeName[] = SKETCH;       // Give this node a name


boolean state;
const int UP = 0;
const int DOWN = 120;

void setup()
{
  myservo.attach(2);            //GPIO2
  //NOTE- On Wemos D1 Mini, disconnect servo from GPIO2 to flash.


  beginSerial();
  setup_wifi();
  start_OTA();

  //Twitch three times
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
  ArduinoOTA.handle();
  state = random(2);
  if (state) myservo.write(DOWN);
  else myservo.write(UP);
  delay(random(200, 800));
}

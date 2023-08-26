// -------------- beginSerial() --------------
void beginSerial() {
  while (!Serial);
  Serial.begin( 115200 );
  Serial.println();
  Serial.println();
  Serial.print(SKETCH);
  Serial.print(".ino, Version ");
  Serial.println(VERSION);
  Serial.println(F("++++++++++++++++++ +"));
}

// --------------- Function to display a string for debugging. ---------------
void dbugs(const char *s, const char *v) {
  //Show a string variable. Enter with the string description and the string.
  //Example dbugs("My String= ",myString);
  Serial.print(s);
  Serial.print (F("\""));
  Serial.print(v);
  Serial.println(F("\""));
}

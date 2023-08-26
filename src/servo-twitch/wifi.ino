// setup_wifi
// ============================= Connect the ESP to the router =============================
// Connect to WiFi network so we can reach the MQTT broker and publish messages to topics.

void setup_wifi() {
#ifndef Kaywinnet
#include <Kaywinnet.h>            // Network credentials
#endif
  byte mac[6];                    // The MAC address of your Wifi

  Serial.println(F("\n"));
  Serial.print(F("Connecting to "));
  Serial.println(MY_SSID);
  dbugs("Connecting to ", MY_SSID);

  WiFi.mode(WIFI_STA);
  //WiFi.enableInsecureWEP();
  WiFi.begin(MY_SSID, MY_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(WiFi.status()); Serial.print(F(" "));
    delay(500);
  }

  Serial.println(F("\nWiFi connected, "));
  Serial.print(F("MAC Address: "));
  Serial.println(WiFi.macAddress());
  Serial.print(F("IP address: "));
  Serial.println(WiFi.localIP());
  Serial.print(F("RSSI: "));
  Serial.println(WiFi.RSSI());
  Serial.println();


  // Get the last three numbers of the mac address.
  // "4C:11:AE:0D:83:86" becomes "0D8386" in macBuffer.
  WiFi.macAddress(mac);
  snprintf(macBuffer, sizeof(macBuffer), "%02X%02X%02X", mac[3], mac[4], mac[5]);

  // Build hostName from prefix + last three bytes of the MAC address.
  strcpy(hostName, nodeName);
  strcat(hostName, "-");
  strcat(hostName, macBuffer);
  WiFi.hostname(hostName);
  dbugs("hostName= ", hostName);

}

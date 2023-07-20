#include <WiFi.h>
#include "esp_camera.h"
#include "esp_system.h"

#include <TridentTD_LineNotify.h>
#define SSID        "Mars"   //WiFi name
#define PASSWORD    "22302376"   //PASSWORD
#define LINE_TOKEN  "phwOxpPtj0pqcgLchS7ip8T9uwKRA575efCyJnOaQQN"   

void setup() {
  Serial.begin(115200);
   while (!Serial) {  ;  }

  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  while(WiFi.status() != WL_CONNECTED) { Serial.print("."); delay(400); }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());  
  LINE.setToken(LINE_TOKEN);
}
void loop() {
  line_send("Hello");
  delay(1000);
}

void line_send(String str)
{
  String data = "Patrick:" + str;
  LINE.notify("\n" + data);
}

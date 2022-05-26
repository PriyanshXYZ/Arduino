#include <dummy.h>

#include "esp_camera.h"
#include <WiFi.h>
#include "camera_pins.h"

//#define CAMERA_MODEL_WROVER_KIT
//#define CAMERA_MODEL_ESP_EYE
//#define CAMERA_MODEL_M5STACK_PSRAM
//#define CAMERA_MODEL_M5STACK_WIDE
#define CAMERA_MODEL_AI_THINKER
 
const char* WIFI_SSID = "Priyansh Laptop";
const char* WIFI_PASS = "12345678";

#define relay 4
long prevMillis = 0;
int interval = 5000;

void setup() {
  Serial.begin(115200);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);
}
void loop() { 
    if (matchFace == true && activeRelay == false){
      activeRelay = true;
      digitalWrite (relay, HIGH);
      prevMillis = millis();
    }
    if(activeRelay == true && millis()- prevMillis > interval){
      activeRelay = false;
      matchFace = false;
      digitalWrite(relay, LOW);
    }
}

/*
  GSN CREATIONS - Naan Sonathum OLED Animation Player
  ESP32 + 0.96" SSD1306 128x64 OLED

  OLED connections:
  VCC -> 3.3V
  GND -> GND
  SDA -> GPIO 21
  SCL -> GPIO 22
  I2C address -> 0x3C

  Required libraries:
  Adafruit GFX Library
  Adafruit SSD1306
*/
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "NaanSonathum_Animation.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_SDA 21
#define OLED_SCL 22
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup(){
  Serial.begin(115200);
  Wire.begin(OLED_SDA, OLED_SCL);
  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)){
    while(true){ delay(1000); }
  }
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(22,20); display.println("GSN CREATIONS");
  display.setCursor(25,38); display.println("OLED PLAYER");
  display.display();
  delay(1000);
}

void loop(){
  for(uint16_t frame=0; frame<NAANSONATHUM_FRAME_COUNT; frame++){
    display.clearDisplay();
    display.drawBitmap(0,0,NaanSonathum_frames[frame],SCREEN_WIDTH,SCREEN_HEIGHT,SSD1306_WHITE);
    display.display();
    delay(NaanSonathum_delays[frame]);
  }
}

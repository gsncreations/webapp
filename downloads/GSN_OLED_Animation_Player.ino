/*
===========================================================
 GSN CREATIONS
 VIDEO TO OLED ANIMATION PLAYER
 ESP32 + 0.96" SSD1306 OLED
===========================================================

 OLED:
 VCC -> 3.3V
 GND -> GND
 SDA -> GPIO 21
 SCL -> GPIO 22

 OLED ADDRESS:
 0x3C

 REQUIRED LIBRARIES:
 Adafruit GFX Library
 Adafruit SSD1306

 FILE REQUIRED:
 animation.h

 Put animation.h in the SAME folder as this .ino file.

===========================================================
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "animation.h"


// =========================================================
// OLED SETTINGS
// =========================================================

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_SDA 21
#define OLED_SCL 22

#define OLED_ADDRESS 0x3C


// =========================================================
// OLED OBJECT
// =========================================================

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  -1
);


// =========================================================
// SETUP
// =========================================================

void setup()
{
  // Start Serial
  Serial.begin(115200);

  delay(500);

  Serial.println();
  Serial.println("================================");
  Serial.println("       GSN CREATIONS");
  Serial.println("    OLED ANIMATION PLAYER");
  Serial.println("================================");


  // =======================================================
  // START I2C
  // =======================================================

  Wire.begin(
    OLED_SDA,
    OLED_SCL
  );


  // =======================================================
  // START OLED
  // =======================================================

  if (!display.begin(
        SSD1306_SWITCHCAPVCC,
        OLED_ADDRESS
      ))
  {
    Serial.println("ERROR!");
    Serial.println("OLED NOT FOUND!");

    while (true)
    {
      delay(1000);
    }
  }


  // =======================================================
  // STARTUP SCREEN
  // =======================================================

  display.clearDisplay();

  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(1);

  display.setCursor(22, 20);
  display.println("GSN CREATIONS");

  display.setCursor(25, 38);
  display.println("OLED PLAYER");

  display.display();

  delay(1500);


  // =======================================================
  // SERIAL INFORMATION
  // =======================================================

  Serial.println();
  Serial.println("OLED FOUND!");
  Serial.println();

  Serial.print("OLED Width  : ");
  Serial.println(SCREEN_WIDTH);

  Serial.print("OLED Height : ");
  Serial.println(SCREEN_HEIGHT);

  Serial.print("Frame Count : ");
  Serial.println(ANIMATION_FRAME_COUNT);

  Serial.println();

  Serial.println("Animation started...");
  Serial.println();
}


// =========================================================
// LOOP
// =========================================================

void loop()
{

  // =======================================================
  // PLAY ALL FRAMES
  // =======================================================

  for (
    uint16_t frame = 0;
    frame < ANIMATION_FRAME_COUNT;
    frame++
  )
  {

    // =====================================================
    // CLEAR OLED
    // =====================================================

    display.clearDisplay();


    // =====================================================
    // DRAW CURRENT FRAME
    // =====================================================

    display.drawBitmap(
      0,
      0,
      animation_frames[frame],
      SCREEN_WIDTH,
      SCREEN_HEIGHT,
      SSD1306_WHITE
    );


    // =====================================================
    // SHOW FRAME
    // =====================================================

    display.display();


    // =====================================================
    // WAIT FOR NEXT FRAME
    // =====================================================

    delay(
      animation_delays[frame]
    );
  }

  // After the last frame,
  // loop() automatically starts again.
}
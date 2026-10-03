GSN CREATIONS - Naan Sonathum OLED Animation

Resolution: 128 x 64
Frame count: 230
Default frame delay: 100 ms
Board example: ESP32
Display: SSD1306 0.96 inch I2C OLED

FILES
- NaanSonathum_Animation.h : animation frame data
- NaanSonathum_Animation.ino : ESP32 player sketch
- preview.png : preview image

WIRING
OLED VCC -> ESP32 3.3V
OLED GND -> GND
OLED SDA -> GPIO 21
OLED SCL -> GPIO 22
OLED I2C address -> 0x3C

INSTALL
1. Install Adafruit GFX Library and Adafruit SSD1306.
2. Keep the .h and .ino in the same Arduino sketch folder.
3. Open the .ino in Arduino IDE.
4. Select your ESP32 board and port.
5. Upload.

NOTE
This package is provided as a ready-to-use OLED animation example.

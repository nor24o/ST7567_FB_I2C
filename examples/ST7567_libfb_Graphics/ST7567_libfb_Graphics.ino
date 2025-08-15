#include <Wire.h>
#include "ST7567_FB_I2C.h"


// ---- PIN DEFINITIONS ----
// The only pin you need for the I2C version is the RESET pin.
// Connect SCL to A5 and SDA to A4 on an Arduino Uno.
#define RST_PIN 255
// I2C pins (adjust based on your board)
#define I2C_SDA 9
#define I2C_SCL 8
// ---- I2C ADDRESS ----
// The I2C address for these displays is often 0x3F or 0x3C.
// Use an I2C scanner sketch if you are unsure.
#define I2C_ADDR 0x3F

// Create an instance of the library
ST7567_FB_I2C lcd(RST_PIN, I2C_ADDR);

void setup() 
{
   Wire.setPins(I2C_SDA, I2C_SCL);
  Serial.begin(9600);
  Serial.println("ST7567 I2C Test");
  Wire.begin();
  // Initialize the display. You can optionally pass a contrast value from 0-31.
  lcd.init(3);
  lcd.cls();
  lcd.drawRectD(0,0,SCR_WD,SCR_HT,1);

  int x=16,y=10;
  lcd.drawRect(x+8,y-5,20,20,1);
  lcd.fillRect(x+8+30,y-5,20,20,1);
  lcd.fillRectD(x+8+60,y-5,20,20,1);

  lcd.drawCircle(x+5+12,48,y,1);
  lcd.fillCircle(x+5+30+12,y+36,12,1);
  lcd.fillCircleD(x+5+60+12,y+36,12,1);

  lcd.display();
}

void loop() 
{
}


# ST7567_FB_I2C
I2C graphics library for ST7567 128x64 LCD with frame buffer.



## Features

- proportional fonts support built-in (requires fonts from PropFonts library https://github.com/cbm80amiga/PropFonts)
- simple primitives
  - pixels
  - lines
  - rectangles
  - filled rectangles
  - circles
  - filled circles
  - triangles
  - filled triangles
- fast ordered dithering (17 patterns)
- ultra fast horizontal and vertical line drawing
- bitmaps drawing
- example programs

## Connections:


|LCD pin|LCD pin name|Arduino,ESP32|
|--|--|--|
 |#01| SDA| A4, 9|
 |#02| SCL| A5,6|
 |#08| GND| GND|
 |#07| 3V3| VCC (3.3V)|
 
Tested on ESP32-S3

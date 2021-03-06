//Experiment of 3.5 Inch LCD (320x480), ILI9488 SPI Interface driver
//Adafruit ILI9341 library is modified for ILI9488 (320x480)
// The Height and Width parameters at Adafruit_ILI9341.h file must be modified to
// #define ILI9341_TFTWIDTH 320
// #define ILI9341_TFTHEIGHT 480
//
// And at the Adafruit_ILI9341.cpp file, at the function Adafruit_ILI9341::begin(void), 
// the following lines muct be modified for adapting ILI9488 device (320x480 pixels).
// writecommand(ILI9341_DFUNCTR); // Display Function Control
// writedata(0x02);
// writedata(0x02);
// writedata(0x3B);

// LCD MOSI to Arduino digital IO D11
// LCD SCLK to Arduino digital IO D13
// LCD CS to Arduino digital IO D10
// LCD RS / DS to Arduino digital IO D9

// https://www.instructables.com/Arduino-and-35-Inch-320x480-TFT-LCD-ILI9488-SPI-In/

//Include Libraries
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

// For the LCD shield, these are the default.
#define TFT_DC 9
#define TFT_CS 10

// Initialize LCD
// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

//Arduino setup
void setup() 
{
	Serial.begin(115200);
 	Serial.println("ILI9341 Test!"); 
	Serial.println("DHT22 temperature / humidity sensor Test");
  
	//Initialize TFT LCD
	tft.begin();

	//Rotate the screen to right direction
	tft.setRotation(1);

	//Print the headers
	printHeader();
}

//Main loop
void loop(void) 
{ 
}

//Print headers
unsigned long printHeader(void )
{
  tft.fillRect(0,0,240, 64,ILI9341_GREEN);
  tft.fillRect(0,64,240, 64,ILI9341_RED);
  tft.fillRect(0,128,240, 64,ILI9341_CYAN);
  tft.fillRect(0,192,240, 64,ILI9341_YELLOW);
  tft.fillRect(0,256,240, 64,ILI9341_ORANGE);

  unsigned long start = micros();
  tft.setTextColor(ILI9341_BLACK);   
  tft.setTextSize(3);
  //
  tft.setCursor(50,0+20);
  tft.print("CELCIUS");

  //
  tft.setCursor(50,64+20);
  tft.print("FAHRENHEIT");
  //
  tft.setCursor(50,128+20);
  tft.print("KELVIN");

    //
  tft.setCursor(50,192+20);
  tft.print("RANKIN");

   //
  tft.setCursor(50,256+20);
  tft.print("HUMIDITY");
  
  return micros() - start;    
}


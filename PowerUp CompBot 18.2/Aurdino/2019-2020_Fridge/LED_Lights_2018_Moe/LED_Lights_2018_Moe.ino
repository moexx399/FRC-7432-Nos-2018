

// Include Files
#include <Adafruit_NeoPixel.h>
#include "LED_Functions.h"

// Macro definitions
#define D_STRIP_1_PIN   2   //Left LED Strip
#define D_STRIP_2_PIN   4    //Front LED Strip
#define D_STRIP_3_PIN   6   //Right LED Strip

#define D_PIXEL_CNT_1  28
#define D_BUFF_SIZE     4
int counter = 0;
// Constructors
Adafruit_NeoPixel strip_1 = Adafruit_NeoPixel(28, D_STRIP_1_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_2 = Adafruit_NeoPixel(D_PIXEL_CNT_1, D_STRIP_2_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_3 = Adafruit_NeoPixel(28, D_STRIP_3_PIN, NEO_GRB + NEO_KHZ800);

// Functions

// Initialization
void setup()
{


  initStrip (&strip_1);     //Left LED Strip
  initStrip (&strip_2);     //Front LED Strip
  initStrip (&strip_3);     //Right LED Strip
} // End setup()

// Main Loop
void loop() {

  theaterChaseRainbow_All(&strip_1, &strip_3, 250);
  theaterChaseRainbow_All(&strip_2, &strip_2, 250);
} // End switch

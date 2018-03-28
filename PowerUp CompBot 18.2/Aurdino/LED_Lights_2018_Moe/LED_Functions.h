

// Type Definitions

typedef enum 
 {
  E_RED,
  E_GREEN,
  E_YELLOW,
  E_BLUE,
  E_ORANGE,
  E_WHITE,
  E_PURPLE,
  E_TEAL,
  E_CHLOESFAVORITECOLOR,
  E_OFF,
  E_1,
  E_DARK_CYAN
}E_LedColor_t;

// Functions Definitions

//*****************************************************************
// Initialize LED strip 
//*****************************************************************
void initStrip (Adafruit_NeoPixel *StripNum);

//*****************************************************************
// Get requested color code
//*****************************************************************
uint32_t getColor(Adafruit_NeoPixel *StripNum, E_LedColor_t Color);

//*****************************************************************
// Set color of each pixel, then turn on all pixels in the strip
//*****************************************************************
void setColor(Adafruit_NeoPixel *StripNum, E_LedColor_t Color);

//*****************************************************************
// Set set even number LEDs color1, and odd number LEDs color2
//*****************************************************************
void setColor2(Adafruit_NeoPixel *StripNum, E_LedColor_t Color1, E_LedColor_t Color2);

//*****************************************************************
// Set three different LED colors
//*****************************************************************
void setColor3(Adafruit_NeoPixel *StripNum, E_LedColor_t Color1, E_LedColor_t Color2, E_LedColor_t Color3);

//*****************************************************************
//  Set three different LED colors
//*****************************************************************
void setColor4(Adafruit_NeoPixel *StripNum, E_LedColor_t Color1, E_LedColor_t Color2, E_LedColor_t Color3, E_LedColor_t Color4);

//*****************************************************************
// Illuminate pixels one after the other with requested color
//*****************************************************************
void wipeColor(Adafruit_NeoPixel *StripNum, E_LedColor_t Color, uint16_t wait_mS);

// ****************************************************************
//Theatre-style crawling lights or requested color.
// ****************************************************************
void theaterChase(Adafruit_NeoPixel *StripNum, E_LedColor_t c, uint8_t wait);
void theaterChase_All(Adafruit_NeoPixel *StripNum_1, Adafruit_NeoPixel *StripNum_2, uint8_t wait);
// ****************************************************************
//Theatre-style crawling lights, rainbow pattern. MultiStrip
// ****************************************************************
void theaterChaseRainbow_All(Adafruit_NeoPixel *StripNum_1, Adafruit_NeoPixel *StripNum_2, uint16_t wait_mS);

// ****************************************************************
//Blink LED Strip requested color on & off 
// ****************************************************************
void blinkColor(Adafruit_NeoPixel *StripNum, E_LedColor_t Color, uint16_t blink_mS);

//****************************************************************
//Blink all LED Strips requested color on & off 
//****************************************************************
void blinkColor_All(Adafruit_NeoPixel *StripNum_1,Adafruit_NeoPixel *StripNum_2, E_LedColor_t Color, uint16_t blink_mS);

void trackingEye(Adafruit_NeoPixel *StripNum, E_LedColor_t c, uint8_t wait, int &counter);

void RunningLights(Adafruit_NeoPixel *StripNum, Adafruit_NeoPixel *StripNum2, Adafruit_NeoPixel *StripNum3, int pixle_Count, byte red, byte green, byte blue, int WaveDelay);




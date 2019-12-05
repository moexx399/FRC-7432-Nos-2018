// Include Files
#include "Arduino.h"
#include <Adafruit_NeoPixel.h>
#include "LED_Functions.h"

// LED Functions
uint32_t Wheel(Adafruit_NeoPixel *StripNum, byte WheelPos);

//*****************************************************************
// Initialize LED strip 
//*****************************************************************
void initStrip (Adafruit_NeoPixel *StripNum)
{
  StripNum->begin();
  StripNum->show(); // Initialize all pixels to 'off'
  StripNum->setBrightness(50);
} // End initStrip()


//*****************************************************************
// Get requested color code
//*****************************************************************
uint32_t getColor(Adafruit_NeoPixel *StripNum, E_LedColor_t Color)
{
    uint32_t Color_Code;
    
    switch (Color)
    {
      case E_RED:  
        Color_Code = StripNum->Color(255, 0, 0);
        break;
      
      case E_GREEN:  
        Color_Code = StripNum->Color(0, 255, 0);
        break;
      
      case E_BLUE:  
        Color_Code = StripNum->Color(0, 0, 255);
        break;

      case E_TEAL:
        Color_Code = StripNum->Color(0, 51,51);
        break;

      case E_CHLOESFAVORITECOLOR:
        Color_Code=StripNum->Color (255, 102,102);
        break;
      
      case E_YELLOW:  
        Color_Code = StripNum->Color(200, 100, 0);
        break;
           
      case E_ORANGE:  
        Color_Code = StripNum->Color(255, 64, 0);
        break;

      case E_WHITE:
        Color_Code = StripNum->Color(255,255,255);
        break;

      case E_PURPLE:
        Color_Code = StripNum->Color(76,0,153);
        break;

      case E_DARK_CYAN:
        Color_Code = StripNum->Color(0,51,51);
        break;
           
      case E_OFF:  
        Color_Code = StripNum->Color(0,0,0);
        break;

      case E_1:
        Color_Code = StripNum->Color(100,100,100);
        break;
      
      default:  
        break;
    }

  return Color_Code;
} // End getColor()

//*****************************************************************
// Set color of each pixel, then turn on all pixels in the strip
//*****************************************************************
void setColor(Adafruit_NeoPixel *StripNum, E_LedColor_t Color)
{ 
  uint32_t Color_Rqst;
   
  Color_Rqst = getColor(StripNum, Color);
      
  for(uint16_t i=0; i < StripNum->numPixels(); i++) 
  {
     StripNum->setPixelColor(i, Color_Rqst);
  } 
  
  StripNum->show();  
} // End setColor()

//*****************************************************************
// Set set even number LEDs color1, and odd number LEDs color2
//*****************************************************************
void setColor2(Adafruit_NeoPixel *StripNum, E_LedColor_t Color1, E_LedColor_t Color2)
{ 
  uint32_t Color_Rqst1;
  uint32_t Color_Rqst2;
   
  Color_Rqst1 = getColor(StripNum, Color1);
  Color_Rqst2 = getColor(StripNum, Color2);
  
      
  for(uint16_t i=0; i < StripNum->numPixels(); i++) 
  {
      if((i%2) == 0)
      {
        StripNum->setPixelColor(i, Color_Rqst1);
      }
      else
      {
        StripNum->setPixelColor(i, Color_Rqst2);
      }
  }
  
  StripNum->show();  
}

//*****************************************************************
// Set 3 led colors
//*****************************************************************
void setColor4(Adafruit_NeoPixel *StripNum, E_LedColor_t Color1, E_LedColor_t Color2, E_LedColor_t Color3, E_LedColor_t Color4)
{  
  uint32_t Color_Rqst1;
  uint32_t Color_Rqst2;
  uint32_t Color_Rqst3;
  uint32_t Color_Rqst4;
  uint32_t LED_Cmd;
 
  Color_Rqst1 = getColor(StripNum, Color1);
  Color_Rqst2 = getColor(StripNum, Color2);
  Color_Rqst3 = getColor(StripNum, Color3);
  Color_Rqst4 = getColor(StripNum, Color4);
      
  for(uint16_t i=0; i < StripNum->numPixels(); i++)
  { 
    LED_Cmd = i%4;
    switch (LED_Cmd)
   {
    case (0):
       StripNum->setPixelColor(i, Color_Rqst1);
       break;
    case (1):
      StripNum->setPixelColor(i, Color_Rqst2);
      break;
          
    case (2):
      StripNum->setPixelColor(i, Color_Rqst3);
      break;

      case (3):
      StripNum-> setPixelColor (i, Color_Rqst4);
      break;
    default:
      break;  
    } // end switch
      
  } // end for
  
  StripNum->show();  
}

//*****************************************************************
// Illuminate pixels one after the other with requested color
//*****************************************************************
void wipeColor(Adafruit_NeoPixel *StripNum, E_LedColor_t Color, uint16_t wait_mS) 
{
  uint32_t c = getColor(StripNum, Color);
  uint32_t n = StripNum->numPixels();
  
  setColor(StripNum, E_OFF);
  
  for(uint16_t i=0; i < n; i++) 
  {
      StripNum->setPixelColor(i, c);
      StripNum->show();
      delay(wait_mS);
  }
} // End wipeColor()

//Theatre-style crawling lights.
void theaterChase(Adafruit_NeoPixel *StripNum, E_LedColor_t Color, uint8_t wait) 
{
  uint32_t Color_Rqst;
  uint16_t i, j, q;
  uint8_t num;
   
  for ( j=0; j<10; j++) 
  {  //do 10 cycles of chasing
    for ( q=0; q < 3; q++) 
    {
      for ( i=0; i < StripNum->numPixels(); i=i+3)
      {

        num = (q%3);
        
        switch(num)
        {
          case (0):     
            Color = E_RED;
            break;
            
          case (1):
            Color = E_WHITE;
            break;
            
          case(2):
            Color = E_BLUE;
            break;
            
          default:
            break;
        }
        
        Color_Rqst = getColor(StripNum, Color);
        StripNum->setPixelColor(i+q, Color_Rqst);    //turn every third pixel on
      }
        StripNum->show();

      delay(wait);

      for ( i=0; i < StripNum->numPixels(); i=i+3) 
      {
        StripNum->setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

   //Theatre-style crawling lights.
void theaterChase_All(Adafruit_NeoPixel *StripNum_1, Adafruit_NeoPixel*StripNum_2, uint8_t wait)
{
  uint32_t Color_Rqst_1;
  uint32_t Color_Rqst_2;
  
  uint16_t i, j, q;
  uint8_t num;
  E_LedColor_t Color;

  
  for ( j=0; j<1; j++) 
  {  //do 3 cycles of chasing
    for ( q=0; q < 3; q++) 
    {
      for ( i=0; i < StripNum_1->numPixels(); i=i+3)
          

      {

        num = (q%3);
        
        switch(num)
        {
          case (0):     
            Color = E_RED;
            break;
            
          case (1):
            Color = E_GREEN;
            break;
            
          case(2):
            Color = E_BLUE;
            break;
            
          default:
            break;
        }
        
        Color_Rqst_1 = getColor(StripNum_1, Color);
        Color_Rqst_2 = getColor(StripNum_2, Color);
        StripNum_1->setPixelColor(i+q, Color_Rqst_1);
        StripNum_2->setPixelColor(i+q, Color_Rqst_2);
      }
        StripNum_1->show();
        StripNum_2->show();

      delay(wait);

      for ( i=0; i < StripNum_1->numPixels(); i=i+3)
        
      {
        StripNum_1->setPixelColor(i+q, 0); 
        StripNum_2->setPixelColor(i+q, 0); //turn every third pixel off
      }
    }
  }
}
void theaterChaseRainbow_All(Adafruit_NeoPixel *StripNum_1, Adafruit_NeoPixel *StripNum_2, uint16_t wait_mS) 
{
  uint16_t i, j, q;
  uint32_t Color_Rqst1;
  uint32_t Color_Rqst2;

  E_LedColor_t Color;
  
  for (j=0; j < 256; j++) 
  {     // cycle all 256 colors in the wheel
    for (q=0; q < 3; q++) 
    {
        for (i=0; i < StripNum_1->numPixels(); i=i+3) 
        {
          StripNum_1->setPixelColor(i+q, Wheel(StripNum_1, (i+j) % 255)); 
          StripNum_2->setPixelColor(i+q, Wheel(StripNum_2, (i+j) % 255));//turn every third pixel on
        }
        StripNum_1->show();
        StripNum_2->show();
       
        delay(wait_mS);
       
        for (i=0; i < StripNum_1->numPixels(); i=i+3) 
        {
          StripNum_1->setPixelColor(i+q, 0);
          StripNum_2->setPixelColor(i+q, 0);//turn every third pixel off
        }
    }
  }
}

      
//Blink LED Strip requsted color on & off
void blinkColor(Adafruit_NeoPixel *StripNum, E_LedColor_t Color, uint16_t blink_mS)
{
  static int ledState = LOW;
  static unsigned long previous_mS =0;
  unsigned long current_mS;
  uint32_t Color_Rqst;

  current_mS = millis();
  
  if ((current_mS -previous_mS) >= blink_mS)
  {
    if(ledState == LOW)
    {
      ledState = HIGH;
      Color_Rqst = getColor (StripNum, Color);
    }
    else
    {
      ledState = LOW;
      Color_Rqst = getColor(StripNum, E_OFF);
    }
    
    for(uint16_t i=0; i<StripNum-> numPixels(); i ++)
    {
       StripNum->setPixelColor (i, Color_Rqst);  
    }
    
    StripNum->show();
    previous_mS =current_mS;
  }
}

//Blink LED Strip requsted color on & off
void blinkColor_All(Adafruit_NeoPixel *StripNum_1,Adafruit_NeoPixel *StripNum_2, E_LedColor_t Color, uint16_t blink_mS)
{
  static int ledState = LOW;
  static unsigned long previous_mS =0;
  unsigned long current_mS;
  
  uint32_t Color_Rqst1;
  uint32_t Color_Rqst2;

  current_mS = millis();
  
  if ((current_mS -previous_mS) >= blink_mS)
  {
    if(ledState == LOW)
    {
      ledState = HIGH;
      Color_Rqst1 = getColor(StripNum_1, Color);
      Color_Rqst2 = getColor(StripNum_2, Color);
    }
    else
    {
      ledState = LOW;
      Color_Rqst1 = getColor(StripNum_1, E_OFF);
      Color_Rqst2 = getColor(StripNum_2, E_OFF);
    }
    
    for(uint16_t i=0; i< StripNum_1-> numPixels(); i ++)
    {
       StripNum_1->setPixelColor (i, Color_Rqst1); 
       StripNum_2->setPixelColor (i, Color_Rqst2); 
    }
    
    StripNum_1->show();
    StripNum_2->show();
    
    previous_mS =current_mS;
  }
}
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(Adafruit_NeoPixel *StripNum, byte WheelPos) 
{
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) 
  {
   return StripNum->Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  else if(WheelPos < 170) 
  {
    WheelPos -= 85;
   return StripNum->Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } 
  else 
  {
   WheelPos -= 170;
   return StripNum->Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}

void trackingEye(Adafruit_NeoPixel *StripNum, E_LedColor_t c, uint8_t wait, int &counter) {
uint32_t Color_Rqst;
setColor(StripNum, E_OFF);
E_LedColor_t Color;
int x;

if (counter == 44)
  counter = 0;
else if (counter < 22)
  x = counter;
else 
 x = 44 - counter;   
    
  if (x < 23){ 
    Color = E_RED;
    Color_Rqst = getColor(StripNum, Color);
    StripNum->setPixelColor(x+4, Color_Rqst);
    StripNum->setPixelColor(x+3, Color_Rqst);
    StripNum->setPixelColor(x+2, Color_Rqst);
    StripNum->setPixelColor(x+1, Color_Rqst);
    StripNum->setPixelColor(x, Color_Rqst);
    Color = E_OFF;
    Color_Rqst = getColor(StripNum, Color);
    StripNum->setPixelColor(x-1, Color_Rqst);

    Color = E_RED;
    Color_Rqst = getColor(StripNum, Color);
     StripNum->setPixelColor(51-x+4, Color_Rqst);
    StripNum->setPixelColor(51-x+3, Color_Rqst);
    StripNum->setPixelColor(51-x+2, Color_Rqst);
    StripNum->setPixelColor(51-x+1, Color_Rqst);
    StripNum->setPixelColor(51-x, Color_Rqst);
    Color = E_OFF;
    Color_Rqst = getColor(StripNum, Color);
    StripNum->setPixelColor(51-x-1, Color_Rqst);}
  
  else {
    Color_Rqst = getColor(StripNum, c);
    Color = E_RED;
    Color_Rqst = getColor(StripNum, Color);
    StripNum->setPixelColor(x-4, Color_Rqst);
    StripNum->setPixelColor(x-3, Color_Rqst);
    StripNum->setPixelColor(x-2, Color_Rqst);
    StripNum->setPixelColor(x-1, Color_Rqst);
    StripNum->setPixelColor(x, Color_Rqst);
    Color = E_OFF;
    Color_Rqst = getColor(StripNum, Color);
    StripNum->setPixelColor(x+1,Color_Rqst );

    Color_Rqst = getColor(StripNum, c);
    Color = E_RED;
    Color_Rqst = getColor(StripNum, Color);
    StripNum->setPixelColor(51-x-4, Color_Rqst);
    StripNum->setPixelColor(51-x-3, Color_Rqst);
    StripNum->setPixelColor(51-x-2, Color_Rqst);
    StripNum->setPixelColor(51-x-1, Color_Rqst);
    StripNum->setPixelColor(51-x, Color_Rqst);
    Color = E_OFF;
    Color_Rqst = getColor(StripNum, Color);
    StripNum->setPixelColor(51-x+1,Color_Rqst );}
    
  counter++;
  StripNum->show();
  delay(wait);
  
  
}

//climb case to 0
// boot up to 7

void RunningLights(Adafruit_NeoPixel *StripNum, Adafruit_NeoPixel *StripNum2, Adafruit_NeoPixel *StripNum3, int pixle_Count, byte red, byte green, byte blue, int WaveDelay) {
  int Position=0;
  
  for(int i=0; i< pixle_Count*2; i++)
  {
      Position++; // = 0; //Position + Rate;
      for(int i=0; i< pixle_Count; i++) {
        // sine wave, 3 offset waves make a rainbow!
        //float level = sin(i+Position) * 127 + 128;
        //setPixel(i,level,0,0);
        //float level = sin(i+Position) * 127 + 128;
        StripNum->setPixelColor(i,((sin(i+Position) * 127 + 128)/255)*red,
                               ((sin(i+Position) * 127 + 128)/255)*green,
                               ((sin(i+Position) * 127 + 128)/255)*blue);
        
        StripNum2->setPixelColor(i,((sin(i+Position) * 127 + 128)/255)*red,
                               ((sin(i+Position) * 127 + 128)/255)*green,
                               ((sin(i+Position) * 127 + 128)/255)*blue);
        
        StripNum3->setPixelColor(i,((sin(i+Position) * 127 + 128)/255)*red,
                               ((sin(i+Position) * 127 + 128)/255)*green,
                               ((sin(i+Position) * 127 + 128)/255)*blue);
      }
      
      StripNum->show();
      StripNum2->show();
      StripNum3->show();
      delay(WaveDelay);
  }
}
 



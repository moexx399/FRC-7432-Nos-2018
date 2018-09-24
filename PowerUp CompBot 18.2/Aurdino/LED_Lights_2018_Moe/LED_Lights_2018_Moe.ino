// Include Files 
#include <Adafruit_NeoPixel.h>
#include "LED_Functions.h"

// Macro definitions 
#define D_STRIP_1_PIN   5   //Left LED Strip
#define D_STRIP_2_PIN   3    //Front LED Strip
#define D_STRIP_3_PIN   7   //Right LED Strip

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
  Serial.println("3026 PowerUP");
  Serial.begin(9600,SERIAL_8N1); 
  Serial1.begin(9600,SERIAL_8N1);
pinMode(11, INPUT);
pinMode(12, INPUT);
pinMode(13, INPUT);
pinMode(NULL, INPUT); //Left Limit Switch
pinMode(NULL, INPUT); //Right Limit Switch
  initStrip (&strip_1);     //Left LED Strip
  initStrip (&strip_2);     //Front LED Strip
  initStrip (&strip_3);     //Right LED Strip
} // End setup()

// Main Loop
void loop() {
int sum = 0;
if(digitalRead(11))
   sum = sum + 1;
if(digitalRead(12))
   sum = sum + 2;
if(digitalRead(13))
   sum = sum + 4;
   
  switch (sum) {  //LED DRIVE MODE
    case (1):
      Serial.println("CLIMB");
      setColor(&strip_3, E_WHITE);
      setColor(&strip_2, E_WHITE);
      setColor(&strip_1, E_WHITE); 
      break;
      
    case (0):
     Serial.println("Robot Centric");
     
//     if (digitalRead()||digitalRead(12)) { 
//        if(digitalRead(11)&&(!digitalRead(12))) { 
//        Serial.println("11");
//        blinkColor(&strip_1, E_BLUE, 250);
//        setColor(&strip_2, E_BLUE);
//        setColor(&strip_3, E_BLUE);}
//        else if(digitalRead(12)&&(!digitalRead(11))){
//        Serial.println("12");
//        setColor(&strip_1, E_BLUE);
//        setColor(&strip_2, E_BLUE);
//        blinkColor(&strip_3, E_BLUE, 250);}
//        else {
//          Serial.println("Both");
//        blinkColor(&strip_1, E_BLUE, 250);
//        setColor(&strip_2, E_BLUE);
//        blinkColor(&strip_3, E_BLUE, 250);}
//        }
//     else {
      setColor(&strip_1, E_BLUE);
      setColor(&strip_3, E_BLUE);
      setColor(&strip_2, E_BLUE);
//      }
      
     break;
        
    case (2):
      Serial.println("Field Centric");
      
//     if (digitalRead(11)||digitalRead(12)) { 
//        if(digitalRead(11)&&(!digitalRead(12))) { 
//        blinkColor(&strip_1, E_GREEN, 250);
//        setColor(&strip_2, E_GREEN);
//        setColor(&strip_3, E_GREEN);}
//        else if(digitalRead(12)&&(!digitalRead(11))){
//        setColor(&strip_1, E_GREEN);
//        setColor(&strip_2, E_GREEN);
//        blinkColor(&strip_3, E_GREEN, 250);}
//        else {
//        blinkColor(&strip_1, E_GREEN, 250);
//        setColor(&strip_2, E_GREEN);
//        blinkColor(&strip_3, E_GREEN, 250);}
//        }
//     else {
      setColor(&strip_1, E_GREEN);
      setColor(&strip_3, E_GREEN);
      setColor(&strip_2, E_GREEN);
//      }     
      break;
          
    case (3):
      Serial.println("Tracks Down");
      trackingEye(&strip_2, E_RED, 50, counter);

//       if (digitalRead(11)||digitalRead(12)) { 
//        if(digitalRead(11)&&(!digitalRead(12))) { 
//        blinkColor(&strip_1, E_RED, 250);
//        setColor(&strip_3, E_RED);}
//        else if(digitalRead(12)&&(!digitalRead(11))){
//        setColor(&strip_1, E_RED);
//        blinkColor(&strip_3, E_RED, 250);}
//        else {
//        blinkColor(&strip_1, E_RED, 250);
//        blinkColor(&strip_3, E_RED, 250);}
//        }
//     else {
      setColor(&strip_1, E_RED);
      setColor(&strip_3, E_RED);
//      } 
      break;

   case (4):
      Serial.println("NULL");
      
//     if (digitalRead(11)||digitalRead(12)) { 
//        if(digitalRead(11)&&(!digitalRead(12))) { 
//        blinkColor(&strip_1, E_ORANGE, 250);
//        setColor(&strip_2, E_ORANGE);
//        setColor(&strip_3, E_ORANGE);}
//        else if(digitalRead(12)&&(!digitalRead(11))){
//        setColor(&strip_1, E_ORANGE);
//        setColor(&strip_2, E_ORANGE);
//        blinkColor(&strip_3, E_ORANGE, 250);}
//        else {
//        blinkColor(&strip_1, E_ORANGE, 250);
//        setColor(&strip_2, E_ORANGE);
//        blinkColor(&strip_3, E_ORANGE, 250);}
//        }
//     else {
      setColor(&strip_1, E_ORANGE);
      setColor(&strip_2, E_ORANGE);
      setColor(&strip_3, E_ORANGE);
//      }
      break;

   case (5):
      Serial.println("NULL");
      setColor(&strip_2, E_PURPLE);
     
     if (digitalRead(11)||digitalRead(12)) { 
        if(digitalRead(11)&&(!digitalRead(12))) { 
        blinkColor(&strip_1, E_PURPLE, 250);
        setColor(&strip_2, E_PURPLE);
        setColor(&strip_3, E_PURPLE);}
        else if(digitalRead(12)&&(!digitalRead(11))){
        setColor(&strip_1, E_PURPLE);
        setColor(&strip_2, E_PURPLE);
        blinkColor(&strip_3, E_PURPLE, 250);}
        else {
        blinkColor(&strip_1, E_PURPLE, 250);
        setColor(&strip_2, E_PURPLE);
        blinkColor(&strip_3, E_PURPLE, 250);}
        }
     else {
      setColor(&strip_1, E_PURPLE);
      setColor(&strip_3, E_PURPLE);
      }     
      break;

   case(6):
      Serial.println("Robot Idle Presentation");
      theaterChaseRainbow_All(&strip_1,&strip_3,250);
      theaterChaseRainbow_All(&strip_2, &strip_2, 250);   
      break;
      
   case(7):
      Serial.println("START_UP");
//      if(digitalRead(4))
      RunningLights(&strip_1, &strip_2, &strip_3, 58 , 255, 0, 0, 50);
//      else
//      RunningLights(&strip_1, &strip_2, &strip_3, 58 , 0, 0, 255, 50);
      break;

   default:
      Serial.println("Default"); 
      break; 

        Serial.println(digitalRead(4));
  } } // End switch

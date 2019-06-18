#include <FastLED.h>

#define NUM_LEDS 9
#define LED_PIN 2

int button = 4;
int pressed = 0;
bool start = true;
bool lastClick = false;
int index = -1;
int arrLength = 4;

////////timer to store time between button presses, coolDown to control how often button can be pressed/////
int timer = 0;
int coolDown = 15;

///function prototypes and pointer declaration//

///setBlue///
void setBlue();
void (*bluePtr)() = setBlue;

///set red///
void setRed();
void (*redPtr)() = setRed;

///setGreen///
void setGreen();
void (*greenPtr)() = setGreen;

///startAnimation///
void startAnim();
void (*startPtr)() = startAnim;
///////////////////

void (*funcArray [])() = {bluePtr, redPtr, greenPtr, startPtr};

CRGB led[NUM_LEDS];

////////////////Color and Animation Funcitons Here//////////////////////////////
void setBlue(int val){
  for (int i = 0; i < NUM_LEDS; i++){
    led[i] = CRGB(0, 0, val);
    }
    FastLED.show();
  }
void setRed(int val){
  for (int i = 0; i < NUM_LEDS; i++){
    led[i] = CRGB(val, 0, 0);
    }
    FastLED.show();
  }

void setGreen(int val){
  for (int i = 0; i < NUM_LEDS; i++){
    led[i] = CRGB(0, val, 0);
    }
    FastLED.show();
  }
void startAnim(){
  for (int i = 0; i < NUM_LEDS; i++){
    led[i] = CRGB(0, 255, 0);
    FastLED.show();
    delay(100);
    led[i] = CRGB(0, 0, 255);
    FastLED.show();
    }
  }
  /////////////////////////////////
  ////////////Initial Setup Function, will run once///////////////
void setup() {
  pinMode(button, INPUT);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(led, NUM_LEDS);

  for (int i = 0; i < NUM_LEDS; i++){
    led[i] = CRGB(0, 0, 255);
    }
  FastLED.show();
}

////////////////////This will constantly loop through the code here/////////////
void loop() {
  lastClick = false;
  pressed = digitalRead(button);

  if(pressed == 1){
    start == false;
    lastClick = true;
    }
  if(lastClick == true){
    timer ++;
    if(timer > coolDown){
      if(index < arrLength - 1){
        index ++;
        }
      else{
        index = 0;
        }
      funcArray[index];
      lastClick = false;
      timer = 0;
    }
    }
  if(start == true){
    startAnim();
    }
  } 

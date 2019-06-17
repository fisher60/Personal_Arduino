#include <FastLED.h>

#define NUM_LEDS 9
#define LED_PIN 2
int button = 4;
int pressed = 0;
CRGB led[NUM_LEDS];

void setup() {
  pinMode(button, INPUT);
  pressed = digitalRead(button);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(led, NUM_LEDS);

  for (int i = 0; i < NUM_LEDS; i++){
    led[i] = CRGB(0, 0, 255);
    }
  FastLED.show();
}

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
void loop() {
  for (int i = 0; i < NUM_LEDS; i++){
    led[i] = CRGB(0, 255, 0);
    FastLED.show();
    delay(100);
    led[i] = CRGB(0, 0, 255);
    FastLED.show();
    }
    
  } 

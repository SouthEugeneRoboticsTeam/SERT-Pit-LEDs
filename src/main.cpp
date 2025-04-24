#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

//Technical Aspects
#define LED_COUNT 16
#define LED_PIN 4

//Customization
#define LED_Brightness 255

#define RED 255, 0, 0
#define GREEN 0, 255, 0
#define BLUE 0, 0, 255
#define WHITE 255, 255, 255
#define Purple 128, 0, 128

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
    strip.begin();
    strip.show();
    strip.setBrightness(LED_Brightness);
}

void loop() {
// write your code here
}
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

void Color_Wipe(uint32_t color, int wait) {
    for(int i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, color);
        strip.show();
        delay(wait);
    }
}

void theaterChase(uint32_t color, unsigned long wait, unsigned int groupSize, unsigned int numChases) {
    for (unsigned int chase = 0; chase < numChases; chase++) {
        for (unsigned int pos = 0; pos < groupSize; pos++) {
            strip.clear();  // turn off all LEDs
            for (unsigned int i = pos; i < strip.numPixels(); i += groupSize) {
                strip.setPixelColor(i, color);  // turn on the current group
            }
            strip.show();
            delay(wait);
        }
    }
}

void theaterChaseTwoColors(uint32_t colorOne, uint32_t colorTwo, unsigned long wait, unsigned int groupSize, unsigned int numChases) {
    for (unsigned int chase = 0; chase < numChases; chase++) {
        for (unsigned int pos = 0; pos < groupSize; pos++) {
            strip.clear();  // turn off all LEDs
            for (unsigned int i = pos; i < strip.numPixels(); i += 1) {
                if ((i % groupSize) == 0){
                    strip.setPixelColor(i, colorOne);
                } else {
                    strip.setPixelColor(i, colorTwo);
                } // turn on the current group
            }
            strip.show();
            delay(wait);
        }
    }
}
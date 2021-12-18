#include <Adafruit_NeoPixel.h>

#define LDR_PIN0 A0
#define LDR_PIN1 A1
#define LDR_PIN2 A2



#define PIN 2   // input pin Neopixel is attached to

#define NUMPIXELS      35 // number of neopixels in Ring

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 0; // timing delay

int redColor = 0;
int greenColor = 0;
int blueColor = 0;

int sensorValue0;
int sensorValue1;
int sensorValue2;

int lightLevel0 = 0;
int lightLevel1 = 0;
int lightLevel2 = 0;
int preLightLevel = 0;

void setup() {
  pixels.begin(); // Initializes the NeoPixel library.
  Serial.begin(9600);
}

void loop() {
  setColor();

  for(int i=0;i<NUMPIXELS;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).

  }

}

// setColor()
// picks random values to set for RGB
void setColor(){

    sensorValue0 = analogRead(LDR_PIN0);
    sensorValue1 = analogRead(LDR_PIN1);
    sensorValue2 = analogRead(LDR_PIN2);

    Serial.println(sensorValue0);
  lightLevel0 = map(sensorValue0, 400, 1000, 10, 255);
//    lightLevel1 = map(sensorValue0, 400, 1000, 10, 255);
//      lightLevel2 = map(sensorValue0, 400, 1000, 10, 255);
      
//  Serial.println(LDR_PIN);
//  Serial.println(lightLevel);

  if( preLightLevel != lightLevel0 ) {
    redColor = random(0, 10) + lightLevel0;
    greenColor = random(0, 10) + lightLevel0;
    blueColor = random(0, 10) + lightLevel0;
  }
  
  preLightLevel = lightLevel0;
}

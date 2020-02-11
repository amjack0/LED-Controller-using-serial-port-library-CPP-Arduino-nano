#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define LED_PIN    6

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 60

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup(){
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(150); // Set BRIGHTNESS to about 1/5 (max = 255) 
}

//int ledPin = 13;

void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    String info;
    info = Serial.readStringUntil('\n');
    if(info.equals("ON")){
      colorWipe(strip.Color(255,   0,   0), 50); // Red
      digitalWrite(LED_PIN, HIGH);
      Serial.print("RED LED is ON");
    }
    if(info.equals("ONF")){
      colorWipe(strip.Color(255,   140,   0), 50); //orange
      digitalWrite(LED_PIN, HIGH);
      Serial.print("ORANGE LED is ON");
    }
    else if(info.equals("OFF")){
      colorWipe(strip.Color(  0, 255,   0), 50); // Green
      digitalWrite(LED_PIN, HIGH); 
      Serial.print("GREEN LED is ON");
    }
  }

}

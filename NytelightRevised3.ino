#include "FastLED.h"
#include <dht.h>

#define NUM_LEDS 24
#define DATA_PIN 9
#define DHT11_PIN 7
#define SDCO (-1766.20)

#define tC 71.0 //adjust temp you feel is too cold here.
#define tH 78.0 //adjust temp you feel is too hot here.
dht DHT;
int g=0;// used for sequentially choosing next led that hasnt been used in standard mode.. so all leds get approx sme runtime.
float tmpf=0;//used for globalizing the check var for temp

CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT); digitalWrite(13,LOW); //Turn OFF the onboard "L" LED
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  Serial.begin(57600);
  Serial.println("Setup Complete.");
  LEDS.setBrightness(10); //added by Lola
  singleRandomLED(0x7FFF00);//added by Lola .. Acts as a pretty good, hi we're on flash.
}

void loop() {
  // put your main code here, to run repeatedly:

  delay(2000); //added by Lola (To assure polling of temp sensor every 2 seconds and no faster.
  tmphum();//Temperature Check subroutine!
    if (tmpf<=tC){tooCold();}
    if (tmpf>=tH){tooHot();}
    Serial.println(SDCO);
    if (tmpf==SDCO){sensorDeadMode();}
    else{standardMode();}
  delay(10); //added by Lola
  //Serial.println("End Cycle - Beginning again.");
}

void tmphum(){
  //Temperature and Humidity Sensor Information
  //
  //needs to be sampled not more than every 2 seconds
  //
  //
  
  int chk = DHT.read11(DHT11_PIN);
  //Serial.print("Temperature = ");
  //Serial.println(DHT.temperature);
  tmpf=(DHT.temperature * 9/5) + 32;//use int instead if you need less precision.
  //Serial.println("In Fahrenheit");
  Serial.println(tmpf);
  //Serial.print("Humidity = ");
  //Serial.println(DHT.humidity);
  }

  // Changes all LEDS to given color
void allColor(CRGB c){
  for(int i=0; i<NUM_LEDS; i++){
    leds[i] = c;
  }
  FastLED.show();
}

  //Bit of a misnomer, Change ONE LEDS to given color, sequentially.
void singleRandomLED(CRGB c){
  //added by Lola
  leds[g] = c;
  FastLED.show();
}


void tooCold(){

  LEDS.setBrightness(100); //added by Lola
  allColor(0x1E90FF);//Change all LEDS to BLUE.
    while(tmpf<=tC){
      //While the temperature sensor is less than or equal to defined tC degrees, wait twenty more seconds and check again til it isn't.
    delay(20000);
    tmphum();
  }
  
}


void tooHot(){
LEDS.setBrightness(100); //added by Lola
  allColor(0xFF0000);//Change all LEDS to RED.
    while(tmpf>=tH){
      //While the temperature sensor is greater than or equal to defined tH degrees, wait twenty more seconds and check again til it isn't.
    delay(20000);
    tmphum();
  }
}


void singleTick(){
//Animates a single LED at a time per second for a full revolution, then jumps back to "loop"
  g++;
  if (g==24)
  {g=0;}
  LEDS.setBrightness(10); //added by Lola
  allColor(0x000000);
  singleRandomLED(0x7FFF00);//added by Lola
}

void standardMode(){
  //stay off for 30 seconds then jump back to loop. Replaces singleTick() temporarily as the kids having adverse reaction to constant on bright led.. go fig. `
  LEDS.setBrightness(10); //added by Lola
  allColor(0x000000);
  delay(20000);
}

void sensorDeadMode(){
//Animates a single LED at a time per second for a full revolution, then jumps back to "loop"
 Serial.println("ALERT SESNOR DEAD OR DISCONNECTED");
  g++;
  if (g==24)
  {g=0;}
  LEDS.setBrightness(10); //added by Lola
  allColor(0x000000);
  singleRandomLED(0xFFC300);//added by Lola
}


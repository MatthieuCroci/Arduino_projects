// Matthieu Croci 
// Temp. Sensor printed on the LCD screen and the cut is regulated with a Potentiometer
// Also a LED is turned on when the temperature is above the cut

#include <math.h>
#include "rgb_lcd.h"
rgb_lcd lcd;

// Screen

const int colorR = 0;
const int colorG = 0;
int colorB = 100;

// Temp. Sensor 

const int B = 4275;             
const int R0 = 100000;            
const int pinTempSensor = A0;     

// Potentiometer

const int pinPot = A1;

// LED

# define LED 3

void setup(){
    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.setRGB(colorR, colorG, colorB);
    pinMode(LED,OUTPUT);
    delay(1000);
}

void loop()
{
    int a = analogRead(pinTempSensor);

    float R = 1023.0/a-1.0;
    R = R0*R;
    float temp = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datasheet

    Serial.println(temp);
    int pot = analogRead(pinPot);
    int cut = map(pot,0,1023,20,40);
    Serial.println(cut);
    
    // Print on the LCD screen the temperature and the cut value 

    lcd.setCursor(0, 0);
    lcd.print(temp);
    lcd.setCursor(0, 1);
    lcd.print(cut);

    if(temp>=cut){
      lcd.setRGB(0, 0, 100);
      digitalWrite(LED,LOW);
      Serial.println("Above");
      }
    else{
      lcd.setRGB(255, 0, 0);
      digitalWrite(LED,HIGH);
      Serial.println("Under");
    }

    delay(1000);

}

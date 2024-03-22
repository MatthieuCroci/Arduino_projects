// Mathtieu Croci 
// Temp. Sensor plot on the LCD screen
// LCD has blue background but If the temperature goes above threschot is turned red 

#include <math.h>
#include "rgb_lcd.h"
rgb_lcd lcd;

// Set the LED color Blu

const int colorR = 0;
const int colorG = 0;
int colorB = 100;

const int B = 4275;               
const int R0 = 100000;          
const int pinTempSensor = A0;     

void setup(){
    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.setRGB(colorR, colorG, colorB);
    delay(1000);
}

void loop()
{
    int a = analogRead(pinTempSensor);

    float R = 1023.0/a-1.0;
    R = R0*R;
    float temp = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datameasurement 

    // Print on the LCD

    lcd.setCursor(0, 0);
    lcd.print(temp);

    // Define a cut 

    int cut = 30;


    if(temp>=cut){
      lcd.setRGB(255, 0, 0);  //Set to red 
      }
    else{
      lcd.setRGB(0, 0, 100);
    }

    delay(1000);

}

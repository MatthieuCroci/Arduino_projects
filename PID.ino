// Matthieu Croci 
// PID controller 

#include <PID_v1.h>
#include <math.h>
#include "rgb_lcd.h"
rgb_lcd lcd;

const int colorR = 0;
const int colorG = 0;
int colorB = 100;

const int B = 4275;              
const int R0 = 100000;            
const int pinTempSensor = A0;     

const int fancontr = 9;

double Setpoint; 
double Input; 
double Output ; 
//PID parameters
double Kp=9, Ki=20, Kd=6; 
 
//create PID instance 
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, REVERSE);
 
void setup()
{ 
  Serial.begin(9600); 

  pinMode(fancontr,OUTPUT);

  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);

  Setpoint = 23.0;
  myPID.SetOutputLimits(0, 255);
  myPID.SetMode(AUTOMATIC);
}
 
void loop(){
  int a = analogRead(pinTempSensor);
  float R = 1023.0/a-1.0;
  R = R0*R;
  Input = 1.0/(log(R/R0)/B+1/298.15)-273.15; 
  Setpoint = 23.0;

  lcd.setCursor(0, 0);
  lcd.print(Input);
  lcd.setCursor(0, 1);
  lcd.print(Setpoint);

  //PID calculation
  myPID.Compute();
  analogWrite(fancontr,Output); 

  //Send data by serial for plotting 
  Serial.print(Input);
  Serial.print(", ");
  Serial.println(100*Output/255);
  delay(100);
}


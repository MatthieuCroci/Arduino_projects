// Matthieu Crcoi 
// RPM calculator 

const int SensorPin = 2;  
const int contr = 9;

int InterruptCounter, rpm;

void setup(){
  pinMode(contr,OUTPUT);
  analogWrite(contr, 0);
  delay(1000);
  Serial.begin(9600);
}

void loop() {
  // Looping from 0 to 100 duty fan speed and read the RPM
  for(int pwm=0; pwm<=255; pwm +=15){
    analogWrite(contr, pwm);
    delay(5000);
    InterruptCounter = 0;
    attachInterrupt(digitalPinToInterrupt(SensorPin), countup, RISING);
    delay(1000);
    detachInterrupt(digitalPinToInterrupt(SensorPin));
    rpm = (InterruptCounter / 2) * 60;
    display_rpm();}
}

void countup() {
  InterruptCounter++;
}

void display_rpm() {
  Serial.print("Counts: ");
  Serial.print(InterruptCounter, 1);
  Serial.print(" RPM: ");
  Serial.println(rpm);
}

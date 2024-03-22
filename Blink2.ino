// Matthieu Croci
// 2 LED blinking with different frequency

# define led_pin1 12
# define led_pin2 8

unsigned long privTime1 = 0;
unsigned long delay1 = 1300;
byte state1 = LOW;

unsigned long privTime2 = 0;
unsigned long delay2 = 400;
byte state2 = LOW;

void setup() {
  pinMode(led_pin1, OUTPUT);
  pinMode(led_pin2, OUTPUT);

}

void loop() {
  // Blinking LED 1
  unsigned long now1 = millis();
  if(now1-privTime1>delay1){
    privTime1+=delay1;
    if(state1==LOW){
      state1 = HIGH;
    }
    else{
      state1 = LOW;
    }
    digitalWrite(led_pin1, state1);
  }

 // Blinking LED 2
  unsigned long now2 = millis();
  if(now2-privTime2>delay2){
    privTime2+=delay2;
    if(state2==LOW){
      state2 = HIGH;
    }
    else{
      state2 = LOW;
    }
    digitalWrite(led_pin2, state2);
  }
}

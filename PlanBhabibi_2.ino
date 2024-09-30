#include <Servo.h>
Servo sv;

int r_forward = 9;
int r_back = 10;

int b_start = 11;
int b_switch = 2;

int t = 0;
int degree;

void setup() {
  Serial.begin(9600);
  sv.attach(3);
  sv.write(80);

  pinMode(r_forward, OUTPUT);
  pinMode(r_back, OUTPUT);

  pinMode(b_start, INPUT_PULLUP);
  pinMode(b_switch, INPUT_PULLUP);
}

void loop() {
  
  if(digitalRead(b_start) == 0){
    delay(1000);
    digitalWrite(r_forward, 1);
    delay(2000);
    sv.write(180);
    delay(1622);
    sv.write(75);
    delay(3000);
    digitalWrite(r_forward, 0);

  }
}

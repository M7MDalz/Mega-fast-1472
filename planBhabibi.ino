#include <Servo.h>
Servo sv;

int r_forward = 9;
int r_back = 10;

int b_start = 11;
int b_switch = 2;

int trig = 7;
int echo = 6;
long dur;
long cm;

int t = 0;
int degree;
void setup() {
  Serial.begin(9600);
  sv.attach(3);
  sv.write(80);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(r_forward, OUTPUT);
  pinMode(r_back, OUTPUT);

  pinMode(b_start, INPUT_PULLUP);
  pinMode(b_switch, INPUT_PULLUP);
}

void loop() {
  Serial.println(digitalRead(b_start));

  if(digitalRead(b_switch) == 0){
    degree = 180;
  }

  digitalWrite(trig, 0);
  delayMicroseconds(10);
  digitalWrite(trig, 1);
  delayMicroseconds(2);
  digitalWrite(trig, 0);

  dur = pulseIn(echo, 1);
  
  cm = (dur * 0.03434) / 2;
    
  Serial.println(cm);

  if(digitalRead(b_start) == 0){
    Serial.println(digitalRead(b_start));
    delay(500);
    while(t < 12){
      digitalWrite(trig, 0);
      delayMicroseconds(10);
      digitalWrite(trig, 1);
      delayMicroseconds(2);
      digitalWrite(trig, 0);

      dur = pulseIn(echo, 1);
  
      cm = (dur * 0.03434) / 2;
    
      Serial.println(cm);

      if(cm <= 90){
        sv.write(degree);
        delay(1615);
        t++;  
        sv.write(80);
      }
      
      digitalWrite(r_forward, 1);

      delay(200);
      
    }
    sv.write(80);
    digitalWrite(r_forward, 0);
    t = 0;
    delay(1000);
  }
  delay(200);
}
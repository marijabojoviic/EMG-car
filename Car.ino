#include<SoftwareSerial.h>
#define enA0 3
#define in10 2
#define in20 4
#define enB0 6
#define in30 5
#define in40 7

#define enA1 10
#define in11 8
#define in21 9
#define enB1 11
#define in31 13
#define in41 12


#define rxPin 0
#define txPin 1

SoftwareSerial MySerial(rxPin, txPin);
int prethodno=5;
char readdata;
void setup() {
   pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  // put your setup code here, to run once:
  pinMode(enA0, OUTPUT);
  pinMode(enB0, OUTPUT);
  pinMode(in10, OUTPUT);
  pinMode(in20, OUTPUT);
  pinMode(in30, OUTPUT);
  pinMode(in40, OUTPUT);

  pinMode(enA1, OUTPUT);
  pinMode(enB1, OUTPUT);
  pinMode(in11, OUTPUT);
  pinMode(in21, OUTPUT);
  pinMode(in31, OUTPUT);
  pinMode(in41, OUTPUT);
  
  MySerial.begin (38400);
}


void levo() {
  digitalWrite(in10, HIGH);
    digitalWrite(in20, LOW);
    digitalWrite(in30, HIGH);
    digitalWrite(in40, LOW); 
    
    analogWrite(enA0, 100);
    analogWrite(enB0, 100);
    
    digitalWrite(in11, HIGH);
    digitalWrite(in21, LOW);
    digitalWrite(in31, HIGH);
    digitalWrite(in41, LOW);

    analogWrite(enA1, 100);
    analogWrite(enB1, 100);
  }
  void desno () {
      digitalWrite(in10, LOW);
    digitalWrite(in20, HIGH);
    digitalWrite(in30, LOW);
    digitalWrite(in40, HIGH); 
    
    analogWrite(enA0, 100);
    analogWrite(enB0, 100);
    
    digitalWrite(in11, LOW);
    digitalWrite(in21, HIGH);
    digitalWrite(in31, LOW);
    digitalWrite(in41, HIGH);

    analogWrite(enA1, 100);
    analogWrite(enB1, 100);
  }
  void napred () {
    digitalWrite(in10, LOW);
    digitalWrite(in20, HIGH);
    digitalWrite(in30, HIGH);
    digitalWrite(in40, LOW); 

    
    digitalWrite(in11, HIGH);
    digitalWrite(in21, LOW);
    digitalWrite(in31, LOW);
    digitalWrite(in41, HIGH);

  
    analogWrite(enA1, 100);
    analogWrite(enB1, 100);
    analogWrite(enA0, 100);
    analogWrite(enB0, 100);
    }
    void stani () {
    digitalWrite(in10, LOW);
    digitalWrite(in20, HIGH);
    digitalWrite(in30, HIGH);
    digitalWrite(in40, LOW); 

    
    digitalWrite(in11, HIGH);
    digitalWrite(in21, LOW);
    digitalWrite(in31, LOW);
    digitalWrite(in41, HIGH);

  
    analogWrite(enA1, 0);
    analogWrite(enB1, 0);
    analogWrite(enA0, 0);
    analogWrite(enB0, 0);
      }
void loop() {
  
if (MySerial.available()>0) {
readdata=MySerial.read();
if ((readdata == '0')&&(prethodno!=0)) {
stani();
prethodno=0;
delay (1000);
}
if ((readdata == '1')&&(prethodno!=1)) {
  
napred();
prethodno=1;
delay(1000);
}
if ((readdata == '2')&&(prethodno!=2)) {
levo();
prethodno=2;
delay(1000);
}
if ((readdata == '3')&&(prethodno!=3)) {
desno();
prethodno=3;
delay(1000);
}
}
}

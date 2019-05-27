#include <NewPing.h>

const int fototransistor = A3;
const int motor1 = 5;
const int motor2 = 6;
const int Trigger = 12;
const int Echo = 13;
const int LedV = 8;
const int LedA = 7;
const int LedR = 9;
NewPing sonar(Trigger, Echo);

void setup() {
  
  pinMode(fototransistor,INPUT);
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(LedV,OUTPUT);
  pinMode(LedA,OUTPUT);
  pinMode(LedR,OUTPUT);

  //===Configuración del puerto serie===
  Serial.begin(9600);
  while (!Serial) {}
  //====================================
}

void loop() {

  int lectura = analogRead(fototransistor);
  int distancia = sonar.ping_cm();
  delay(500);
  
  //===Lecturas sólo para Debug===
  Serial.println("===Lecturas===");
  Serial.println(distancia);
  Serial.println(lectura);
  //==============================
  
  if(lectura > 22){
    digitalWrite(LedA,HIGH);
  } else{
    digitalWrite(LedA,LOW);
  }
  if(distancia < 10){
    digitalWrite(LedV,HIGH);
  }else{
    digitalWrite(LedV,LOW);
  }

  if(lectura < 22){
    if(distancia < 10  & distance != 0){
    
      digitalWrite(LedR, HIGH);
      
      analogWrite(motor1, 150);
      digitalWrite(motor2, LOW);
      
      delay(1000);
      
      digitalWrite(LedR, LOW);

      digitalWrite(motor1, HIGH);
      digitalWrite(motor2, HIGH);
    }
  } 

}

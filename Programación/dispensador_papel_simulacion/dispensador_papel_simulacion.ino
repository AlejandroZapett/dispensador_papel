const int fototransistor = A3;
const int motor1 = 5;
const int motor2 = 6;
const int ultrasonico = 13;
const int LedV = 8;
const int LedA = 7;
const int LedR = 9;

void setup() {

  pinMode(fototransistor,INPUT);
  pinMode(ultrasonico,INPUT);
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(LedV,OUTPUT);
  pinMode(LedA,OUTPUT);
  pinMode(LedR,OUTPUT);

}

void loop() {

  int lectura = analogRead(fototransistor);
  int distancia = digitalRead(ultrasonico);
  delay(500);

  if(distancia == 1){
    digitalWrite(LedV,HIGH);
  } else{
    digitalWrite(LedV,LOW);
  }
  
  if(lectura < 22){
    digitalWrite(LedA,LOW);
    if(distancia == 1){
      encender_motor();
      delay(2000);
      apagar_motor();
    }
  } else {
    digitalWrite(LedA,HIGH);
  }

  while(fototransistor == 0){
    if(ultrasonico == 1){
      encender_motor();
      delay(2000);
      apagar_motor();
    }
  }
  
}

void encender_motor(){
  digitalWrite(LedR,HIGH);
  digitalWrite(motor1,HIGH);
  digitalWrite(motor2,LOW);
}

void apagar_motor(){
  digitalWrite(LedR,LOW);
  digitalWrite(motor1,HIGH);
  digitalWrite(motor2,HIGH);
}

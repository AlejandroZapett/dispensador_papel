//La Biblioteca NewPing nos permite configurar y utilizar
//el sensor ultrasónico
#include <NewPing.h>

//Sensores
const int fototransistor = A3; //Pin analógico del Arduino
const int trigger = 12;
const int echo = 13;
NewPing sonar(trigger, echo); //Sensor ultrasónico
//Actuadores
const int motor_uno = 5;
const int motor_dos = 6;
//Banderas
const int led_amarillo = 7; //Indica si hay papel en la bandeja
const int led_verde = 8; //Indica si hay solicitud de papel
const int led_rojo = 9; //Indica si el motor está activo

void setup() {
  //==Declaración de entradas y salidas==
  //Sensores
  pinMode(fototransistor,INPUT);
  //Actuadores
  pinMode(motor_uno,OUTPUT);
  pinMode(motor_dos,OUTPUT);
  //Banderas
  pinMode(led_amarillo,OUTPUT);
  pinMode(led_verde,OUTPUT);
  pinMode(led_rojo,OUTPUT);
  //=====================================
}

void loop() {
  
  //=======Lecturas de los sensores======
  int obstruccion = analogRead(fototransistor);
  int distancia = sonar.ping_cm();
  delay(500);
  //=====================================

  //=========Lógica del programa=========
  if(distancia < 10 & distancia != 0){ // Pregunta por la solicitud de papel
    digitalWrite(led_verde,HIGH); // Hay solicitud de papel
  }else{
    digitalWrite(led_verde,LOW); // No hay solicitud de papel
  }

  if(obstruccion < 22){ // Pregunta por papel en la bandeja
    digitalWrite(led_amarillo,LOW); //No hay papel en la bandeja
    if(distancia < 10  & distancia != 0){ // Pregunta por la solicitud de papel
      // Hay solicitud de papel
      encender_motor();
      delay(1000);
      apagar_motor();
    }
  } else {
    digitalWrite(led_amarillo,HIGH); // Hay papel en la bandeja
  }
   //=====================================

}

//=========Funciones auxiliares=========
void encender_motor(){
  digitalWrite(led_rojo, HIGH); // Bandera de motor encendido
  analogWrite(motor_uno, 150); // Salida de pwm para regular
  //velocidad del motor
  digitalWrite(motor_dos, LOW);
}

void apagar_motor(){
   digitalWrite(led_rojo, LOW); // Bandera de motor apagado
   digitalWrite(motor_uno, HIGH);
   digitalWrite(motor_dos, HIGH);
}
//=====================================

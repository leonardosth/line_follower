#include <Arduino.h>

/*portas sensor QTR*/

#define sensor1 A0
#define sensor2 A1
#define sensor3 A2
#define sensor4 A3
#define sensor5 A6
#define sensor6 A7

/*número de sensores*/

#define SENSORNO 6

/*limite de preto*/

#define BLACK 800

/*motor direito*/

#define RIGHT_PMW 9 /* analogWrite(valor) 0-255*/
#define RIGHT_IN2 7 /* digitalWrite(HIGH or LOW)*/
#define RIGHT_IN1 8 /* digitalWrite(HIGH or LOW)*/

#define STBY 6 /*HABILITA LOCOMOÇÃO digitalWrite(HIGH)*/

/*MOTOR ESQUERDO*/

#define LEFT_IN1 4
#define LEFT_IN2 5
#define LEFT_PMW 3

/* portas bluetooth*/

#define BLUETOOTH_TX 10
#define BLUETOOTH_RX 11


void setup() {
  
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);
  pinMode(sensor6, INPUT);
  Serial.begin(9600);

  pinMode(LEFT_PMW, OUTPUT);
  pinMode(LEFT_IN2, OUTPUT);
  pinMode(LEFT_IN1, OUTPUT);
  
  pinMode(RIGHT_PMW, OUTPUT);
  pinMode(RIGHT_IN2, OUTPUT);
  pinMode(RIGHT_IN1, OUTPUT);
  pinMode(STBY, OUTPUT);

}


void funcao(int vele, int veld){
   digitalWrite(STBY, HIGH);
    
    digitalWrite(RIGHT_IN2, LOW);
    digitalWrite(RIGHT_IN1, HIGH);
    analogWrite(RIGHT_PMW, veld);

    digitalWrite(LEFT_IN2, HIGH);
    digitalWrite(LEFT_IN1, LOW);
    analogWrite(LEFT_PMW, vele);
}



void loop() {
  
  int luz1, luz2, luz3, luz4, luz5, luz6;
  luz6 = analogRead(sensor1);
  luz5 = analogRead(sensor2);
  luz4 = analogRead(sensor3);
  luz3 = analogRead(sensor4);
  luz2 = analogRead(sensor5);
  luz1 = analogRead(sensor6);
  

  //ir pra frente
  
 Serial.print(luz1);
 Serial.print(" ");
 Serial.print(luz2);
 Serial.print(" ");
 Serial.print(luz3);
 Serial.print(" ");
 Serial.print(luz4);
 Serial.print(" ");
 Serial.print(luz5);
 Serial.print(" ");
 Serial.print(luz6);
 Serial.print(" ");
 Serial.println("");
 

if (luz1 < 200 && luz2 < 200)
{
  funcao(0, 110);
}
  else if (luz2 < 200 && luz3 < 200)
{
  funcao(100, 125);  
}
  else if (luz3 < 200 && luz4 < 200)
{
  funcao(125, 125);
}
else if (luz4 < 200 && luz5 < 200)
{
  funcao(125, 100);
}
  else if (luz5 < 200 && luz6 < 200)
{
  funcao(110, 0);
}
else if(luz1 < 200)
{
  funcao(0, 120);
} 
  else if(luz2 < 200)
{
  funcao(20, 100);
}
  else if (luz3 < 200)
{
  funcao(115, 125);
}
  else if (luz4 < 200)
{
  funcao(125, 115);
}
  else if (luz5 < 200)
{
  funcao(100, 20);
}
  else if (luz6 < 200)
{
  funcao(120, 0);
}
  else
{
  funcao(0, 0);
}

}


#include <Servo.h>

Servo servo1;
Servo servo2;

const int LED1_PIN = 2;
const int LED2_PIN = 3;

void setup() {
  Serial.begin(9600);
  
  servo1.attach(9);
  servo2.attach(10);
  
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  
  // Posição inicial (0 graus)
  servo1.write(0);
  servo2.write(0);
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    
    // Processa comandos para o Servo 1 (ex: S1:90)
    if (input.startsWith("S1:")) {
      int angle = input.substring(3).toInt();
      servo1.write(angle);
      
      // Se o ângulo for maior que 0, acende o LED
      if (angle > 0) {
        digitalWrite(LED1_PIN, HIGH);
      } else {
        digitalWrite(LED1_PIN, LOW);
      }
    } 
    // Processa comandos para o Servo 2 (ex: S2:90)
    else if (input.startsWith("S2:")) {
      int angle = input.substring(3).toInt();
      servo2.write(angle);
      
      // Se o ângulo for maior que 0, acende o LED
      if (angle > 0) {
        digitalWrite(LED2_PIN, HIGH);
      } else {
        digitalWrite(LED2_PIN, LOW);
      }
    }
  }
}
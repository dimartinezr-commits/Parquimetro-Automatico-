//Conexión de Pines pantalla 16x2 con protocolo I2C al microcontrolador ESP32, SDA: 21; SCL: 22
//Sensor Ultrasonico HC-SR04 
#include <LiquidCrystal_I2C.h>
const int trigPin = 5;
const int echoPin = 18;
const int ledPin = 2;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  lcd.init();       
  lcd.clear();      
  lcd.backlight();  
  lcd.setCursor(0, 0);
  lcd.print("  Hola Park :) ");
  lcd.setCursor(0, 1);
  lcd.print("   Automatico ");
  delay(2000);
  lcd.clear();
}

void loop() {
  long duration;
  float distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Cálculo de distancia en cm [3]

  Serial.print("Distancia: ");
  Serial.println(distance);

  if (distance < 20) { // Si hay un objeto a menos de 20cm
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  delay(500);

  lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(" Long: "); // Imprime la distancia en el LCD.
    lcd.print(distance);
    lcd.print("cm");
    lcd.setCursor(0, 0);
    lcd.print("   Parking IA");
  delay(500);
} 


#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define LEDr 7
#define LEDg 6
#define LEDb 5
LiquidCrystal_I2C lcd(0x27, 16, 2);
const float referenceVolts = 5; 
const int batteryPin = 1;         
const int buttonPin = 2;
int buttonState = 0;
const int potPin = A0;     
void setup() 
{
  pinMode(LEDr, OUTPUT);
  pinMode(LEDb, OUTPUT);
  pinMode(LEDg, OUTPUT);
  lcd.begin();
  
  lcd.backlight();
  Serial.begin(9600);
  pinMode(potPin, INPUT);
}

void loop()
{ 
  int sensorValue = analogRead(A2);
  Serial.println(sensorValue);
  delay(1);
  float volts= sensorValue * (5.0 / 1023.0);
  int con= volts*2183-152.8;
  
  lcd.clear();
  
  if (-1000<=con and con<=1000){
    digitalWrite(LEDr, HIGH);
    digitalWrite(LEDg, LOW);
    digitalWrite(LEDb, LOW);
    
  }
  else if (1000<=con and con<=2000){
    digitalWrite(LEDg, HIGH);
    digitalWrite(LEDr, LOW);
    digitalWrite(LEDb, LOW);
  }
  else if (2000<=con and con<=10000){
    digitalWrite(LEDb, HIGH);
    digitalWrite(LEDr, LOW);
    digitalWrite(LEDg, LOW);
  }
  lcd.setCursor(4,0);
  lcd.print("v: ");
  lcd.print(volts);
  lcd.setCursor(4,1);
  lcd.print("c:");
  lcd.print(con);
  delay(500);
} 

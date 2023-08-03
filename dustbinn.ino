#include <Key.h>
#include <Keypad.h>
#include<Servo.h>
#include <LiquidCrystal.h>
int servoPin=3;
int servo1Pin=2;
int Ir = 4;
int Ir1 = 5;
Servo S;
Servo S1;

const byte ROWS = 4; 
const byte COLS = 4; 
char hexaKeys[ROWS][COLS] = {
  {'D','#','0','*'},
  {'C','9','8','7'},
  {'B','6','5','4'},
  {'A','3','2','1'}
};
byte rowPins[ROWS] = {10, 11, 12, 13}; 
byte colPins[COLS] = {6, 7, 8, 9}; 

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
const int rs = A5, en = A4, d4 = A3, d5 = A2, d6 = A1, d7 = A0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup(){
Serial.begin(9600);
pinMode(Ir, INPUT);
pinMode(Ir1,INPUT);
S.attach(servoPin);
S1.attach(servo1Pin);

lcd.print("1-WET 2-DRY");
  
}

void loop(){
  
  char customKey = customKeypad.getKey();

  if (customKey){
Serial.println(customKey);
{

switch (customKey)

{
case '1':

S.write(90);

Serial.println("WET");
lcd.begin(16, 1);
Serial.println("OPEN");
lcd.print("1-WET 2-DRY");
delay(3000);
S.write(0);
 
break;
  
case '2':
S1.write(90);
Serial.println("Dry");
lcd.begin(16, 1);
Serial.println("OPEN");
lcd.print("1-WET 2-DRY");
delay(3000);
S1.write(0);

break;

}
  int b=digitalRead(Ir);
  if (b==0)
  {
    Serial.println("2-FULL ");
   S.write(0);
   Serial.println("CLOSED");
    
  }
  else{
    Serial.println("2-EMPTY");
    
    
  }
  int a=digitalRead(Ir1);
  if (a==0)
  {
    Serial.println("1-FULL ");
    S.write(0);
   Serial.println("CLOSED");
   
    
  }
  else{
    Serial.println("1-EMPTY");
    
    
  }
 
  }
  }
}

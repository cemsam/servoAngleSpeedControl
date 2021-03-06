#include <VarSpeedServo.h>

VarSpeedServo sg90;

int potPin1=A1;
int potPin2=A2;
int value1=0;
int value2=0;
int mapped1=0;
int mapped2=0;

void setup() {
 Serial.begin(9600);
 sg90.attach(9); 
 sg90.write(0, 20, true);  
}

void loop() {
 value1 = analogRead(potPin1);
 value2 = analogRead(potPin2);
 
 mapped1 = map(value1, 0, 1023, 0, 160);
 mapped2 = map(value2, 0, 1023, 30, 255);
 
 Serial.print("Angle:");
 Serial.print(mapped1);
 Serial.print("\t");
 Serial.print("Speed:");
 Serial.println(mapped2); 


 sg90.write(0, mapped2, true);
 sg90.write(mapped1, mapped2, true);         
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

#include <Servo.h>

int const POT_PIN = A0;
int const SERVO_PIN = 9;
int potValue;
int angle;

Servo servo;

void setup()
{
  servo.attach(SERVO_PIN);
  Serial.begin(9600);
}

void loop()
{
  potValue = analogRead(POT_PIN);
  Serial.print("potValue: ");
  Serial.print(potValue);
  
  angle = map(potValue, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.print(angle);
  Serial.println();
  
  servo.write(angle);
  delay(1000);
}

const int GREEN_LED_PIN = 9;
const int RED_LED_PIN = 11;
const int BLUE_LED_PIN = 10;

const int RED_SENSOR_PIN = A0;
const int GREEN_SENSOR_PIN = A1;
const int BLUE_SENSOR_PIN = A2;

float redValue = 0;
float greenValue = 0;
float blueValue = 0;

float redSensorValue = 0;
float greenSensorValue = 0;
float blueSensorValue = 0;

float total = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
}

void loop()
{
  redSensorValue = (float) analogRead(RED_SENSOR_PIN);
  delay(5);
  
  greenSensorValue = (float) analogRead(GREEN_SENSOR_PIN);
  delay(5);
  
  blueSensorValue = (float) analogRead(BLUE_SENSOR_PIN);
  delay(5);
  
  Serial.print("Sensor: ");
  Serial.print("\tRed: ");
  Serial.print(redSensorValue);
  Serial.print("\tBlue: ");
  Serial.print(blueSensorValue);
  Serial.print("\tGreen: ");
  Serial.print(greenSensorValue);
  Serial.println("");
  
  total = redSensorValue + blueSensorValue + greenSensorValue;
  
  redValue = (redSensorValue / total) * 255.0;
  blueValue = (blueSensorValue / total) * 255.0;
  greenValue = (greenSensorValue / total) * 255.0;

  Serial.print("Output: ");
  Serial.print("\tRed: ");
  Serial.print(redValue);
  Serial.print("\tBlue: ");
  Serial.print(blueValue);
  Serial.print("\tGreen: ");
  Serial.print(greenValue);
  Serial.println("");
  
  analogWrite(RED_LED_PIN, (int) redValue);
  analogWrite(BLUE_LED_PIN, (int) blueValue);
  analogWrite(GREEN_LED_PIN, (int) greenValue);
}

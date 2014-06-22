int const LED_PIN = 8;
int const PIEZO_PIN = 7;
int const SENSOR_PIN = A0;

int sensorLow = 1023;
int sensorHigh = 0;
int sensorValue = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  
  while (millis() < 10000) {
    sensorValue =  analogRead(SENSOR_PIN);
    sensorHigh = (sensorValue > sensorHigh ? sensorValue : sensorHigh);
    sensorLow =  (sensorValue < sensorLow  ? sensorValue : sensorLow);
    
    Serial.print("Sensor Value: ");
    Serial.print(sensorValue);
    Serial.print(" high: ");
    Serial.print(sensorHigh);
    Serial.print(" low: ");
    Serial.print(sensorLow);
    Serial.println();
  }
  
  digitalWrite(LED_PIN, LOW);
}

void loop()
{
  sensorValue = analogRead(SENSOR_PIN);
  
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  tone(PIEZO_PIN, pitch, 20);
}

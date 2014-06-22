const int SENSOR_PIN = A0;
const float BASELINE_TEMPERATURE = 20.0;

void setup()
{
  Serial.begin(9600);
  
  for (int pin = 2; pin < 5; pin++) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
}

void loop()
{
  int sensorValue = analogRead(SENSOR_PIN);
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  float voltage = (sensorValue / 1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);
  float temperature = (voltage - 0.5) * 100;
  Serial.print(" degrees C: ");
  Serial.print(temperature);
  Serial.println();
  
  for (int i = 2; i < 5; i++) {
    int pinValue = LOW;
    
    if (temperature > (i + BASELINE_TEMPERATURE)) {
      pinValue = HIGH;
    }
    
    digitalWrite(i, pinValue);
  }
}

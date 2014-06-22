
int NOTES[] = { 262, 294, 330, 349 };

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int keyVal = analogRead(A0);
  
  Serial.print("keyVal: ");
  Serial.println(keyVal);
  
  if (keyVal == 1023) {
    tone(8, NOTES[0]);
  } else if (keyVal >=  990 && keyVal <= 1010) {
    tone(8, NOTES[1]);
  } else if (keyVal >=  505 && keyVal <=  515) {
    tone(8, NOTES[2]);
  } else if (keyVal >=    5 && keyVal <=   10) {
    tone(8, NOTES[3]);
  } else {
    noTone(8);
  }
}


#define LED 9
#define HALL 2

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(HALL, INPUT);
}

void loop()
{
  if (digitalRead(HALL) == HIGH)
  {
    digitalWrite(LED, HIGH);
    delay(200);
  }
  else
  {
    digitalWrite(LED, LOW);
    delay(200);
  }
}

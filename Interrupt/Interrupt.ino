#define LED 10
volatile int button_state = LOW;
void setup() 
{
  pinMode(LED,OUTPUT);
  attachInterrupt(1,Light,LOW);
  Serial.begin(9600);
  digitalWrite(LED,button_state);
}

void loop() 
{
  digitalWrite(LED,button_state);
}
void Light()
{
  button_state = !button_state;
}

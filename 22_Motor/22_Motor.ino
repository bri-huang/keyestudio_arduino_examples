int IN1 = 7;
int IN2 = 6;
int ENA = 5;
void setup()
{
  for (int i = 5; i < 8; i ++)
  {
    pinMode(i, OUTPUT);
  }
}
void loop()
{
  //turn forward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 200);
  delay(1000);
  //delay one second
  analogWrite(ENA, 0);
  delay(1000);
  //turn forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 100);
  delay(1000);
  //pause one second
  analogWrite(ENA, 0);
  delay(1000);
}

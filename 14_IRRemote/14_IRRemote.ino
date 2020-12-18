/*
   IRremote: IRreceiveDemo - demonstrates receiving IR codes with IRrecv
   An IR detector/demodulator must be connected to the input RECV_PIN.
   Initially coded 2009 Ken Shirriff http://www.righto.com/
*/

#include <IRremote.h>
/**************************************************/
int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;
int LED6 = 7;

long on1  = 0x00FF6897;
long off1 = 0x00FF9867;
long on2 =  0x00FFB04F;
long off2 = 0x00FF30CF;
long on3 =  0x00FF18E7;
long off3 = 0x00FF7A85;
long on4 =  0x00FF10EF;
long off4 = 0x00FF38C7;
long on5 =  0x00FF5AA5;
long off5 = 0x00FF42BD;
long on6 =  0x00FF4AB5;
long off6 = 0x00FF52AD;
/**************************************************/

int IR_RECEIVE_PIN = 12;
IRrecv IrReceiver(IR_RECEIVE_PIN);
decode_results results;
unsigned long last;

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  
  pinMode(IR_RECEIVE_PIN, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);

  Serial.begin(115200);

  Serial.println("Enabling IRin");
  IrReceiver.enableIRIn();  // Start the receiver

  Serial.print(F("Ready to receive IR signals at pin "));
  Serial.println(IR_RECEIVE_PIN);
}

void loop()
{
  if (IrReceiver.decode(&results))
  {
    // If it's been at least 1/4 second since the last
    // IR received, toggle the relay
    if (millis() - last > 250)
    {
      dump(&results);
    }
    if (results.value == on1 )
      digitalWrite(LED1, HIGH);
    if (results.value == off1 )
      digitalWrite(LED1, LOW);
    if (results.value == on2 )
      digitalWrite(LED2, HIGH);
    if (results.value == off2 )
      digitalWrite(LED2, LOW);
    if (results.value == on3 )
      digitalWrite(LED3, HIGH);
    if (results.value == off3 )
      digitalWrite(LED3, LOW);
    if (results.value == on4 )
      digitalWrite(LED4, HIGH);
    if (results.value == off4 )
      digitalWrite(LED4, LOW);
    if (results.value == on5 )
      digitalWrite(LED5, HIGH);
    if (results.value == off5 )
      digitalWrite(LED5, LOW);
    if (results.value == on6 )
      digitalWrite(LED6, HIGH);
    if (results.value == off6 )
      digitalWrite(LED6, LOW);
    last = millis();
    IrReceiver.resume(); // Receive the next value
  }
}

void dump(decode_results *results) {
  if (results->decode_type == UNKNOWN)
  {
    Serial.println("Could not decode message");
  }
  else
  {
    Serial.print("Data: ");
    Serial.print(results->value, HEX);
  }
  Serial.println("");
}

int led1 = 8; // si definisce il led e lo si assegna ad un determinato PIN
int pushBottone = 7; // si definisce il bottone 
int btn_status = 0; // si usa come variabile per indicare se il pulsante si premuto o meno e si utilizzerà nel corso del codice.
int tempo_random = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(led1, OUTPUT);
pinMode(pushBottone, INPUT);
tempo_random = random(2000, 10000);
}

void loop() {
  delay(tempo_random);
  digitalWrite(led1, HIGH);
  while(btn_status == LOW)
  btn_status = digitalRead(pushBottone);
  if(btn_status == HIGH)
  {
    digitalWrite(led1, LOW);
  }
  btn_status = LOW;
  delay(3000);
}

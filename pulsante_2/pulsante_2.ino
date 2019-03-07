int led1 = 8; // si definisce il led e lo si assegna ad un determinato PIN
int pushBottone = 9; // si definisce il bottone 
int btn_status = 0; // si usa come variabile per indicare se il pulsante si premuto o meno e si utilizzerà nel corso del codice.
long tempo_random;
long tempo_bottone;
int tempo_riflesso;
void setup() {
  // put your setup code here, to run once:
pinMode(led1, OUTPUT);
pinMode(pushBottone, INPUT);
Serial.begin(9600);
}

void loop() {
  tempo_random = 0;
  tempo_bottone = 0;
  tempo_random = random(2000, 10000);
  delay(tempo_random);// parte a contare i millisecondi necessari ad accendere il led econtinua fino al push del bottone.
  digitalWrite(led1, HIGH);
  tempo_random = millis();
  while(btn_status == LOW)
  btn_status = digitalRead(pushBottone);
  tempo_bottone = millis(); // restituisce i millisecondi necessari al led per essere spento dal bottone 
  if(btn_status == HIGH)
  {
    digitalWrite(led1, LOW);
  }
  btn_status = LOW;
  tempo_riflesso = tempo_bottone - tempo_random;
  Serial.println("tempo random: ");
  Serial.println(tempo_random);
  Serial.println("tempo bottone: ");
  Serial.println(tempo_bottone);
  Serial.println("tempo riflessi: ");
  Serial.println(tempo_riflesso);
  while(Serial.available() == 0);
}

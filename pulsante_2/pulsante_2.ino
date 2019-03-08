int led1 = 9; // si definisce il led e lo si assegna ad un determinato PIN
int pushBottone = 8; // si definisce il bottone 
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
  tempo_random = 0; // RESET DELLE VARIABILI
  tempo_bottone = 0; // RESET DELLE VARIABILI
  digitalWrite(beep, LOW); // setta inizialmente il buzzer senza alcun tipo di suono
  tempo_random = random(2000, 10000); // genera un tempo random
  delay(tempo_random);// parte a contare i millisecondi necessari ad accendere il led econtinua fino al push del bottone.
  // con la funzione millis() riesce a prendere i millisecondi durante i quali viene acceso il led 
  digitalWrite(led1, HIGH);
  tempo_random = millis();
  // questo while permette di capire se il bottone è stato premuto oppure no.
  while(btn_status == LOW)
  btn_status = digitalRead(pushBottone);
   
  if(btn_status == HIGH)
  {
    tempo_bottone = millis(); // restituisce i millisecondi necessari al led per essere spento dal bottone 
    digitalWrite(led1, LOW);
    btn_status = LOW;
  }
  
  // parte correlata alla seriale che permette di restituire in out il valore dei millisecondi i riflesso.
  tempo_riflesso = tempo_bottone - tempo_random;
  Serial.println("Hai premuto il bottone dopo: ");
  Serial.println(tempo_riflesso);
  while(Serial.available() == 0);
  tempo_random = random(2000, 10000);
  digitalWrite(
  delay(tempo_random);
  
}

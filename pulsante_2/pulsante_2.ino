int beep = 10;
int led1 = 9; // si definisce il led e lo si assegna ad un determinato PIN
int pushBottone = 8; // si definisce il bottone 
int btn_status = 0; // si usa come variabile per indicare se il pulsante si premuto o meno e si utilizzerà nel corso del codice.
int tempo_random;
int tempo_riflesso;
int tempo_riflesso_buzzer;
void setup() {
  // put your setup code here, to run once:
pinMode(led1, OUTPUT);
pinMode(pushBottone, INPUT);
pinMode(beep, OUTPUT);
Serial.begin(9600);
}

void loop() { 
  
  Serial.println("INIZIO");
  tempo_random = random(2000, 10000); // genera un tempo random
  delay(tempo_random);// parte a contare i millisecondi necessari ad accendere il led econtinua fino al push del bottone.                      
  digitalWrite(led1, HIGH); 
  long tempo_led = millis();
  
  while(btn_status == LOW)
  
  btn_status = digitalRead(pushBottone);
  long tempo_bottone = millis(); // restituisce i millisecondi necessari al led per essere spento dal bottone 
  check(led1);
  tempo_riflesso = tempo_bottone - tempo_led;
  Serial.println("Hai premuto il bottone dopo: ");
  Serial.println(tempo_riflesso);
  tempo_random = random(2000, 10000);
  delay(tempo_random);
  digitalWrite(beep, HIGH);
  long tempo_buzzer = millis();

  while(btn_status == LOW)
  
  btn_status = digitalRead(pushBottone);
  long tempo_bottone2 = millis();
  check(beep);
  tempo_riflesso_buzzer = tempo_bottone2 - tempo_buzzer;
  Serial.println("Hai premuto il bottone (con il buzzer) dopo: ");
  Serial.println(tempo_riflesso_buzzer);
  Serial.println("per restartare premere invio...");
  while(Serial.available() == 0);
  Serial.println("----------------------------------------");
}

void check(int a){
    if(btn_status == HIGH)
    {
      digitalWrite(a, LOW);
      btn_status = LOW;  
    }
  }

int pushBottone = 13; // input del BOTTONE
int led1 = 12; // LED
int beep = 11; 
int btn_status = 0; // si usa come variabile per indicare se il pulsante si premuto o meno e si utilizzerà nel corso del codice. (status del BOTTONE)
int tempo_random; // tempo RANDOM
int tempo_riflesso; // tempo del riflesso del LED
int tempo_riflesso_buzzer; // tempo del riflesso del BUZZER

void setup() {
  // put your setup code here, to run once:
pinMode(led1, OUTPUT);
pinMode(pushBottone, INPUT);
pinMode(beep, OUTPUT);
Serial.begin(9600);
}

void loop() { 
  
  Serial.println("INIZIO (i tempi sono misurati in millisecondi)...");
  tempo_random = random(2000, 10000); 
  delay(tempo_random);                  
  digitalWrite(led1, HIGH); 
  long tempo_led = millis(); // restituisce quando si accende il led1 (in millisecondi)
  while(btn_status == LOW)
  
  btn_status = digitalRead(pushBottone);
  long tempo_bottone = millis(); // restituisce il push del bottone
  check(led1);
  tempo_riflesso = tempo_bottone - tempo_led;
  Serial.println("Hai premuto il bottone dopo: ");
  Serial.println(tempo_riflesso);
  
  tempo_random = random(2000, 10000);
  delay(tempo_random);
  digitalWrite(beep, HIGH);
  long tempo_buzzer = millis(); // restituisce quando si accende il BUZZER (in millisecondi)
  while(btn_status == LOW)
  
  btn_status = digitalRead(pushBottone);
  long tempo_bottone2 = millis(); // restituisce il push del bottone
  check(beep);
  tempo_riflesso_buzzer = tempo_bottone2 - tempo_buzzer;
  Serial.println("Hai premuto il bottone (con il buzzer) dopo: ");
  Serial.println(tempo_riflesso_buzzer);
  Serial.println("premere invio per iniziare: ");
  while(Serial.available() == 0);
  Serial.println("-----------------");
}

void check(int a){
    if(btn_status == HIGH)
    {
      digitalWrite(a, LOW);
      btn_status = LOW;  
    }
  }

#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
int pushBottone_restart = 2;
int pushBottone = 3; // input del BOTTONE
int led1 = 4; // LED
int beep = 6; 
int btn_status = 1; // si usa come variabile per indicare se il pulsante si premuto o meno e si utilizzerà nel corso del codice. (status del BOTTONE)
int tempo_random; // tempo RANDOM
int tempo_riflesso; // tempo del riflesso del LED
int tempo_riflesso_buzzer; // tempo del riflesso del BUZZER

void setup() {
  // put your setup code here, to run once:
pinMode(led1, OUTPUT);
pinMode(pushBottone, INPUT);
pinMode(pushBottone_restart, INPUT);
pinMode(beep, OUTPUT);
Serial.begin(9600);
lcd.begin(16, 2);
}

void loop() { 
  // CONDIZIONI INIZIALI PER LO START CORRETTO DEL PROGRAMMA
  btn_status = HIGH;
  lcd.clear();
  digitalWrite(beep, LOW);
  
  // --------- SEZIONE DEDICATA AL LED --------- //
  Serial.println("INIZIO (i tempi sono misurati in millisecondi)...");
  lcd.print("INIZIO");
  tempo_random = random(2000, 10000); 
  delay(tempo_random);                  
  digitalWrite(led1, HIGH); 
  long tempo_led = millis(); // restituisce quando si accende il led1 (in millisecondi)
  
  while(btn_status == HIGH)
  btn_status = digitalRead(pushBottone);
  lcd.clear();
  long tempo_bottone = millis(); // restituisce il push del bottone
  check(led1);
  tempo_riflesso = tempo_bottone - tempo_led;
  lcd.setCursor(0, 0);
  lcd.print(tempo_riflesso);
  lcd.print("ms");
  lcd.print(" ");
  // --------- SEZIONE DEDICATA AL BUZZER --------- //
  tempo_random = random(2000, 10000);
  delay(tempo_random);
  digitalWrite(beep, HIGH);
  long tempo_buzzer = millis(); // restituisce quando si accende il BUZZER (in millisecondi)
  
  while(btn_status == HIGH) // DA CAMBIARE IN CASO NON FUNZIONI
  btn_status = digitalRead(pushBottone);
  long tempo_bottone2 = millis(); // restituisce il push del bottone
  check(beep);
  tempo_riflesso_buzzer = tempo_bottone2 - tempo_buzzer;
  lcd.print(tempo_riflesso_buzzer);
  lcd.print("ms ");
  lcd.setCursor(0, 1);
  if((tempo_riflesso + tempo_riflesso)/2 < 250)
  {
    lcd.print("POSITIVO");
    }
    else
    {
      lcd.print("NEGATIVO");
      }
  // --------- SEZIONE DEDICATA AL PULSANTE DI RESTART --------- //
  while(btn_status == HIGH)
  btn_status = digitalRead(pushBottone_restart);
  Serial.println();
  Serial.println("-----------------------------------");
}

void check(int a){
    if(btn_status == LOW)
    {
      digitalWrite(a, LOW);
      btn_status = HIGH;  
    }
  }

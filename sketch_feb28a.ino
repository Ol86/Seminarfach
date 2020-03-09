int Lightlevel = 0;
int Tasterstatus = 0;

void setup() {
  Serial.begin(9600);

  pinMode(7, OUTPUT); //Led
  pinMode(6, OUTPUT); //Led
  pinMode(9, INPUT);  //Knopf zum Ausschalten der Alarmanlage
}

void loop() {
  Lightlevel = analogRead(A0);
  Serial.print("Lightlevel = ");
  Serial.println(Lightlevel);
  //Wert vom Fotosensor wird ausgelesen und auf Lightlevel gespeichert
  
  while (Lightlevel <= 318) {
      if (Tasterstatus == HIGH) {
        Lightlevel = 350;  
      }
      else {
        digitalWrite(7,HIGH);
        digitalWrite(6,LOW);
        tone(8, 100);
        delay(250); 
        digitalWrite(7,LOW);
        digitalWrite(6,LOW);
        noTone(8);
        delay(250); 
        digitalWrite(7,LOW);
        digitalWrite(6,HIGH);
        tone(8, 200);
        delay(500); 
        digitalWrite(7,LOW);
        digitalWrite(6,LOW);
        noTone(8);
      }     
  }
}

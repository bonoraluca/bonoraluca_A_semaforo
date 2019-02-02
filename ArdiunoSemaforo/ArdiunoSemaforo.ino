int rosso = 2;
int giallo = 3;
int verde = 4;
int rosso_ = 5;
int giallo_ = 6;
int verde_ = 7;
int tempo;
int ripetizioni;
int durataVerde;
int durataGiallo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  quantoDuraVerde();
  quantoDuraGiallo();
  tempoLampeggi();
  quantiLampeggi();
  pinMode(rosso, OUTPUT);
  pinMode(giallo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(rosso_, OUTPUT);
  pinMode(giallo_, OUTPUT);
  pinMode(verde_, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (rosso_, LOW);
  digitalWrite (giallo_, LOW);
  digitalWrite (giallo, LOW);
  digitalWrite (rosso, HIGH);
  digitalWrite (verde_, HIGH);
  delay(durataVerde);
  
  digitalWrite (giallo, HIGH);
  lampeggia(verde_, tempo, ripetizioni);
  digitalWrite (giallo_, HIGH);
  delay(durataGiallo);

  digitalWrite (rosso, LOW);
  digitalWrite (giallo, LOW);
  digitalWrite (verde, HIGH);
  digitalWrite (giallo_, LOW);
  digitalWrite (rosso_, HIGH);
  delay(durataVerde);
  
  lampeggia(verde, tempo, ripetizioni);
  digitalWrite (giallo, HIGH);
  delay(durataGiallo);
  
}

void tempoLampeggi(){
  Serial.println ("quanto vuoi far durare il lampeggio?");
  while(Serial.available() == 0) {};
  tempo = Serial.readString().toInt();
}

void quantiLampeggi(){
  Serial.println ("quante volte vuoi far lampeggiare il verde?");
  while(Serial.available() == 0) {};
  ripetizioni = Serial.readString().toInt();
}

void quantoDuraVerde(){
  Serial.println ("quanto vuoi far durare il verde?");
  while(Serial.available() == 0) {};
  durataVerde = Serial.readString().toInt();
}

void quantoDuraGiallo(){
  Serial.println ("quanto vuoi far durare il giallo?");
  while(Serial.available() == 0) {};
  durataGiallo = Serial.readString().toInt();
}

void lampeggia(int led, int tempo, int ripetizioni) {
  for (int i = 0;i <= ripetizioni;i++)
  {
  digitalWrite (led,LOW);
  delay(tempo);
  digitalWrite (led,HIGH);
  delay(tempo);
  digitalWrite (led,LOW);
  }
}

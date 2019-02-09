//ASSEGNO LE VARIABILI
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
  //FUNZIONI DA ESEGUIRE ALL'INIZIO
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
  //FUNZIONI DA RIPETERE SEMPRE

  //SI SPENGONO IL GIALLO E IL ROSSO, E SI ACCENDE IL VERDE DEL PRIMO SEMAFORO; SI SPENGONO IL GIALLO E IL ROSSO DEL SECONDO SEMAFORO
  digitalWrite (rosso_, LOW);
  digitalWrite (giallo_, LOW);
  digitalWrite (giallo, LOW);
  digitalWrite (rosso, HIGH);
  digitalWrite (verde_, HIGH);
  //TEMPO DI DURATA DEL VERDE
  delay(durataVerde);

  //SI ACCENDE IL GIALLO DEL SECONDO SEMAFORO; IL VERDE LAMPEGGIA E SI SPEGNE IL GIALLO DEL PRIMO SEMAFORO
  digitalWrite (giallo, HIGH);
  lampeggia(verde_, tempo, ripetizioni);
  digitalWrite (giallo_, HIGH);
  //TEMPO DI DURATA DEL GIALLO
  delay(durataGiallo);

  //SPENGO IL ROSSO E IL GIALLO, ACCENDO IL VERDE DEL SECONDO SEMAFORO; SI SPEGNE IL GIALLO E SI ACCENDE IL ROSSO DEL PRIMO SEMAFORO
  digitalWrite (rosso, LOW);
  digitalWrite (giallo, LOW);
  digitalWrite (verde, HIGH);
  digitalWrite (giallo_, LOW);
  digitalWrite (rosso_, HIGH);
  //TEMPO DI DURATA DEL VERDE
  delay(durataVerde);

  //SI ACCENDE IL GIALLO DEL PRIMO, LAMPEGGIA IL VERDE E SI ACCENDE IL GIALLO DEL SECONDO
  digitalWrite (giallo_, HIGH);
  lampeggia(verde, tempo, ripetizioni);
  digitalWrite (giallo, HIGH);
  //TEMPO DI DURATA DEL GIALLO
  delay(durataGiallo);
  
}

//FUNZIONE PER METTERE IN INPUT IL TEMPO DEI LAMPEGGI 
void tempoLampeggi(){
  Serial.println ("quanto vuoi far durare il lampeggio?");
  while(Serial.available() == 0) {};
  tempo = Serial.readString().toInt();
}

//FUNZIONE PER METTERE IN INPUT QUANTI LAMPEGGI FARE
void quantiLampeggi(){
  Serial.println ("quante volte vuoi far lampeggiare il verde?");
  while(Serial.available() == 0) {};
  ripetizioni = Serial.readString().toInt();
}

//FUNZIONE PER METTERE IN INPUT QUANTO FAR DURARE IL VERDE
void quantoDuraVerde(){
  Serial.println ("quanto vuoi far durare il verde?");
  while(Serial.available() == 0) {};
  durataVerde = Serial.readString().toInt();
}

//FUNZIONE PER METTERE IN INPUT QUANTO FAR DURARE IL GIALLO
void quantoDuraGiallo(){
  Serial.println ("quanto vuoi far durare il giallo?");
  while(Serial.available() == 0) {};
  durataGiallo = Serial.readString().toInt();
}

//FUNZIONE PER FAR LAMPEGGIARE IL VERDE
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

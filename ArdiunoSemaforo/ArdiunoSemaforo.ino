int rosso = 1;
int giallo = 2;
int verde = 3;
int rosso_ = 4;
int giallo_ = 5;
int verde_ = 6;
int tempo = 100;
int ripetizioni=4;

void lampeggia(int led, int tempo, int ripetizioni) {
  for (int i = 0;i <= ripetizioni;i++)
  {
  digitalWrite (led,LOW);
  delay(tempo);
  digitalWrite (led,HIGH);
  delay(tempo);
  }
}

void setup() {
  // put your setup code here, to run once:
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
  digitalWrite (rosso, HIGH);
  digitalWrite (verde_, HIGH);
  delay(4600);

  digitalWrite (giallo, HIGH);
  digitalWrite (giallo_, HIGH);
  lampeggia(verde_, tempo, ripetizioni);

  digitalWrite (rosso, LOW);
  digitalWrite (giallo, LOW);
  digitalWrite (verde, HIGH);
  digitalWrite (rosso_, HIGH);
  delay(4600);
  
  lampeggia(verde, tempo, ripetizioni);
  digitalWrite (giallo, HIGH);
  delay(5000);
  
}

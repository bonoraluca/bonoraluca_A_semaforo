int rosso = 1
int giallo = 2
int verde = 3
int rosso_ = 4
int giallo_ = 5
int verde_ = 6

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
  digitalWrite (rosso, HIGH);
  digitalWrite (verde_, HIGH);
  digitalWrite (rosso_, LOW);
  delay (5000);
  digitalWrite (giallo_, HIGH);
  delay (5000);
  digitalWrite (rosso, LOW);
  digitalWrite (verde, HIGH);
  digitalWrite (verde_, LOW);
  digitalWrite (giallo_, LOW);
  digitalWrite (rosso_, HIGH);
  delay (5000);
  digitalWrite (giallo, HIGH);
  delay (5000);
  digitalWrite (verde, LOW);
  digitalWrite (giallo, LOW);
}

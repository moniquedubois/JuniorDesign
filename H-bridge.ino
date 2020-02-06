const int s1 = 2;
const int s2 = 3;
const int s3 = 4;
const int s4 = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//  double voltage = 5;
//  int vMap = map(voltage, 0, 5, 0, 255);
//  analogWrite(s2, vMap);
//  analogWrite(s3, vMap);
//  digitalWrite(s1, 0);
//  digitalWrite(s4, 0);
//  delay(8000);

//  //analogWrite(s2, vMap);
//  analogWrite(s4, vMap);
// // digitalWrite(s1, 0);
//  digitalWrite(s3, 0);
//  delay(8000);

//  // backwards
//  digitalWrite(s3, LOW);
//  digitalWrite(s4, HIGH);
//  digitalWrite(s2, LOW);
//  digitalWrite(s1, HIGH);

//  // forwards
//  digitalWrite(s3, LOW);
//  digitalWrite(s4, HIGH);
//  digitalWrite(s1, LOW);
//  digitalWrite(s2, HIGH);

//  //Turning Right
//  digitalWrite(s3, LOW);
//  digitalWrite(s4, LOW);
//  digitalWrite(s1, LOW);
//  digitalWrite(s2, HIGH);

  //Turning Left
  digitalWrite(s3, LOW);
  digitalWrite(s4, HIGH);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
}

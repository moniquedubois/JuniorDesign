const int vo = A0;
const int LED = 8;
void setup() {
  // put your setup code here, to run once:
  pinMode(vo, INPUT);
  pinMode(LED, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(LED, HIGH);
  int voValue = analogRead(vo);
  float voltage = voValue * (5.0/1023.0);
  Serial.println(voltage);
}

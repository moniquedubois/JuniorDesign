double voltage = 1.4;
double changeAmount = 0.2;
void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int vMap = map(voltage, 0, 5, 0, 255);
  analogWrite(8, vMap);
  voltage = voltage + changeAmount;
  if(voltage >= 3 || voltage <= 1.4)
  {
    changeAmount = -1 * changeAmount;
  }
  Serial.print(voltage);
  delay(2000);
}

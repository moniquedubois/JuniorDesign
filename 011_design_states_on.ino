int pink = 15;
int yellow = 12;
int white = 10;
int brightness = 240;
int fadeAmount = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(pink, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(white, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //On state 
  //pink blinks @10Hz 
//  digitalWrite(pink, HIGH);
//  delay(100);
//  digitalWrite(pink,LOW);
//  delay(100);

  //Off state
  //Does nothing 

  //Run state 
  //yellow fades then blink 0.5s 
   analogWrite(yellow, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness - fadeAmount;

  if(brightness <= 0)
  {
    digitalWrite(yellow, HIGH);
    delay(500);
    digitalWrite(yellow, LOW);
    delay(500);
    brightness = 240;
  }

  delay(30);

  //Sleep State
  // white  @4Hz for 1 sec fade for 1 sec
  
}

  
int red = 12;
int green = 11;
int blue = 10;
int pin1 = 2;
int pin2 = 3;
int pin3 = 4;
int brightness = 250;
int fadeAmount = 5;

int pin1State = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pin1State = digitalRead(pin1);
  //On state 
  //Red blinks @10Hz 
  if(pin1State = HIGH)
  {  
    digitalWrite(red, HIGH);
    delay(100);
    digitalWrite(red,LOW);
    delay(100);
  }
  //Off state
  //Does nothing 

  //Run state 
  //Green fades then blink 0.5s 
//   analogWrite(green, brightness);
//
//  // change the brightness for next time through the loop:
//  brightness = brightness - fadeAmount;
//
//  if(brightness <= 0)
//  {
//    digitalWrite(green, HIGH);
//    delay(500);
//    digitalWrite(green, LOW);
//    delay(500);
//    brightness = 250;
//  }
//
//  delay(30);

  //Sleep State
  //Blue blink  @4Hz for 1 sec fade for 1 sec
  
}

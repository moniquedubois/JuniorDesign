// Pin connection
// Output
// P10 - Blue LED
// P11 - Green LED
// P12 - Red LED
// Input
// P2 - Pin 2
// P3 - Pin 3
// P4 - Pin 4
// P20 - Pin 7 
// P21 - Pin 8 

// State representation (P2, P3, P4)
// On - 001
// off - 000
// Run - 010
// Sleep - 100
// Diagnostic - 101

const int red = 12;
const int green = 11;
const int blue = 10;
const int pin2 = 2;
const int pin3 = 3;
const int pin4 = 4;
const int pin7 = 20;
const int pin8 = 21;
const int poten1 = A0;
const int poten2 = A1;

int brightness = 250;
int fadeAmount = 5;
int sleep = 0;
int diagnos = 0;
int blinkSpeed = 100;
int pin2State = 0;
int pin3State = 0;
int pin4State = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);
  pinMode(pin7, INPUT_PULLUP);
  pinMode(pin8, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pin7), switch1, FALLING);
  attachInterrupt(digitalPinToInterrupt(pin8), switch2, RISING);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  pin2State = digitalRead(pin2);
  pin3State = digitalRead(pin3);
  pin4State = digitalRead(pin4);
  int redDelay = analogRead(poten1);
  int redBright = analogRead(poten2);
  redBright = map(redBright, 0, 1023, 0, 255);
  delay(30);
  //On state
  //Red blinks @10Hz
  if (pin4State == HIGH && pin3State == LOW && pin2State == LOW )
  {
    // Reset sleep and diagnos 
    sleep = 0;
    diagnos = 0;
    
    analogWrite(red, redBright);
    delay(redDelay);
    analogWrite(red, 0);
    delay(redDelay);
  }
  //Off state
  //Does nothing
  if (pin4State == LOW && pin3State == LOW && pin2State == LOW )
  {
    // Reset sleep and diagnos
      sleep = 0;
      diagnos = 0;
      digitalWrite(red, LOW);
      digitalWrite(blue, LOW);
      digitalWrite(green, LOW);
  }

  //Run state
  //Green fades then blink 0.5s
  if (pin4State == LOW && pin3State == HIGH && pin2State == LOW )
  {
    // Reset sleep
    sleep = 0;
    diagnos = 0;
    
    analogWrite(green, brightness);

    // change the brightness for next time through the loop:
    brightness = brightness - 25;

    if (brightness <= 0)
    {
      digitalWrite(green, HIGH);
      delay(500);
      digitalWrite(green, LOW);
      delay(500);
      brightness = 250;
    }

     digitalWrite(blue, HIGH);
     delay(blinkSpeed);
     digitalWrite(blue, LOW);
     delay(blinkSpeed);
   
    //delay(30);

    
  }

  //Sleep State
  //Blue blink  @4Hz for 1 sec fade for 1 sec
  if(pin4State == LOW && pin3State == LOW && pin2State == HIGH && sleep == 0)
  {  
    //Reset diagnos
    diagnos = 0;
    digitalWrite(blue, HIGH);
    delay(250);
    digitalWrite(blue, LOW);
    delay(250);
    digitalWrite(blue, HIGH);
    delay(250);
    digitalWrite(blue, LOW);
    delay(250);
    while (brightness >= 0)
    {
      analogWrite(blue, brightness);
      brightness = brightness - fadeAmount;
      delay(40);
    }
    brightness = 250;
    sleep = 1;
  }

  //Diagnostic State 
  //Red blinks N number of times for N list of problems 
  if(pin4State == HIGH && pin3State == LOW && pin2State == HIGH && diagnos == 0)
  { 
    // Reset sleep
    sleep = 0;
    int N = 5;
    for(int count = 0; count < N; count++)
    {
      digitalWrite(red, HIGH);
      delay(100);
      digitalWrite(red, LOW);
      delay(100);
    }
    diagnos = 1;
  }
  //  Serial.print(pin1State);
  //  Serial.print(pin2State);
  //  Serial.print(pin3State);
}

// Actions to perform when interrupt 1 triggered
// pin7 from Open to close 
// If at run state Blue LED flashes ten times 
void switch1()
{
  if (pin4State == LOW && pin3State == HIGH && pin2State == LOW )
  {
    blinkSpeed = 1000;
    digitalWrite(red,LOW);
  }
}

// Actions to perform when interrupt 2 triggered
// pin8 from close to open 
// If at run state Blue LED flashes ten times 
void switch2()
{
  if (pin4State == LOW && pin3State == HIGH && pin2State == LOW )
  {
    if(blinkSpeed == 100)
    {
      digitalWrite(red,HIGH);
    }
  }
}

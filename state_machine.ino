 // Pin connection
// Output
// P10 - Blue LED
// P11 - Green LED
// P12 - Red LED
// Input
// P2 - Pin 2
// P3 - Pin 3
// P4 - Pin 4

// State representation (P2, P3, P4)
// On - 001
// Sleep - 000
// Run - 010
// Sleep - 100
// Diagnostic - 101

const int red = 12;
const int green = 11;
const int blue = 10;
const int pin2 = 2;
const int pin3 = 3;
const int pin4 = 4;
int brightness = 250;
int fadeAmount = 5;
int sleep = 0;
int diagnos = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pin2State = digitalRead(pin2);
  int pin3State = digitalRead(pin3);
  int pin4State = digitalRead(pin4);

  //On state
  //Red blinks @10Hz
  if (pin4State = HIGH && pin3State = LOW && pin2State = LOW )
  {
    // Reset sleep and diagnos 
    sleep = 0;
    diagnos = 0;
    
    digitalWrite(red, HIGH);
    delay(100);
    digitalWrite(red, LOW);
    delay(100);
  }
  //Off state
  //Does nothing
  if (pin4State = LOW && pin3State = LOW && pin2State = LOW )
  {
    // Reset sleep and diagnos
      sleep = 0;
      diagnos = 0;
  }

  //Run state
  //Green fades then blink 0.5s
  if (pin4State = LOW && pin3State = HIGH && pin2State = LOW )
  {
    // Reset sleep
    sleep = 0;
    diagnos = 0;
    
    analogWrite(green, brightness);

    // change the brightness for next time through the loop:
    brightness = brightness - fadeAmount;

    if (brightness <= 0)
    {
      digitalWrite(green, HIGH);
      delay(500);
      digitalWrite(green, LOW);
      delay(500);
      brightness = 250;
    }

    delay(30);
  }

  //Sleep State
  //Blue blink  @4Hz for 1 sec fade for 1 sec
  if(pin4State = LOW && pin3State = LOW && pin2State = HIGH && sleep = 0)
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
    }
    brightness = 250;
    sleep = 1;
  }

  //Diagnostic State 
  //Red blinks N number of times for N list of problems 
  if(pin4State = HIGH && pin3State = LOW && pin2State = HIGH && diagnos = 0)
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

int PWMpin = 9;      // PWM out on digital pin 9
const int buttonPin = 2;  // the number of the pushbutton pin
const int PinLED = 3;    // the number of the LED pin
int analogPin = 0;   // potentiometer connected to A0
int val = 0;         // variable to store the read value
int estado = LOW;  // variable for reading the pushbutton status
int oldbuttonState = 0;
int newbuttonState = 0;

void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(PinLED, OUTPUT);              
  digitalWrite(PinLED, LOW);            
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT); 
  pinMode(PWMpin, OUTPUT); // sets the pin as output
}

void loop() {
  val = analogRead(analogPin);// read the potentiometer as 8 bit
  //Serial.println(val);
  val = map(val,0,1023,0,25500);
  val = val/100;
  analogWrite(PWMpin, val);
  Serial.println(val);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  newbuttonState = digitalRead(buttonPin);
  if(newbuttonState != oldbuttonState)
  {
    oldbuttonState = newbuttonState;
    if(newbuttonState == LOW)
    {
      estado = !estado;
      digitalWrite(PinLED, estado);
    }
  }
}
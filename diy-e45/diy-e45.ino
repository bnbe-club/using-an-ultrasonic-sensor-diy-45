/***********************************************************************************************************************************************************
 *  TITLE: This is an example skecth that will help you interface the HC-SR04 ultrasonic sensor to an Arduino compatible board.
 *
 *  By Frenoy Osburn
 *  YouTube Video: https://youtu.be/JIfKOMAU224
 ***********************************************************************************************************************************************************/

  /********************************************************************************************************************
 *  Board Settings:
 *  Board: "Arduino Nano"
 *  Processor: "ATmega328P (Old Bootloader)"
 *  COM Port: Depends *On Your System*
 *********************************************************************************************************************/
 
#define TRIGGER_PIN   7
#define ECHO_PIN      8

int echoTime;             //time in us
float distance;           //distance in mms

void setup() 
{
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  digitalWrite(TRIGGER_PIN, LOW);     //set trigger pin LOW - idle state

  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(TRIGGER_PIN, HIGH);    //send trigger pulse
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  echoTime = pulseIn(ECHO_PIN, HIGH); //capture the echo signal and determine duration of pulse when HIGH

  distance = (echoTime*0.034*10)/2;    //obtain distance (in mm), from time

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" mm"); 

  delay(500);                         //wait for sometime to prevent flooding the terminal
}

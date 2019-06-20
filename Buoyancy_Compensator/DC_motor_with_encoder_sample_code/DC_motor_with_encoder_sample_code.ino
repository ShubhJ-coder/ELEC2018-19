/***SAMPLE ENCODER CODE***/
//For example,with UNO board, you want to use interrupt port 0(int.0). 
//You should connect digital pin 2 with the board.
//See the link for detail http://arduino.cc/en/Reference/AttachInterrupt
//Encoder Resolution: 16CPR(motor shaft)/700CPR(gearbox shaft)

//The sample code for driving one way motor encoder
const byte encoder0pinA = 2;//A pin -> the interrupt pin 0
const byte encoder0pinB = 4;//B pin -> the digital pin 4
byte encoder0PinALast;
int duration;//the number of the pulses
boolean Direction;//the rotation direction
void setup()
{
Serial.begin(57600);//Initialize the serial port
EncoderInit();//Initialize the module
}
void loop()
{
Serial.print("Pulse:");
Serial.println(duration);
duration = 0;
delay(100);
}
void EncoderInit()
{
Direction = true;//default -> Forward
pinMode(encoder0pinB,INPUT);
attachInterrupt(0, wheelSpeed, CHANGE);
}
void wheelSpeed()
{
int Lstate = digitalRead(encoder0pinA);
if((encoder0PinALast == LOW) && Lstate==HIGH)
{
int val = digitalRead(encoder0pinB);
if(val == LOW && Direction)
{
Direction = false; //Reverse
}
else if(val == HIGH && !Direction)
{
Direction = true; //Forward
}
}
encoder0PinALast = Lstate;
if(!Direction) duration++;
else duration--;
}

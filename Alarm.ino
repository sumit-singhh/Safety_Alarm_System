const int trigpin = 7;
const int echopin = 6; 
int safeZone = 20; //for demontration purpose I have taken the range to be 20 cm, you can set it up between 2-400 cm
int tonepin=9;
int redled = 12;
 
void setup() {
  pinMode(trigpin, OUTPUT);  
  pinMode(redled, OUTPUT);  
  pinMode(tonepin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(9600);
}
 
void loop()
{
  int duration, cm;
   
   //sending the signal, starting with LOW for a clean signal
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigpin, LOW);
   
  duration = pulseIn(echopin, HIGH);
 
  cm = microsecondsToCentimeters(duration);
  
  if (cm > safeZone)
  {
    digitalWrite(redled, LOW);
  }
  else
  {
    digitalWrite(redled, HIGH);
   
    for(int i=0;i<20;i++)
    {
      tone(tonepin, 2000);   //you can change the sound by changing numbers.
      delay(30);      
    }
    noTone(tonepin);
  } 
  delay(100);
}
 
int microsecondsToCentimeters(int duration)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we take half of the distance travelled.
  return duration / 29 / 2;
}

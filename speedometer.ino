const int trigPin = 9;
const int echoPin = 10;
float w_length = 2.050;
volatile unsigned long lastturn, time_press;
volatile float SPEED;
volatile float DIST;
long duration;
int distance;
void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
Serial.begin(9600); 
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
  if (millis() - lastturn > 80 && distance < 8) {    
    SPEED = w_length / ((float)(millis() - lastturn) / 1000) * 3.6;  
    lastturn = millis();                                              
    DIST = DIST + w_length / 1000;
  Serial.println((String) "[Speed]" + SPEED + " km/h [Distance] " + DIST + " km ");    
    delay(150);  
  }
  else
  {
    digitalWrite(trigPin, LOW);
  }
  delay(90);             
}

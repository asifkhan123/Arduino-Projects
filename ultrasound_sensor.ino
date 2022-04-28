const int trigPin = 9;
const int echoPin = 10;

long duration;
int point = 1;
int distance;
unsigned long time;
int const buzzPin = 2;

void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT); 
Serial.begin(9600); 
}
void loop() {
digitalWrite(trigPin, LOW);
delay(60);
digitalWrite(trigPin, HIGH);
delay(60);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
if (distance <=22 && distance >=0){
  int score = point++;
time = millis();
int timer = time/1000;
Serial.println((String) "[" + timer + " seconds] Score: " + score + " points");
}
}


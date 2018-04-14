/*
 * UTA
 * 
 * Calculates distance between players hands and two ultrasonic sensors. Associates distance
 * to index in a list, which contains pitch values.
 * Left hand controls octave. Right hand controls notes within the octave.
 * 
 * created 14 April 2018
 * by Dallas Foglia
 * 
 */
 const int trigger1 = 12;
 const int echo1 = 13;
 const int trigger2 = 7;
 const int echo2 = 8;
 const int buzzer = 2;

 int dur, dist;
 
 
void setup() {
  pinMode(trigger1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trigger2, OUTPUT);
  pinMode(echo2, INPUT);
  Serial.begin(9600);
}

void loop() {
  SendEcho(trigger1, echo1);
  Serial.print("Value(Sensor 1):");
  Serial.println(dist);

  SendEcho(trigger2, echo2);
  Serial.print("Value(Sensor 2):");
  Serial.println(dist);
  tone(buzzer, 1000, 500);  
  delay(500);
}

void SendEcho(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  dur = pulseIn(echo, HIGH);
  dist = dur*0.034/2; //convert to centimeters
}


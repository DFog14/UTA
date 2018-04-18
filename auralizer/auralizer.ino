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

 #include "pitches.h"
 
//pins
const int trigger1 = 12;
const int echo1 = 13;
const int trigger2 = 7;
const int echo2 = 8;
const int buzzer = 2;

//pitch lists
int octave1[] = {NOTE_C1, NOTE_CS1, NOTE_D1, NOTE_DS1, NOTE_E1, NOTE_F1, NOTE_FS1, NOTE_G1, NOTE_GS1, NOTE_A1, NOTE_AS1, NOTE_B1};
int octave2[] = {NOTE_C2, NOTE_CS2, NOTE_D2, NOTE_DS2, NOTE_E2, NOTE_F2, NOTE_FS2, NOTE_G2, NOTE_GS2, NOTE_A2, NOTE_AS2, NOTE_B2};
int octave3[] = {NOTE_C3, NOTE_CS3, NOTE_D3, NOTE_DS3, NOTE_E3, NOTE_F3, NOTE_FS3, NOTE_G3, NOTE_GS3, NOTE_A3, NOTE_AS3, NOTE_B3};
int octave4[] = {NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4, NOTE_B4};
int octave5[] = {NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_AS5, NOTE_B5};
int octave6[] = {NOTE_C6, NOTE_CS6, NOTE_D6, NOTE_DS6, NOTE_E6, NOTE_F6, NOTE_FS6, NOTE_G6, NOTE_GS6, NOTE_A6, NOTE_AS6, NOTE_B6};
int octave7[] = {NOTE_C7, NOTE_CS7, NOTE_D7, NOTE_DS7, NOTE_E7, NOTE_F7, NOTE_FS7, NOTE_G7, NOTE_GS7, NOTE_A7, NOTE_AS7, NOTE_B7};
int* octave_select[] = {octave1, octave2, octave3, octave4, octave5, octave6, octave7};

int dur, dist, oct_index, oct, note_index;
 
 
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
  oct_index = GetOctave(dist);
  Serial.println(oct_index);

  SendEcho(trigger2, echo2);
  Serial.print("Value(Sensor 2):");
  Serial.println(dist);
  note_index = GetNote(dist);
  Serial.println(octave_select[oct_index][note_index]);
  //tone(buzzer, octave_select[oct_index][note_index]);
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

//35cm / 7octaves = 5cm per octave
int GetOctave(int distance) {
  if(distance > 0 && distance <= 5) {
    return 0;
  }
  else if(distance > 5 && distance <= 10) {
    return 1;
  }
  else if(distance > 10 && distance <= 15) {
    return 2;
  }
  else if(distance > 15 && distance <= 20) {
    return 3;
  }
  else if(distance > 20 && distance <= 25) {
    return 4;
  }
  else if(distance > 30 && distance <= 35) {
    return 5;
  }
  else if(distance > 35 && distance <= 40) {
    return 6;
  }
}
//36cm / 12notes = 3cm per note
int GetNote(int distance) {
  if(distance > 0 && distance <= 3) {
    return 0;
  }
  else if(distance > 3 && distance <= 6) {
    return 1;
  }
  else if(distance > 6 && distance <= 9) {
    return 2;
  }
  else if(distance > 9 && distance <= 12) {
    return 3;
  }
  else if(distance > 12 && distance <= 15) {
    return 4;
  }
  else if(distance > 15 && distance <= 18) {
    return 5;
  }
  else if(distance > 18 && distance <= 21) {
    return 6;
  }
  else if(distance > 21 && distance <= 24) {
    return 7;
  }
  else if(distance > 24 && distance <= 27) {
    return 8;
  }
  else if(distance > 27 && distance <= 30) {
    return 9;
  }
  else if(distance > 30 && distance <= 33) {
    return 10;
  }
  else if(distance > 33 && distance <= 36) {
    return 11;
  }
}


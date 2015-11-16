/*
  
 */
#include <toneAC.h>
#include "pitches.h"

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

//notesinthemelody:
//Mario Theme
//int melody[]={NOTE_E7,NOTE_E7,0,NOTE_E7,0,NOTE_C7,NOTE_E7,0,NOTE_G7,0,0,0,NOTE_G6,0,0,0,NOTE_C7,0,0,NOTE_G6,0,0,NOTE_E6,0,0,NOTE_A6,0,NOTE_B6,0,NOTE_AS6,NOTE_A6,0,NOTE_G6,NOTE_E7,NOTE_G7,NOTE_A7,0,NOTE_F7,NOTE_G7,0,NOTE_E7,0,NOTE_C7,NOTE_D7,NOTE_B6,0,0,NOTE_C7,0,0,NOTE_G6,0,0,NOTE_E6,0,0,NOTE_A6,0,NOTE_B6,0,NOTE_AS6,NOTE_A6,0,NOTE_G6,NOTE_E7,NOTE_G7,NOTE_A7,0,NOTE_F7,NOTE_G7,0,NOTE_E7,0,NOTE_C7,NOTE_D7,NOTE_B6,0,0};
//int noteDurations[]={12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,9,9,9,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,9,9,9,12,12,12,12,12,12,12,12,12,12,12,12,};

//Final Fantasy Fanfare
int melody[] = { NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_G4}; 
int noteDurations[] = {8, 8, 8,4,4,4,8,8,2};


void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    soundMusic();//Play Music
  } 
}

void soundMusic() {
  // iterate over the notes of the melody:

  int size = sizeof(melody) / sizeof(int);
  for (int thisNote = 0; thisNote < size; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];


    toneAC(melody[thisNote], 2, noteDuration, true); // Melody, volume, play in background
    delay(noteDuration * 4 / 3); // Wait while the tone plays in the background, plus another 33% delay between notes.
    
  }

  

}


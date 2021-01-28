#define RED 2
#define GREEN 3
#define BLUE 4

#include "IRremote.h"

int receiver = 12;

IRrecv irrecv(receiver);
decode_results results;

void setup() {
  Serial.begin(9600);

  irrecv.enableIRIn(); //start the receiver
  
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);

}

void loop() {

  if(irrecv.decode(&results)) {
    
    switch(results.value){
      //NEED TO FIND VALUES FOR REMOTE BUTTONS
      case 0xFF629D: //VOL + on remote
        digitalWrite(RED,HIGH); 
        delay(1000); 
        break;

      case 0xFFA857:
        digitalWrite(BLUE, HIGH);
        delay(1000);
        break;
    }

    irrecv.resume();
    digitalWrite(RED, LOW);
    digitalWrite(BLUE, LOW);
    digitalWrite(GREEN, LOW);
  }
  
//want to add a DC motor that powers on and off based off the controller. Maybe speed aswell

}

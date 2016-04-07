/*
 * Released under the Creative Commons 
 * Attribution Share-Alike 3.0 License
 * https://creativecommons.org/licenses/by-sa/3.0/
 * 
 * Douglas M. Reilly
 * 4/7/2016
*/


/*
 * Device Modes
 * -------------------
 * 0      All Off
 * 1      LedArray1 Pulse
 * 2      LedArray2 Pulse
 * 3      LedArray3 Pulse
*/

const int button_pin       =   0;
const int ledArray1_pin    =   1;
const int ledArray2_pin    =   2;
const int ledArray3_pin    =   3;

int currentMode            =   0;
int buttonState_current    =   0;
int buttonState_previous   =   0;
int pulseState             = LOW;

const long pulseRate       = 500; 

unsigned long currentTime  =   0;
unsigned long previousTime =   0; 



void setup() {
  pinMode(button_pin,     INPUT);
  pinMode(ledArray1_pin, OUTPUT);
  pinMode(ledArray2_pin, OUTPUT);
  pinMode(ledArray3_pin, OUTPUT);
}

void loop() {
  buttonState_current  = digitalRead(button_pin);
  currentTime          = millis();

  if(timeDelta(currentTime, previousTime) >= pulseRate){
    if(currentMode == 0){
      //All off
    }
    if(currentMode == 1){
      if(pulseState == LOW){pulseState = HIGH;}
                       else{pulseState = LOW;}
      digitalWrite(ledArray1_pin, pulseState);
    }
    if(currentMode == 2){
      if(pulseState == LOW){pulseState = HIGH;}
                       else{pulseState = LOW;}
      digitalWrite(ledArray2_pin, pulseState);
    }
    if(currentMode == 3){
      if(pulseState == LOW){pulseState = HIGH;}
                       else{pulseState = LOW;}
      digitalWrite(ledArray3_pin, pulseState);
    }    
  }

  if(buttonState_current != buttonState_previous){
    if(currentMode == 3){currentMode = 0;}
    else{currentMode++;}
    All_Off();   
  }

  
  previousTime         = currentTime;
  buttonState_previous = buttonState_current;
}

unsigned long timeDelta(long t2, long t1){
  int diff = t2 - t1;
  return diff;
}

void All_Off(){
  digitalWrite(ledArray1_pin, LOW);
  digitalWrite(ledArray2_pin, LOW);
  digitalWrite(ledArray3_pin, LOW);
}
void All_On(){
  digitalWrite(ledArray1_pin, HIGH);
  digitalWrite(ledArray2_pin, HIGH);
  digitalWrite(ledArray3_pin, HIGH);
}



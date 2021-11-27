/*
 * Released under the Creative Commons 
 * Attribution Share-Alike 3.0 License
 * https://creativecommons.org/licenses/by-sa/3.0/
 * 
 * Autumn Reilly
 * 4/8/2016
*/


/*
 * Device Modes
 * -------------------
 * 0      All Off
 * 1      LedArray1 Pulse
 * 2      LedArray2 Pulse
 * 3      LedArray3 Pulse
*/

const int button_pin       =   2;
const int ledArray1_pin    =   3;
const int ledArray2_pin    =   4;
const int ledArray3_pin    =   5;

int currentMode            =   0;
int buttonState_current    =   0;
int buttonState_previous   =   0;
int pulseState             = LOW;

const long pulseRate       = 500; 

unsigned long currentTime  =   0;
unsigned long previousTime =   0; 



void setup() {
  Serial.begin(9600);
  Serial.println("Device ON");
  pinMode(button_pin,     INPUT);
  pinMode(ledArray1_pin, OUTPUT);
  pinMode(ledArray2_pin, OUTPUT);
  pinMode(ledArray3_pin, OUTPUT);
  Startup_Sequence();
}

void loop() {
  buttonState_current  = digitalRead(button_pin);
  currentTime          = millis();
//  Serial.println(buttonState_current);

//  Serial.println(timeDelta(currentTime, previousTime)); //Debug

  if(timeDelta(currentTime, previousTime) >= pulseRate){
    previousTime = currentTime;
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

  if((buttonState_current == 1) && (buttonState_current != buttonState_previous)){
    previousTime = currentTime;
    Serial.println(currentMode);
    if(currentMode == 3){currentMode = 0;}
    else{currentMode++;}
    All_Off();   
  }

  
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
void Startup_Sequence(){
  digitalWrite(ledArray1_pin, HIGH);
  delay(500);
  digitalWrite(ledArray2_pin, HIGH);
  delay(500);
  digitalWrite(ledArray3_pin, HIGH);
  delay(500);
  All_Off();
  for(int i = 0;i < 10;i++){
   All_On();
   delay(50);
   All_Off();
   delay(50); 
  }
  delay(100);
  for(int i = 0;i < 2;i++){
   All_On();
   delay(50);
   All_Off();
   delay(50); 
  }  
}

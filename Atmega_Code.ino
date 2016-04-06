/*
 * Device Modes
 * -------------------
 * 0      LedArray1 ON
 * 1      LedArray2 ON 
 * 2      LedArray3 ON
 * 3           All Off
 */

const int button_pin    = 0;
const int ledArray1_pin = 1;
const int ledArray2_pin = 2;
const int ledArray3_pin = 3;

int currentMode          = 0;
int buttonState_current  = 0;
int buttonState_previous = 0;


void setup() {
  pinMode(button_pin,     INPUT);
  pinMode(ledArray1_pin, OUTPUT);
  pinMode(ledArray2_pin, OUTPUT);
  pinMode(ledArray3_pin, OUTPUT);
}

void loop() {
  buttonState_current  = digitalRead(button_pin);
  if(buttonState_current != buttonState_previous){
    All_Off();
    if(currentMode == 3){
      currentMode=0;
    } 
    else{
      currentMode++;
    }
  }    

  buttonState_previous = buttonState_current;
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



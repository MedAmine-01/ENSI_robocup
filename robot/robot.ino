#define rm1 5
#define rm2 6
#define lm1 9
#define lm2 10

#define ch1 2


int duration1;
int duration2;

int stickX;
int stickY;


void readPulse(){
  duration1=pulseIn(ch1, HIGH);
  duration2=pulseIn(ch2, HIGH);
  stickX = map(duration1, 1000, 2000, -255, 255);
  stickY = map(duration2, 1000, 2000, -255, 255);
}

void calculPWM(){
  leftMotorPWM = stickY;          
  rightMotorPWM = stickY;                 
  leftMotorPWM += stickX;        
  rightMotorPWM -= stickX;   
  leftMotorPWM = constrain(leftMotorPWM,-255,255);
  leftMotorPWM = constrain(leftMotorPWM,-255,255);   
}



void loop() {
  // put your main code here, to run repeatedly:

}

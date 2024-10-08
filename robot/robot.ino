#define rm1 5
#define rm2 6
#define lm1 9
#define lm2 10

#define ch1 11
#define ch2 12


int duration1;
int duration2;

int stickX;
int stickY;

int leftMotorPWM;
int rightMotorPWM;


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
  rightMotorPWM = constrain(rightMotorPWM,-255,255);   
}


void move(){
  if (leftMotorPWM>0){
    analogWrite(lm1,leftMotorPWM);
    analogWrite(lm2,0);
  }
  else{
    analogWrite(lm1,0);
    analogWrite(lm2,abs(leftMotorPWM));
  }
  if (rightMotorPWM>0){
    analogWrite(rm1,rightMotorPWM);
    analogWrite(rm2,0);
  }
  else{
    analogWrite(rm1,0);
    analogWrite(rm2,abs(rightMotorPWM));
  }
}


void setup(){
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(ch1, INPUT);
  pinMode(ch2, INPUT);
  Serial.begin(9600);
}

void loop() {
  readPulse();
  calculPWM();
  Serial.print(rightMotorPWM);
  Serial.print("    ");
  Serial.println(leftMotorPWM);
  move();
  delay(100);
}
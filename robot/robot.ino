#define rm1 6
#define rm2 7
#define lm1 8
#define lm2 9

#define ch1 2

int duration1;


void readPulse(){
  duration1=pulseIn(ch1, HIGH);
  if(duration1>1500){
    duration1 = map(duration1, 1500, 2000, 0, 255);
  }
  else {
     duration1 = map(duration1, 1500, 2000, 0, -255);
  }
  Serial.println(duration1);
  delay(100);
}

void forward(){
  digitalWrite(rm1, HIGH);
  digitalWrite(rm2, LOW);

  digitalWrite(lm1, HIGH);
  digitalWrite(lm2, LOW);
}

void backward(){
  digitalWrite(rm1, LOW);
  digitalWrite(rm2, HIGH);

  digitalWrite(lm1, LOW);
  digitalWrite(lm2, HIGH);
}

void left(){
  digitalWrite(rm1, HIGH);
  digitalWrite(rm2, LOW);

  digitalWrite(lm1, LOW);
  digitalWrite(lm2, HIGH);
}


void right(){
  digitalWrite(rm1, LOW);
  digitalWrite(rm2, HIGH);

  digitalWrite(lm1, HIGH);
  digitalWrite(lm2, LOW);
}


void stop(){
  digitalWrite(rm1, LOW);
  digitalWrite(rm2, LOW);

  digitalWrite(lm1, LOW);
  digitalWrite(lm2, LOW);
}


void setup() {
  // put your setup code here, to run once:
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}

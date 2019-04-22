volatile unsigned long t1;
volatile int rev = 0;
unsigned long t2 = 0;
unsigned long mph = 0;
int interruptPin = 2;
unsigned long t = 0;
unsigned long circIn = 0;
unsigned long circMile = 0;
unsigned long RPMicro = 0;
unsigned long RPMin = 0;
unsigned long RPHour = 0;


void setup() {
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), ISR, FALLING);
  Serial.begin(9600);
}

void loop() {
  
 if(rev == 1)
 {   
    t = t1-t2;
    circIn = 20*3.14;
    RPMicro = 60/t;
    RPMin = RPMicro * .0000000166666667;
    RPHour = RPMin * 60;
    circMile = circIn * .0000157828;
    mph = circMile*RPHour;
    Serial.println(mph);
    t1 = t2;
    rev = 0;
 }
  
}

void ISR() {
  
  t1 = millis();
  rev++;
}

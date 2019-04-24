volatile unsigned long t1;//newest time volatile so it can be changed during ISR unsigned long because micros function type
unsigned long t2 = 0;//older time to be compared to 
volatile int rev = 0;//ISR int counter so only non zero values of speed are calculated
unsigned long mph = 0;//Final output
int interruptPin = 2;//pin declaration
unsigned long circIn = 0;//circumference in inches
unsigned long tDelt = 0;//rotational period
unsigned long IPMin = 0;//Inches travelled per minute
unsigned long RPMin = 0;//Rotations per minute
unsigned long RPHour = 0;//Rotations per hour
unsigned long Diam = 20;//Diameter declaration


void setup() {
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), time, FALLING);
  Serial.begin(9600);
}

void loop() {
  
 if(rev == 1)
 {   
    tDelt = t1-t2;//finding period
    RPMin = (60*1000*1000)/tDelt;//finding rotations per minute from microseconds
    //RPHour = RPMin*60;
    circIn = Diam*3.14; //circumference of the tire aka distance traveled per rotation
    IPMin = circIn*RPMin; //Inches traveled per minute
    mph = IPMin/63360;// final mph calculation
    Serial.println(mph);//printing speed
    t2 = t1;//changing newest time to last time to compare to 
    rev = 0;//resetting counter so next interrupt will be calculated
 }
  
}

void time() {
  
  t1 = micros();//taking in newest time during ISR
  rev++;//incrementing counter
}

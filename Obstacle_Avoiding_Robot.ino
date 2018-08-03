int trig = 8, echo = 9, counter =0;       // Declaring values for ultrasonic module
long duration = 20, number;
int distance = 20, blinking;
int pos = 0, value = 0;





#include <IRremote.h>                   // Initializing the IR Remote
const int irReceiverPin = 2;
IRrecv irrecv(irReceiverPin);
decode_results results;

#include <AccelStepper.h>
#include <Servo.h>
Servo myservo; 

// Motor pin definitions
#define motorPin1  3                // IN1 on the ULN2003 driver 1
#define motorPin2  4                // IN2 on the ULN2003 driver 1
#define motorPin3  5                // IN3 on the ULN2003 driver 1
#define motorPin4  6                // IN4 on the ULN2003 driver 1

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper stepper1(8, motorPin1, motorPin3, motorPin2, motorPin4);

void setup() {


  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  myservo.attach(11);
  irrecv.enableIRIn();

  stepper1.setMaxSpeed(-1000.0);           // Setting up the initial instructions to the stepper motor
  stepper1.setAcceleration(-200.0);
  stepper1.setSpeed(-200);
  stepper1.moveTo(-20000);
  
}


void loop() {

  if (irrecv.decode(&results))                                    // Starts the receiver module
{
if (results.value == 16750695 || value == 16750695){              // The code for the Start button on the IR Remote

value == 16750695;
  
}
  
  else if (results.value == 16726215 || value == 16726215){       // The code for the Stop button on the IR Remote
    value = 16726215;



if (distance == 200){

stepper1.setMaxSpeed(1000.0);
  stepper1.setAcceleration(800.0);
  stepper1.setSpeed(800);
  stepper1.moveTo(800);
  

   
if (stepper1.distanceToGo() == 0) {
    distance = 20;
  }

  stepper1.run();
 
}
else if (distance != 200){

 
digitalWrite(trig, LOW);
delayMicroseconds(2);           // To clear the sensor


digitalWrite(trig, HIGH);
delayMicroseconds(10);   
digitalWrite(trig, LOW);


duration = pulseIn(echo, HIGH, 12000);                    // Waits for 12000 microseconds before skipping that value

distance = ((duration)*0.034)/2;                          // Calculation for converting raw data to distance in centimeters

if (distance > 210){                                      // If sensor returns garbage values, reduce to 50 cm
  distance = 50;
}


}

if (distance <= 5){                                         // If distance is less than 5 cm, move stepper motor backwards



  stepper1.setMaxSpeed(1000.0);
  stepper1.setAcceleration(800.0);
  stepper1.setSpeed(800);
  stepper1.moveTo(800);
  distance = 200;

if (stepper1.distanceToGo() == 0) {
    distance = 20;
  }

  
  stepper1.run();

 
}
else if (distance > 5 && distance != 200){                  // If distance is greater than 5 cm, move stepper motor forwards

  
  stepper1.setMaxSpeed(-1100.0);
  stepper1.setAcceleration(-900.0);
  stepper1.setSpeed(-900);
  stepper1.moveTo(-20000000);
  stepper1.run();
  
}



if (distance < 5 || distance == 200){                       // If stepper motor is moving backwards, then move servo motor to steer rear axle



pos = 40;
myservo.write(pos);
 
}
else if (distance > 5)                                      // When distance is greater than 5 cm, return to original position
{
  pos = 0;
  myservo.write(pos);
}

  


  
}
}
}

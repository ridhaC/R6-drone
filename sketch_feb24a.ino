using namespace std;
class Motor {

  public:
    unsigned int in1;
    unsigned int in2;
    unsigned int en;
    Motor(int in1, int in2, int en) {
      // setting all variables
      this -> in1 = in1;
      this -> in2 = in2;
      this -> en = en;
    }

    void init() {
      // marking arduino pins as outputs
      pinMode(en, OUTPUT);
      pinMode(in1, OUTPUT);
      pinMode(in2, OUTPUT);
      
      //setting motor direction
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
    }
    
    void setPower(float power)  {
      if(power > 0) {
        setDirection(true);
        analogWrite(en, power * 255);
      }
      else  {
        setDirection(false);
        analogWrite(en, power * 255);
      }
    }

    void stop() {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
    }

    void setDirection(bool forward) {
      if(forward) {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
      }
      else  {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
      }
    }
};


Motor leftMotor(11, 12, 13);

Motor rightMotor(2, 3, 4);
 
void setup() {
  leftMotor.init();
  rightMotor.init();
}



 
void demoOne() {
  leftMotor.setPower(1);
  rightMotor.setPower(1);
  
  delay(2000);
 
  // Now change motor directions
  leftMotor.setPower(-1);
  rightMotor.setPower(-1);
  delay(2000);
 
  // Now turn off motors
  leftMotor.stop();
  rightMotor.stop();
 
}
 
void demoTwo() {

  // This function will run the motors across the range of possible speeds
  // Note that maximum speed is determined by the motor itself and the operating voltage

  // Accelerate from zero to maximum speed

  for (float i = 0; i < 1; i += 0.01)
  {
    leftMotor.setPower(i);
    rightMotor.setPower(i);
    delay(20);
  } 

  // Decelerate from maximum speed to zero

  for (int i = 255; i >= 0; --i)
  {
    leftMotor.setPower(i);
    rightMotor.setPower(i);
    delay(20);
  } 
  
  leftMotor.stop();
  rightMotor.stop();
}
 
void loop() {
  demoOne();
 
  delay(1000);
 
  demoTwo();
 
  delay(1000);
}

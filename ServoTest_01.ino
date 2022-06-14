#include <Servo.h>

int PIN_SERVO_1 = 9;
Servo gServo;
int pos;
int dir;

void setup() {
  Serial.begin(115200);
  gServo.attach(PIN_SERVO_1);
  pos = 0;
  dir = 1;
}

void loop() {
  Serial.print("Moving to : ");
  Serial.println(pos, DEC);
  
  gServo.write(pos);
  delay(300);
  
  if( pos >= 180 ) {
    dir = -1;
  }
  else if ( pos <= 0 ){
    dir = 1;
  }

  pos = pos + dir * 10;
}

// *********************************************************************
// CAN package definition
//
// device id: 0x168
//
// [0]: angle X
// [1]: angle Y
// *********************************************************************
#include <SPI.h>
#include <mcp2515.h>
#include <Servo.h>

#define CAN_SLAVE_ID    0x168

struct can_frame canMsg;
MCP2515 mcp2515(10);


#define SERVO_PIN_X     6
#define SERVO_PIN_Y     5

Servo servoX;
Servo servoY;

void setup() {
  Serial.begin(115200);
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS);
  mcp2515.setNormalMode();

  servoX.attach(SERVO_PIN_X);
  servoY.attach(SERVO_PIN_Y);
  
  Serial.println("------- CAN Read ----------");
}

void loop() {
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) {
    Serial.print(canMsg.can_id, HEX); // print ID
    Serial.print(" "); 
    Serial.print(canMsg.can_dlc, HEX); // print DLC
    Serial.print(" ");
    
    for (int i = 0; i<canMsg.can_dlc; i++)  {  // print the data
      Serial.print(canMsg.data[i],HEX);
      Serial.print(" ");
    }

    Serial.println();      

    if( CAN_SLAVE_ID == canMsg.can_id ) {
      // correct package
      Serial.print("Rotate: (x, y) -> ");
      Serial.print(canMsg.data[0]);
      Serial.print(", ");
      Serial.println(canMsg.data[1]);

      if( canMsg.data[0] <= 180 )
        servoX.write(canMsg.data[0]);
      if( canMsg.data[1] <= 180 )
        servoY.write(canMsg.data[1]);
    }
  }
}

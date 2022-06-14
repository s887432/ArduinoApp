#define UP 2
#define RIGHT 3
#define DOWN 4
#define LEFT 5
#define E 6
#define F 7
#define Joy_BT 8
#define Joy_X A0
#define Joy_Y A1

#define NUM_OF_BTNS   7
int bottons[]={UP,RIGHT,DOWN,LEFT,E,F,Joy_BT};
 
void setup() {
  Serial.begin(115200);
  for(int i=0;i<NUM_OF_BTNS;i++)
    pinMode(bottons[i],INPUT);
}

void loop() {
  Serial.print("UP:");
  Serial.print(digitalRead(UP));
  
  Serial.print("  RIGHT:");
  Serial.print(digitalRead(RIGHT));
  
  Serial.print("  DOWN:");
  Serial.print(digitalRead(DOWN));
  
  Serial.print("  LEFT:");
  Serial.print(digitalRead(LEFT));
  
  Serial.print("  E:");
  Serial.print(digitalRead(E));
  
  Serial.print("  F:");
  Serial.print(digitalRead(F));
  
  Serial.print("  Joy_BT:");
  Serial.print(digitalRead(Joy_BT));
  
  Serial.print("  Joy_X:");
  Serial.print(analogRead(Joy_X));
  
  Serial.print("  Joy_Y:");
  Serial.println(analogRead(Joy_Y));

  delay(500); 
}

// end of file

#define A_1A 8 // A_1A控制A馬達的前進（HIGH）、後退（LOW）
#define A_1B 9 // A_1B控制A馬達的速度 0~255 ，LOW表示停止

#define Speed 150 //設定前進速度


void setup() {
    pinMode(A_1A,OUTPUT);
    pinMode(A_1B,OUTPUT);
    digitalWrite(A_1A,LOW);
    digitalWrite(A_1B,LOW);
}

//車子停止
void stopcar(){
    digitalWrite(A_1A,LOW);
    digitalWrite(A_1B,LOW);
}

//車子向前走
void forward(){
    digitalWrite(A_1A,HIGH);
    analogWrite(A_1B,Speed);
}

//車子向後走
void backward(){
    digitalWrite(A_1A,LOW);
    analogWrite(A_1B,Speed);
}

void loop() {
    forward();
    delay(2000);
    stopcar();
    delay(2000);
}
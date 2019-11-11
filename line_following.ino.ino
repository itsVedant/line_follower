const int IRPinR= 4;
const int IRPinL= 2;
const int MotorPinL = 7;
const int MotorPinR = 12;
  int valueL, valueR, valueNewR = 0, valueNewL = 0;

void setup() {
 pinMode(IRPinR, INPUT); 
 pinMode(IRPinL, INPUT);
 pinMode(MotorPinL, OUTPUT);
 pinMode(MotorPinR, OUTPUT);
 
 Serial.begin(9600);
 valueL = digitalRead(IRPinL);
 valueR = digitalRead(IRPinR);

}

void loop() {
  valueL = digitalRead(IRPinL); 
  valueR = digitalRead(IRPinR);
     //Serial.println(valueR);
     Serial.println(valueL);

    if (valueL == 0 && valueR == 0) {
      moveForward();
    } else if (valueL == 0 && valueR == 1){
      moveRight();
    } else if (valueL == 1 && valueR == 0) {
      moveLeft();
    } else {
      moveNull();
    }
}

void moveForward() {
  analogWrite(MotorPinL, 255);
  analogWrite(MotorPinR, 255);
}

void moveLeft() {
  analogWrite(MotorPinL, 0);
  analogWrite(MotorPinR, 255);
}

void moveRight() {
  analogWrite(MotorPinL, 255);
  analogWrite(MotorPinR, 0);
}

void moveNull() {
  analogWrite(MotorPinL, 0);
  analogWrite(MotorPinR, 0);
}

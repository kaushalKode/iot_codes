#define soil_moisture_pin A0
#include <Servo.h>

Servo servo;
#define ir1Pin D0
#define ir2Pin D5


int moist = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  servo.attach(5); //d1
  servo.write(35);

  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ir1 = digitalRead(ir1Pin);
  int ir2 = digitalRead(ir2Pin);

  Serial.print("ir_data : ");
  Serial.print(ir1);
  Serial.print(",");
  Serial.print(ir2);
  Serial.println();


  if(ir1 == 0 ){
    moist = analogRead(soil_moisture_pin); 
    Serial.print("moist : ");
    Serial.println(moist);
    if(moist < 1000) {
      servo.write(90);
      delay(2000);
      servo.write(35);
    } else {
      servo.write(-50);
      delay(2000);
      servo.write(35);
    }
  }
   else {
      servo.write(35);
    }

    delay(2500);
}

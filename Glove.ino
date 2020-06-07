
//for glove


#include <SoftwareSerial.h>
#include <GY6050.h>
#include <Wire.h>


int X = 0;
int Y = 0;
GY6050 gyro(0x68);
SoftwareSerial BTserial(11, 10);



void setup() {

  Serial.begin(9600);
  BTserial.begin(38400);

  Wire.begin();
  gyro.initialisation();
  delay(2500);
}

void loop() {

  X = gyro.refresh('A', 'X');
  Y = gyro.refresh('A', 'Y');
  if (X > -10 && X < 10 && Y > -10 && Y < 10)
  {
    BTserial.write('S');
  }
  if (X < -50 && Y > -10 && Y < 10)
  {
    BTserial.write('F');
  }
  if (X > 50 && Y > -10 && Y < 10)
  { BTserial.write('B');
  }
  if (Y < -50 && X > -10 && X < 10)
  {
    BTserial.write('R');
  }
  if (Y > 50 && X > -10 && X < 10)
  {
    BTserial.write('L');
  }
  if (Y < -50 && X < -30)
  {
    BTserial.write('N');  //right+forward
  }
  if (Y < -50 && X > 30)
  {
    BTserial.write('M');   //R+B
  }

  if (Y > 50 && X < -30)
  {
    BTserial.write('O');    //L+F
  }
  if (Y > 50 && X > 40)
  {
    BTserial.write('P');    //L+B
  }

}

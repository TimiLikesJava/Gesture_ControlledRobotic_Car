//for car



#include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 11);

int state = 0;

void setup() {




  Serial.begin(9600);
  BTserial.begin(38400);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

}

void loop() {

  if (BTserial.available() > 0)
  {
    state = BTserial.read();
    Stop();
    switch (state)
    {
      case 'F':
        forward();
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
      case 'O':
        Fleft();
        break;
      case 'N':
        Fright();
        break;
      case 'P':
        Bleft();
        break;
      case 'M':
        Bright();
        break;


    }
  }
}



void forward()
{
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);


}
void back()
{
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
}


void left()
{
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}
void right()
{
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
}
void Stop()
{
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}
void Fright()
{
  right();
  forward();

}
void Fleft()
{
  left();
  forward();
}

void Bleft()
{
  left();
  back();
}
void Bright()
{
  right();
  back();
}

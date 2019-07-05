#include "Arduino.h"
void morse(int pin);
void dian();
void gang();
void w_space();
void s_space();
int letter[28][4]={
{1,2,0,0},{2,1,1,1},{2,1,2,1},{2,1,1,0},{1,0,0,0},{1,1,2,1},{2,2,1,0},{1,1,1,1},{1,1,0,0},
{1,2,2,2},{2,1,2,0},{1,2,1,1},{2,2,0,0},{2,1,0,0},{2,2,2,0},{1,2,2,1},{2,2,1,2},{1,2,1,0},
{1,1,1,0},{2,0,0,0},{ 1,1,2,0},{1,1,1,2},{1,2,2,0},{2,1,1,2},{2,1,2,2},{2,2,1,1 },{3,0,0,0},{4,0,0,0}
};
void setup()
{
  morse (8);  
  Serial.begin(9600);
}
int _pin;
int _dottime;
void loop()
{
  while(Serial.available() > 0 )
  {

  int asci=Serial.read();
  asci=asci-65;
  for(int i=0;i<4;i++)
  {
    if(letter[asci][i]==1)
    {
      dian();
      Serial.println('*');
      }
    else if(letter[asci][i]==2)
    {
      gang();
      Serial.println('_');
      }
    else if(letter[asci][i]==3)
    {
      c_space();
      Serial.println(' ');
      }
    else if(letter[asci][i]==4)
    {
      w_space();
      Serial.println('\n');
      }
  }
  delay(5000);
  Serial.println('@');
  }
}
void morse(int pin)
{
  pinMode(pin,OUTPUT);
  _pin=pin;
  _dottime=200;
}
void dian()
{
  digitalWrite(_pin,HIGH);
  delay(_dottime);
  digitalWrite(_pin,LOW);
  delay(_dottime);
}
void gang()
{
  digitalWrite(_pin,HIGH);
  delay(_dottime*8);
  digitalWrite(_pin,LOW);
  delay(_dottime);
}
void c_space()
{
  digitalWrite(_pin,LOW);
  delay(_dottime*6);
}
void w_space()
{
  digitalWrite(_pin,LOW);
  delay(_dottime*14);
}

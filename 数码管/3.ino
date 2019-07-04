void setup()
{
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  
  Serial.begin(9600);
  
  gigitalWrite(4,LOW);
  delay(10);
  digitalWrite(0,LOW);
  digitalWrite(1,HIGH);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  delay(10);
  digitalWrite(4,HIGH);
  delay(10);
}

void loop()
{
  if(Serial.available()>0)
  {
    income=Serial.read();
  
    income=income-'0';
    if((income&1)==1)
      digitalWrite(0,HIGH);
    if((income>>1&1)==1)
      digitalWrite(1,HIGH);
    if((income>>2&1)==1)
      digitalWrite(2,HIGH);
    if(income>>3&1)==1)
      digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    delay(2000);
  }
}  

  
  
  
  
  
 

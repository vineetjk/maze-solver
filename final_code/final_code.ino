
//Author : Sanvich
//Copyright reserved

 
 int vSpeed = 110;        // MAX 255
  int turn_speed = 230;    // MAX 255 
  int turn_delay = 10;
  int leaptime=200;
#define leftCenterSensor 6
#define leftFarSensor 7
#define rightCenterSensor 5
#define rightFarSensor 4
  const int rm1      = 12;  
  const int rm2      = 11; 
  const int rmspeed  = 13;
  const int lm1      = 8; 
  const int lm2      = 9; 
  const int lmspeed  = 10;
void straight();
void read();
int s1,s2,s3,s4;

void setup() {
pinMode(leftCenterSensor, INPUT);

pinMode(leftFarSensor, INPUT);
pinMode(rightCenterSensor, INPUT);

pinMode(rightFarSensor, INPUT);
pinMode(lm1, OUTPUT);
pinMode(lm2, OUTPUT);
pinMode(rm1, OUTPUT);
pinMode(rm2, OUTPUT);
delay(3000);
}

void loop() {
  read();
  if(s1 == 0 && (s2 == 1 || s3==1) && s4==0)
  {
    straight();  
  }
  else{
    leftHandWall();
  }
}
void read()
{
  s2 = digitalRead(leftCenterSensor);
  s1 = digitalRead(leftFarSensor);
  s3 = digitalRead(rightCenterSensor);
  s4 = digitalRead(rightFarSensor); 
}
void straight()
{
  if(digitalRead(leftCenterSensor)==0)
  {
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    analogWrite (rmspeed, vSpeed);
    analogWrite (lmspeed, vSpeed);
    delay(1);

    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,LOW);
    analogWrite (rmspeed, vSpeed);
    analogWrite (lmspeed, vSpeed);
    delay(2);
    return;
   }
   if(digitalRead(rightCenterSensor)==0)
   {
    
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    analogWrite (rmspeed, vSpeed);
    analogWrite (lmspeed, vSpeed);
    delay(1);

    digitalWrite(lm1,LOW);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    analogWrite (rmspeed, vSpeed);
    analogWrite (lmspeed, vSpeed);
    delay(2);
    return; 
   }
   
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    analogWrite (rmspeed, vSpeed);
    analogWrite (lmspeed, vSpeed);
    delay(2);

    digitalWrite(lm1,LOW);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,LOW);
    analogWrite (rmspeed, vSpeed);
    analogWrite (lmspeed, vSpeed);
    delay(1);
}
void leftHandWall()
{
  if(s1 == 1 && s4== 1)
  {
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    analogWrite (rmspeed, vSpeed);
    analogWrite (lmspeed, vSpeed);
    delay(leaptime);

    read();
    if(s1==1 || s2==1)
    {
      done();
    }
    if(s1==0 && s4==0)
    {
      left();
    }
  }
  if(s1==1){
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    analogWrite (rmspeed, vSpeed);
    analogWrite (lmspeed, vSpeed);
    delay(leaptime);
    read();

    if(s1==0 && s4==0)
    {
      left();
    }
    else{
      done();
    }
  }

  if(s4==1)
  {
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    analogWrite (rmspeed, vSpeed);
    analogWrite (lmspeed, vSpeed);
    delay(30);
    read();
    if(s1==1)
    {
      delay(leaptime-30);
      read();

      if(s1 == 1 && s4==1)
      {
        done();
      }
      else{
        left();
        return;
      }
    }
    delay(leaptime-30);
  }
  
}

#include <Servo.h>

//variables for servo motor
int servopin = 9;
int angle = 0;
Servo myservo;

//variables for PIR sensor
int pir1 = 2;
int pir2 = 3;
int pir3 = 4;

int gun = 12;


//email logic

int minSecsBetweenEmails = 10; // 10 sec
long lastSend = -minSecsBetweenEmails * 1000l;






void setup() {
  // put your setup code here, to run once:
  
  //setup for servo motor
  myservo.attach(servopin);
  Serial.begin(9600);
  
  //setup for PIR pins
  pinMode(pir1,INPUT);
  pinMode(pir2,INPUT);
  pinMode(pir3,INPUT);
  
  pinMode(gun,OUTPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly: 
    
  long now = millis();
    
    
    
  
    
  //logic if movement is only on 1 sensor
  if(digitalRead(pir1) == HIGH){
   
    for(angle = 25; angle < 80; angle++){
      myservo.write(angle);
      delay(10);
      digitalWrite(gun,HIGH);
      
    }
    for(angle = 80; angle > 25; angle--){
      myservo.write(angle);
      delay(10);
      digitalWrite(gun,LOW);
    }
    digitalWrite(gun,LOW);
    
  //************  
    if (now > (lastSend + minSecsBetweenEmails * 1000l))
{
Serial.println("MOVEMENT");
lastSend = now;
}
else
{
Serial.println("Too soon");
}
//************

  }
  
  
  
  if(digitalRead(pir2) == HIGH){
    for(angle = 60; angle < 120; angle++){
      myservo.write(angle);
      delay(15);
      digitalWrite(gun,HIGH);
    }
    for(angle = 120; angle > 60; angle--){
      myservo.write(angle);
      delay(15);
      digitalWrite(gun,LOW);
    }
    digitalWrite(gun,LOW);
    
   //************  
    if (now > (lastSend + minSecsBetweenEmails * 1000l))
{
Serial.println("MOVEMENT");
lastSend = now;
}
else
{
Serial.println("Too soon");
}
//************ 
    
  }
  
  
  
  if(digitalRead(pir3) == HIGH){
    for(angle = 100; angle < 150; angle++){
      myservo.write(angle);
      delay(15);
      digitalWrite(gun,HIGH);
    }
    for(angle = 150; angle > 100; angle--){
      myservo.write(angle);
      delay(15);
      digitalWrite(gun,LOW);
    }
    digitalWrite(gun,LOW);
    
    //************  
    if (now > (lastSend + minSecsBetweenEmails * 1000l))
{
Serial.println("MOVEMENT");
lastSend = now;
}
else
{
Serial.println("Too soon");
}
//************
    
  }
  
  
  
  
  //logic if movement is on 2 sensors i.e on consecutive
  if(digitalRead(pir1) && digitalRead(pir2)){
    for(angle = 30; angle < 100; angle++){
      myservo.write(angle);
      delay(15);
      digitalWrite(gun,HIGH);
    }
    for(angle = 100; angle > 30 ; angle--){
      myservo.write(angle);
      delay(15);
      digitalWrite(gun,LOW);
    }
    digitalWrite(gun,LOW);
    
    //************  
    if (now > (lastSend + minSecsBetweenEmails * 1000l))
{
Serial.println("MOVEMENT");
lastSend = now;
}
else
{
Serial.println("Too soon");
}
//************
    
  }
  
  
  if(digitalRead(pir2) && digitalRead(pir3)){
    for(angle = 60; angle < 150; angle++){
      myservo.write(angle);
      delay(15);
      digitalWrite(gun,HIGH);
    }
    for(angle = 150; angle > 60; angle--){
      myservo.write(angle);
      delay(15);
      digitalWrite(gun,LOW);
    }
    digitalWrite(gun,LOW);
    
    //************  
    if (now > (lastSend + minSecsBetweenEmails * 1000l))
{
Serial.println("MOVEMENT");
lastSend = now;
}
else
{
Serial.println("Too soon");
}
//************
    
  }
  
  
  
  
  //logic if movement is on 2 sensors but alternate
  if(digitalRead(pir1) && digitalRead(pir3)){
    for(angle = 25; angle < 150; angle++){
      myservo.write(angle);
      delay(15);
      digitalWrite(gun,HIGH);
    }
    for(angle = 150; angle > 25; angle--){
      myservo.write(angle);
      delay(15);
      digitalWrite(gun,LOW);
    }
    digitalWrite(gun,LOW);
    
    //************  
    if (now > (lastSend + minSecsBetweenEmails * 1000l))
{
Serial.println("MOVEMENT");
lastSend = now;
}
else
{
Serial.println("Too soon");
}
//************
    
  }
  
  
  
  
  
}

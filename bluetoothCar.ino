//initial motors pin
#define motor1Pin1 5  
#define motor1Pin2 4   
#define motor2Pin1 3  
#define motor2Pin2 2  

int Speed = 255;

char command; 

void setup() 
{       
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
}

void loop(){
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Stop(); //initialize with motors stoped
    //Change pin mode only if new command is different from previous.   
    //Serial.println(command);
    switch(command){
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
    case 'G':
      forwardLeft();
      break;
    case 'I':
      forwardRight();
      break;
    case 'H':
      backwardLeft();
      break;
    case 'J':
      backwardRight();
      break;
    case 'S':
      Stop();
      break;
  }
  } 
}

void forward()
{
  analogWrite(motor1Pin1, Speed);
  analogWrite(motor1Pin2, 0);
  analogWrite(motor2Pin1, Speed);
  analogWrite(motor2Pin2, 0);
}

void back()
{
  analogWrite(motor1Pin1, 0);
  analogWrite(motor1Pin2, Speed);
  analogWrite(motor2Pin1, 0);
  analogWrite(motor2Pin2, Speed);
}

void left()
{
  analogWrite(motor1Pin1, 0);
  analogWrite(motor1Pin2, 50);
  analogWrite(motor2Pin1, 0);
  analogWrite(motor2Pin2, Speed);
}

void right()
{
  analogWrite(motor1Pin1, 0);
  analogWrite(motor1Pin2, Speed);
  analogWrite(motor2Pin1, 0);
  analogWrite(motor2Pin2, 50);
} 

void Stop()
{
  analogWrite(motor1Pin1, 0);
  analogWrite(motor1Pin2, 0);
  analogWrite(motor2Pin1, 0);
  analogWrite(motor2Pin2, 0);
}

void forwardLeft(){
  analogWrite(motor1Pin1, Speed);
  analogWrite(motor1Pin2, 0);
  analogWrite(motor2Pin1, 200);
  analogWrite(motor2Pin2, 0);
}

void forwardRight(){
  analogWrite(motor1Pin1, 200);
  analogWrite(motor1Pin2, 0);
  analogWrite(motor2Pin1, 255);
  analogWrite(motor2Pin2, 0);
}

void backwardRight(){
  analogWrite(motor1Pin1, 0);
  analogWrite(motor1Pin2, Speed);
  analogWrite(motor2Pin1, 0);
  analogWrite(motor2Pin2, 200);
}

void backwardLeft(){
  analogWrite(motor1Pin1, 0);
  analogWrite(motor1Pin2, 200);
  analogWrite(motor2Pin1, 0);
  analogWrite(motor2Pin2, Speed);
}

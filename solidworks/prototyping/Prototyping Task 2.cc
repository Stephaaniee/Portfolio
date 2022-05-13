#define EnableRight 10
#define Input1Right 9
#define Input2Right 8
#define EnableLeft 5
#define Input1Left 7
#define Input2Left 6
#define RightSensor 4
#define LeftSensor 2

int sensorR;
int sensorL;

void setup()
{
	pinMode(EnableRight, OUTPUT);
	pinMode(Input1Right, OUTPUT);
	pinMode(Input2Right, OUTPUT);
	pinMode(EnableLeft, OUTPUT);
	pinMode(Input1Left, OUTPUT);
	pinMode(Input2Left, OUTPUT);
	pinMode(RightSensor, INPUT);
	pinMode(LeftSensor, INPUT);
}

void straight()
{
  digitalWrite(Input1Right, HIGH);
  digitalWrite(Input2Right, LOW);
  analogWrite(EnableRight, 180);
  
  digitalWrite(Input1Left, HIGH);
  digitalWrite(Input2Left, LOW);
  analogWrite(EnableLeft, 180);
}

void turnRight()
{
  digitalWrite(Input1Right, LOW);
  digitalWrite(Input2Right, LOW);
  analogWrite(EnableRight, 180);
  
  digitalWrite(Input1Left, HIGH);
  digitalWrite(Input2Left, LOW);
  analogWrite(EnableLeft, 180);
}

void turnLeft()
{
  digitalWrite(Input1Right, HIGH);
  digitalWrite(Input2Right, LOW);
  analogWrite(EnableRight, 180);
  
  digitalWrite(Input1Left, LOW);
  digitalWrite(Input2Left, LOW);
  analogWrite(EnableLeft, 180);
}
void loop()
{
    sensorR = digitalRead(2);
  	sensorL = digitalRead(4);
  
	if(sensorR == LOW && sensorL == LOW)
    {
      straight();
    }
  	
  	else if(sensorR == HIGH && sensorL == LOW)
    {
      turnRight();
    }
  	
  	else if(sensorR == LOW && sensorL == HIGH)
    {
      turnLeft();
    }
  delay(100);
}
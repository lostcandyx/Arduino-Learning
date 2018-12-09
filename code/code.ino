#define MOTOR1_F 22
#define MOTOR1_B 23

#define MOTOR2_F 24
#define MOTOR2_B 25

#define MOTOR3_F 26
#define MOTOR3_B 27

#define MOTOR4_F 28
#define MOTOR4_B 29

#define MOTOR12_PWM 44
#define MOTOR34_PWM 45

#define EN        8       //步进电机使能端，低电平有效

#define X_DIR     5       //X轴 步进电机方向控制

#define Y_DIR     6       //y轴 步进电机方向控制

#define X_STP     2       //x轴 步进控制

#define Y_STP     3       //y轴 步进控制

#define PAUSE 1400
/*

  //函数：step    功能：控制步进电机方向，步数。

  //参数：dir 方向控制, dirPin对应步进电机的DIR引脚，stepperPin 对应步进电机的step引脚， steps 步进的步数

  //无返回值

*/
void step(boolean dir, int steps)
{
  byte dirPin = X_DIR;
  byte stepperPin = X_STP;
  digitalWrite(dirPin, dir);

  delay(50);

  for (int i = 0; i < steps; i++) {

    digitalWrite(stepperPin, HIGH);

    delayMicroseconds(PAUSE);

    digitalWrite(stepperPin, LOW);

    delayMicroseconds(PAUSE);

  }

}

void step_running(boolean dir, int steps, int run_dir, int run_speed)
{
  byte dirPin = X_DIR;
  byte stepperPin = X_STP;
  digitalWrite(dirPin, dir);

  delay(50);

  for (int i = 0; i < steps; i++)
  {
    Operate_motor12(run_dir, run_speed );
    Operate_motor34(run_dir, run_speed);

    digitalWrite(stepperPin, HIGH);

    delayMicroseconds(PAUSE);

    digitalWrite(stepperPin, LOW);

    delayMicroseconds(PAUSE);

  }

}

void setup()
{
  for (int i = MOTOR1_F; i <= MOTOR4_B; i++)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(MOTOR12_PWM, OUTPUT);
  pinMode(MOTOR34_PWM, OUTPUT);

  pinMode(X_DIR, OUTPUT); pinMode(X_STP, OUTPUT);

  pinMode(EN, OUTPUT);

  digitalWrite(EN, LOW);

  delay(2000);
}

void loop()
{
  Operate_motor12(1, 255);
  Operate_motor34(1, 255);
  delay(2000);
  shut_down();
  delay(100);
  Operate_motor12(0, 255);
  Operate_motor34(0, 255);
  delay(2000);
  turn(1, 255);
  delay(1000);
  Operate_motor12(1, 255);
  Operate_motor34(1, 255);
  delay(2000);
  shut_down();
  delay(100);
  Operate_motor12(0, 255);
  Operate_motor34(0, 255);
  delay(2000);
  turn(0, 255);
  delay(1000);

  step_running(true,700,1,255);
  shut_down();
  delay(100);
  step_running(false,700,0,255);
  shut_down();
  delay(100);
}

void Operate_motor12(int state, int s)
{
  if (s >= 255) s = 255;
  else if (s <= 0) s = 0;
  if (state == 1)
  {
    digitalWrite(MOTOR1_F, LOW);
    digitalWrite(MOTOR1_B, HIGH);
    digitalWrite(MOTOR2_F, LOW);
    digitalWrite(MOTOR2_B, HIGH);

    analogWrite(MOTOR12_PWM, s);
  }
  else if (state == 0)
  {
    digitalWrite(MOTOR1_F, HIGH);
    digitalWrite(MOTOR1_B, LOW);
    digitalWrite(MOTOR2_F, HIGH);
    digitalWrite(MOTOR2_B, LOW);

    analogWrite(MOTOR12_PWM, s);
  }
  else
  {
    digitalWrite(MOTOR1_F, LOW);
    digitalWrite(MOTOR1_B, LOW);
    digitalWrite(MOTOR2_F, LOW);
    digitalWrite(MOTOR2_B, LOW);
  }
}

void Operate_motor34(int state, int s)
{
  if (s >= 255) s = 255;
  else if (s <= 0) s = 0;
  if (state == 1)
  {
    digitalWrite(MOTOR3_F, LOW);
    digitalWrite(MOTOR3_B, HIGH);
    digitalWrite(MOTOR4_F, LOW);
    digitalWrite(MOTOR4_B, HIGH);

    analogWrite(MOTOR34_PWM, s);
  }
  else if (state == 0)
  {
    digitalWrite(MOTOR3_F, HIGH);
    digitalWrite(MOTOR3_B, LOW);
    digitalWrite(MOTOR4_F, HIGH);
    digitalWrite(MOTOR4_B, LOW);

    analogWrite(MOTOR34_PWM, s);
  }
  else
  {
    digitalWrite(MOTOR3_F, LOW);
    digitalWrite(MOTOR3_B, LOW);
    digitalWrite(MOTOR4_F, LOW);
    digitalWrite(MOTOR4_B, LOW);
  }
}

void turn(int state, int s) //1 顺时针 0 逆时针
{
  if (state == 1 )
  {
    digitalWrite(MOTOR1_F, LOW);
    digitalWrite(MOTOR1_B, HIGH);
    digitalWrite(MOTOR2_F, LOW);
    digitalWrite(MOTOR2_B, HIGH);
    digitalWrite(MOTOR3_F, HIGH);
    digitalWrite(MOTOR3_B, LOW);
    digitalWrite(MOTOR4_F, HIGH);
    digitalWrite(MOTOR4_B, LOW);

    analogWrite(MOTOR34_PWM, s);
    analogWrite(MOTOR12_PWM, s);
  }
  else if (state == 0)
  {
    digitalWrite(MOTOR1_F, HIGH);
    digitalWrite(MOTOR1_B, LOW);
    digitalWrite(MOTOR2_F, HIGH);
    digitalWrite(MOTOR2_B, LOW);
    digitalWrite(MOTOR3_F, LOW);
    digitalWrite(MOTOR3_B, HIGH);
    digitalWrite(MOTOR4_F, LOW);
    digitalWrite(MOTOR4_B, HIGH);

    analogWrite(MOTOR34_PWM, s);
    analogWrite(MOTOR12_PWM, s);
  }
  else
  {
    digitalWrite(MOTOR3_F, LOW);
    digitalWrite(MOTOR3_B, LOW);
    digitalWrite(MOTOR4_F, LOW);
    digitalWrite(MOTOR4_B, LOW);
    digitalWrite(MOTOR1_F, LOW);
    digitalWrite(MOTOR1_B, LOW);
    digitalWrite(MOTOR2_F, LOW);
    digitalWrite(MOTOR2_B, LOW);
  }
}

void shut_down()
{
  digitalWrite(MOTOR3_F, LOW);
  digitalWrite(MOTOR3_B, LOW);
  digitalWrite(MOTOR4_F, LOW);
  digitalWrite(MOTOR4_B, LOW);
  digitalWrite(MOTOR1_F, LOW);
  digitalWrite(MOTOR1_B, LOW);
  digitalWrite(MOTOR2_F, LOW);
  digitalWrite(MOTOR2_B, LOW);
}

#include "LineFollower/LineFollower.h"

void Move_Forward(int speed1, int speed2)
{
  analogWrite(L_M_1, speed1);
  analogWrite(L_M_2, LOW);
  analogWrite(R_M_2, speed2);
  analogWrite(R_M_1, LOW);
  digitalWrite(Front_LED, HIGH);
  digitalWrite(B_R_LED, LOW);
  digitalWrite(B_L_LED, LOW);
}
void Move_STOP()
{
  digitalWrite(B_L_LED, HIGH);
  digitalWrite(B_R_LED, HIGH);
  analogWrite(L_M_1, LOW);
  analogWrite(R_M_1, LOW);
  analogWrite(L_M_2, LOW);
  analogWrite(R_M_2, LOW);
}
void Move_RIGHT( int speed2)
{
  digitalWrite(B_R_LED, HIGH);
  digitalWrite(B_L_LED, LOW);
  analogWrite(L_M_1, LOW);
  analogWrite(R_M_1, LOW);

  analogWrite(L_M_2, LOW);
  analogWrite(R_M_2, speed2);
}
void Move_LEFT(int speed1)
{
  digitalWrite(B_R_LED, LOW);
  digitalWrite(B_L_LED, HIGH);
  analogWrite(L_M_1, speed1);
  analogWrite(R_M_1, LOW);
  analogWrite(L_M_2, LOW);
  analogWrite(R_M_2, LOW);
}
int Get_error()
{
  int s1 = digitalRead(IR_1);
  int s2 = digitalRead(IR_2);
  int s3 = digitalRead(IR_3);
  if (s1 == 1 && s3 == 0)
    return -1;
  else if (s1 == 0 && s2 == 1 && s3 == 0)
    return 0;
  else if (s1 == 0 && s3 == 1)
    return 1;
  else if (s1 == 0 && s2 == 0 && s3 == 0)
    return 2;
  else
    return 3;
}
void Line_Follower()
{
  int error = Get_error();
  int left_speed = MAX_SPEED;
  int right_speed = MAX_SPEED;

  if (error == 1)
  {
    while (error != 0)
    {
      Move_LEFT(left_speed);
      error = Get_error();
    }
  }
  else if (error == 0)
  {
    Move_Forward(right_speed, left_speed);
  }
  else if (error == -1)
  {
    while (error != 0)
    {
      Move_RIGHT(right_speed);
      error = Get_error();
    }
  }
  else if (error == 2)
  {
    Move_STOP();
  }
  else
  {
    Move_STOP();
  }
}


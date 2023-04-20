
#include "LineFollower/LineFollower.h"

void setup()
{
  Serial.begin(9600);
  pinMode(B_R_LED, OUTPUT);
  pinMode(B_L_LED, OUTPUT);
  pinMode(Front_LED, OUTPUT);
  pinMode(L_M_1, OUTPUT);
  pinMode(L_M_2, OUTPUT);
  pinMode(R_M_1, OUTPUT);
  pinMode(R_M_2, OUTPUT);
  pinMode(IR_1, INPUT);
  pinMode(IR_2, INPUT);
  pinMode(IR_3, INPUT);
}

void loop()
{
  Line_Follower();
}
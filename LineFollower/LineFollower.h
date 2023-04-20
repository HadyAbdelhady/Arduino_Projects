#ifndef __LineFollower__
#define __LineFollower__
#include <Arduino.h>

#define Front_LED A3
#define B_L_LED A2
#define B_R_LED A1

#define L_M_2 4
#define L_M_1 5

#define R_M_2 6
#define R_M_1 7

#define IR_1 8
#define IR_2 9
#define IR_3 10

#define MAX_SPEED 250
#define MIN_SPEED 0

int Get_error();
void Line_Follower();

#endif
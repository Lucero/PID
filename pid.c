#include "pid.h"


//Private
typedef struct
{	
	float Err;       //差分
	float Err_Sum;   //积分
	float Err_Diff;  //微分
	
	float Err_Last;  //最新一次
	float Err_Pre;   //前一次
	
	float p;         //Proportional Coefficient
	float i;         //Integral
	float d;         //Derivative
}PID_CB_t; //PID control block


void PID_Init(PID_CB_t *PID_CB, float p, float i, float d)
{
	PID_CB->p = p;
	PID_CB->i = i;
	PID_CB->d = d;
}

float PID_Calculate(PID_CB_t *PID_CB, float Target, float Measurement)
{
	float output;
	
	PID_CB->Err = Target - Measurement;
	PID_CB->Err_Sum += PID_CB->Err;
	PID_CB->Err_Diff = PID_CB->Err_Last - PID_CB->Err_Pre;

	PID_CB->Err_Pre = PID_CB->Err_Last;
	PID_CB->Err_Last = PID_CB->Err;

	output = PID_CB->p * PID_CB->Err + PID_CB->i * PID_CB->Err_Sum + PID_CB->d * PID_CB->Err_Diff;
	
	return output;
}





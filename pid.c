#include "pid.h"

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





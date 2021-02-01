#include "pid.h"

void PID_Calculate(PID_CB_t *PID_CB)
{
	PID_CB->Err = PID_CB->Target - PID_CB->Current;
	PID_CB->Err_Sum += PID_CB->Err;
	PID_CB->Err_Det = PID_CB->Err_Last - PID_CB->Err_Pre;

	PID_CB->Err_Pre = PID_CB->Err_Last;
	PID_CB->Err_Last = PID_CB->Err;

	PID_CB->Result = PID_CB->p * PID_CB->Err + PID_CB->i * PID_CB->Err_Sum + PID_CB->d * PID_CB->Err_Det;
}





#ifndef __PID_H
#define __PID_H


typedef struct
{
	float Target;    //Target value
	float Input;
	float Output;
	
	float Err;       //差分
	float Err_Sum;   //积分
	float Err_Diff;  //微分
	
	float Err_Last;  //最新一次
	float Err_Pre;   //前一次
	
	float p;         //Proportional Coefficient
	float i;         //Integral
	float d;         //Derivative
}PID_CB_t; //PID control block


extern void PID_Calculate(PID_CB_t *PID_CB);

#endif



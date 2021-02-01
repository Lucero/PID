#ifndef __PID_H
#define __PID_H

//Public
extern void  PID_Init(PID_CB_t *PID_CB, float p, float i, float d);
extern float PID_Calculate(PID_CB_t *PID_CB, float Target, float Measurement);

#endif



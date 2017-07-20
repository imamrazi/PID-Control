#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;

    this->p_error = 0;
    this->d_error = 0;
    this->i_error = 0;
     
    this->prev_cte = 0;
}

void PID::UpdateError(double cte) {
    p_error = -Kp*cte;
    d_error = Kd*(cte - prev_cte);
    i_error += Ki*i_error;
    
    // Set previous cte to current cte
    prev_cte = cte;
}

double PID::TotalError() {
    
    return (p_error - d_error - i_error);
    
}


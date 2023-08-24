#include "mbed.h"
#include "crazyflie.h"
#include "utils/parameters.h"
PwmOut motor(MOTOR2);
float control_motor (float omega)
{
    float pwm;
    pwm = a2 * pow(omega,2) + a1 * omega;
    return pwm;
}
int main()
{
    motor.period(1.0/500.0);
    motor = control_motor(1000.0);
    wait(5);
    motor = 0;
    while(true)
    {

    }
}
#include "mbed.h"
#include "crazyflie.h"
#include "utils/parameters.h"
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);
float control_motor (float omega)
{
    float pwm;
    pwm = a2 * pow(omega,2) + a1 * omega;
    return pwm;
}
int w = 2000;
int main()
{
    motor1.period(1.0/500.0);
    motor1 = control_motor(w);
    motor2.period(1.0/500.0);
    motor2 = control_motor(w);
    motor3.period(1.0/500.0);
    motor3 = control_motor(w);
    motor4.period(1.0/500.0);
    motor4 = control_motor(w);
    wait(5);
    motor1 = 0;
    motor2 = 0;
    motor3 = 0;
    motor4 = 0;

    while(true)
    {

    }
}
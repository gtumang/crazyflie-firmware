#include "mbed.h"
#include "crazyflie.h"
PwmOut motor(MOTOR2);
int main()
{
    motor.period(1.0/500.0);
    motor = 0.6;
    wait(5);
    motor = 0;
}
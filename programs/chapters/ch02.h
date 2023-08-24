#include "mbed.h"
#include "crazyflie.h"

PwmOut motor1(MOTOR2);
int main()
{
    motor1 = 1.0;
    wait(5);
    motor1 = 0;
}
#include "mbed.h"
#include "crazyflie.h"

Mixer mixer1;

int main()
{
    mixer1.arm();
    mixer1.actuate(0,0,0,0.001);
    wait(5);
    mixer1.actuate(0,0,0,0);

    mixer1.disarm();
    mixer1.actuate(0,0.005,0,0);
    wait(5);
    mixer1.actuate(0,0,0,0);

    while(true){
    }
}
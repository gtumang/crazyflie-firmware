#include "mbed.h"
#include "crazyflie.h"

// Define all LEDs as digital output objects
DigitalOut led1(LED_GREEN_R, !false);
DigitalOut led2(LED_BLUE_L,!false);
// Define all motors as PWM objects
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);
int freq = 400;
// Main program
int main()
{
    // Blink blue LED indicating inicialization (5 seconds)
    for (int i = 1; i < 3; i++)
    {
        led1 = !led1;
        wait(0.5);
        led1 = !led1;
        wait(0.5);
        led2 = !led2;
        wait(0.5);
        led2 = !led2;
    }
    // Turn on red LEDs indicating motors are armed

    // Test all motors with different frequencies (to make different noises)
    
    // Turn off red LEDs indicating motors are disarmed
    
    // Blink green LEDs indicating end of program
    while(true)
    {
        motor1 = 0.2;
        wait(2);
        motor2 = 0.2;
        wait(2);
        motor3 = 0.2;
        wait(2);
        motor4 = 0.2;
    }
}

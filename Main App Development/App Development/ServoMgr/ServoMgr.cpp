#include "ServoMgr.hpp"
#include <wiringPi.h>
#include <stdint.h>

#define ENABLE_DEBUG 0
#if ENABLE_DEBUG == 1
#include <iostream>
#endif
/************************************************
 ******************* APIs    *******************
 ***********************************************/
// Function to initialize PWM for servos
void ServoMgr_voidInit()
{
    // Initialize WiringPi library
    wiringPiSetupGpio();
#if ENABLE_DEBUG == 1
    std::cout << "Init Servos ..."<< std::endl;
#endif
    // Set servo pins as PWM output
    pinMode(SLIDE_SERVO_PIN, PWM_OUTPUT);
    pinMode(HEIGHT_SERVO_PIN, PWM_OUTPUT);
}

// Function to control two servos based on angles
void ServoMgr_voidControl(const S_DEG *servoAngles)
{
    // Control sliding servo based on angle
    pwmWrite(SLIDE_SERVO_PIN, (servoAngles->ST_SLD_S2));
    // Control height servo based on angle
    pwmWrite(HEIGHT_SERVO_PIN, (servoAngles->ST_HGT_S1));
#if ENABLE_DEBUG == 1
    std::cout << "servoAngles->ST_SLD_S2 = " << static_cast<int>(servoAngles->ST_SLD_S2) << std::endl
              << "servoAngles->ST_HGT_S1 = " << static_cast<int>(servoAngles->ST_HGT_S1) << std::endl;
#endif
}

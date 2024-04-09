#ifndef SERVO_MGR_HPP
#define SERVO_MGR_HPP
#include "../Common/Common.hpp"
/************************************************
 ******************* MACROS *******************
 ***********************************************/
// Define GPIO pins for servos
#define SLIDE_SERVO_PIN 18     // GPIO pin for sliding servo
#define HEIGHT_SERVO_PIN 17  // GPIO pin for height servo

/************************************************
 ******************* APIs    *******************
 ***********************************************/
// Function to initialize PWM for servos
void ServoMgr_voidInit();

// Function to control two servos based on angles
void ServoMgr_voidControl(const S_DEG *servoAngles);

#endif // SERVO_MGR_HPP

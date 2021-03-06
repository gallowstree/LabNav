#ifndef MYARDUINOPROJECT_MOTIONCONTROLLER_H
#define MYARDUINOPROJECT_MOTIONCONTROLLER_H

#include "MotorDriver.h"
#include "Odometer.h"
#include "Motion.h"

class MotionController {
public:
    MotionController(Odometer* odometer, MotorDriver * motors, SpeedControl* speedCtl);
    void rotate(float degrees, bool clockwise);   
    void rotateWithSign(float degrees); 
    void stop();
    void moveForward(float cm);
	void moveBackwards(float cm);	

    int initialRightPulseLength = 125;
    int initialLeftPulseLength = 125;
private:    
    MotorDriver* motors;
    Odometer* odometer;
    SpeedControl* speedCtl;
    void waitForDistance(float cm);  
    void beforeMoving();
    void afterMoving();
    
};

#endif
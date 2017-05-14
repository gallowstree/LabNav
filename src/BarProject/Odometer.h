#ifndef MYARDUINOPROJECT_ODOMETER_H
#define MYARDUINOPROJECT_ODOMETER_H

#include <Arduino.h>

class Odometer {

public:
	Odometer(float wheelRadius, int resolution, int leftInterruptPin, int rightInterruptPin);
        void enable();
        void disable();
        float getRightDistance();
        float getLeftDistance();
        float getAvgDistance();
        float getMaxDistance();

        
        static volatile float leftInt;
        static volatile float rightInt;	
        static void leftISR();
        static void rightISR();
private:
        float wheelRadius;
        float resolution;
        
        int leftInterruptPin;
        int rightInterruptPin;

        float calculateDistance(float interrupts);
        
};

#endif
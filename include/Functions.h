#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define OPEN 1
#define CLOSE 0

#define UP 1
#define DOWN 0

//always include vex.h because it has all the robot setup declarations
//as well as the API for the code.
#include "vex.h"

//enter the prototypes for other functions here
//lift, claw, etc
//drive function prototypes can go here but they should be in the DriveFunctions.h file
void testPID(void);

void clamp(bool openClose);
void moveLift(bool upDown, uint32_t time, uint8_t velocity);
void Rings();
void goalApproach( int vel) ;
#endif
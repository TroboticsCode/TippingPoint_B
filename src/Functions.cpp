#include "functions.h"
#include "DriveFunctionsConfig.h"
#include "vex.h"

void testPID()
{
  for(int i = 0; i < 8; i++)
  {
    moveLinear(12, 100, 10000);  
    moveRotate(-90, 90, 10000);
  }
  //moveStop();
  wait(20, msec); // Sleep the task for a short amount of time t
}

void printGPS(void) 
{
  Brain.Screen.setCursor(1, 1);
  Brain.Screen.print("X Pos: %f\n", GPS.xPosition(distanceUnits::in));
  Brain.Screen.newLine();
  Brain.Screen.print("Y Pos: %f\n", GPS.yPosition(distanceUnits::in));
  Brain.Screen.newLine();
  Brain.Screen.print("Heading: %f\n", GPS.heading());

  Controller1.Screen.setCursor(1, 1);
  Controller1.Screen.print("X Pos: %f\n", GPS.xPosition(distanceUnits::in));
  Controller1.Screen.newLine();
  Controller1.Screen.print("Y Pos: %f\n", GPS.yPosition(distanceUnits::in));
  Controller1.Screen.newLine();
  Controller1.Screen.print("Heading: %f\n", GPS.heading());
}

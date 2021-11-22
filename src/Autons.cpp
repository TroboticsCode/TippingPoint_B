#include "vex.h"
#include "Autons.h"
#include "Functions.h"
#include "DriveFunctionsConfig.h"

//Put your auton routines in here

void Auton1()
{
 // setRotGains(0, 0, 0, 20, 10); //update PID gains to tune robot
 // setLinGains(0, 0, 0, 20, 10);

  moveLinear(12, 25, 3000);
  moveStop(hold);
  clamp(CLOSE);
  moveLinear(-12, 25, 3000);
  moveStop(hold);
  clamp(OPEN);
}

void skills()
{
   moveLinear(12, 25, 3000);
  moveStop(hold);
  clamp(CLOSE);
  moveLinear(-12, 25, 3000);
  moveStop(hold); 
  moveRotate(90, 25, 500);

}
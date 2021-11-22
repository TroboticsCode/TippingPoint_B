#include "functions.h"
#include "DriveFunctionsConfig.h"
#include "vex.h"

using namespace vex;

void testPID() {
  for (int i = 0; i < 8; i++) {
    moveLinear(12, 100, 10000);
    moveRotate(-90, 90, 10000);
  }
  // moveStop();
  wait(20, msec); // Sleep the task for a short amount of time t
}

void clamp(bool openClose) 
{
  if (openClose == OPEN) 
  {
    claw.spin(forward, 100, pct);
  } 
  else if (openClose == CLOSE) 
  {
    claw.spin(reverse, 100, pct);
  }
  wait(500, msec);
  claw.stop(hold);
}

void moveLift(bool upDown, uint32_t time, uint8_t velocity)
{
  if(upDown)
  {
    armL.rotateFor(fwd, time, msec, velocity, pct);
    //armR.rotateFor(fwd, time, msec, velocity, pct);
  }
  else
  {
    //armL.rotateFor(rev, time, msec, velocity, pct);
    //armR.rotateFor(rev, time, msec, velocity, pct);
 
  }
}
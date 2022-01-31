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
  uint32_t startTime = Brain.timer(timeUnits::msec);

  armL.setVelocity(velocity, pct);
  armR.setVelocity(velocity, pct);

  armR.setBrake(hold);
  armL.setBrake(hold);

  while(Brain.timer(msec) - startTime < time)
  {
    if(upDown)
    {
      armL.spin(fwd);
      armR.spin(fwd);
    }
    else
    {
      armL.spin(reverse);
      armR.spin(reverse);
  
    }
  }
  armL.stop();
  armR.stop();
}
void Rings ()
{
    while(armPot.value(range10bit)>= 41)
    {
      armL.spin(forward , 30,pct);
      armR.spin(forward,  30,pct);
    }
      armL.stop(hold);
      armR.stop(hold);
      moveLinear(10, 25, 3000);
      wait(0.5, seconds);
      clamp(CLOSE);
      wait(1, seconds);
      clamp(OPEN);
      // moveLinear()
    
}
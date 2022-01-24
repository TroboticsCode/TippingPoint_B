#include "Autons.h"
#include "DriveFunctionsConfig.h"
#include "Functions.h"
#include "vex.h"

// Put your auton routines in here

void Auton1() {
  // setRotGains(0, 0, 0, 20, 10); //update PID gains to tune robot
  // setLinGains(0, 0, 0, 20, 10);
  moveLinear(91, 50, 3000); // drive across field push one goal
  wait(1, seconds);
  moveRotate(40, 25, 3000); // turn to align with yellow short goal
  wait(1, seconds);
  moveLinear(-77, 50, 3000); // drive backward to push yellow goal
  wait(1, seconds);
  moveRotate(-60, 25, 3000); // turn to align with center yellow goal
  wait(1, seconds);
  moveLinear(73, 50, 3000); // drive forwad to push center yellow goal
  wait(1, seconds);
  moveRotate(55, 25, 3000); // turn to align with 3rd yellow short goal
  wait(1, seconds);
  moveLinear(-65, 50, 3000); // drive backward to push yellow goal
  wait(1, seconds);
  moveRotate(-51, 25, 3000); // turn to align with blue goal on red square
  wait(1, seconds);
  moveLinear(43, 45, 3000); // moves toward goal
  wait(1, seconds);
  moveLinear(1, 25, 2000);
  clamp(CLOSE);
  moveLinear(-78, 60, 3000); // moves backward towards the blue section
}

void Auton2() {
  //copied from main

  //old auton code
  moveLinear(15, 25, 3000);
  clamp(CLOSE);
  moveLinear(-8, 25, 3000);
  //moveRotate(-120, 25, 3000);
  // moveLift(UP, 1000, 75);
  // moveLinear(27, 25, 3000);
  clamp(OPEN);
  // moveLinear(-25, 45, 3000);
  moveRotate(-76, 45, 3000);
}

/*
  moveLinear(12, 25, 3000);
  moveStop(hold);
  clamp(CLOSE);
  moveLinear(-12, 25, 3000);
  moveStop(hold);
  clamp(OPEN);
  */

void skills() {
  moveLinear(12, 25, 3000);
  moveStop(hold);
  clamp(CLOSE);

  moveLinear(-6, 25, 3000);
  moveStop(hold);
  //moveLift(UP, 3000, 100);

  moveRotate(-170, 100, 5000);
  //moveStop(hold);
  //wait(500, msec);

  //moveLinear(29, 100, 5000);
  moveStop(hold);

  //moveLift(DOWN, 500, 100);
  clamp(OPEN);
  //moveLinear(-12, 100, 3000);
  moveRotate(100, 80, 5000) ;
}

void skills120() {
  moveLinear(12, 100, 3000);  // approach first goal
  clamp(CLOSE);               // grabs first goal
  moveLinear(-11, 100, 3000); // moves backward with first goal
  moveRotate(80, 25, 3000);   // turns with goal
  moveLinear(48, 100, 3000);  // moves across field
  clamp(OPEN);                // lets go of goal
  moveRotate(14, 100, 3000);  // alines with second goal
  moveLinear(48, 100, 3000);  // grabs second goal
  moveRotate(90, 25, 3000);   // moves to aline with middle yellow goal
}
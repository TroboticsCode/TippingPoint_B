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
  moveLinear(-10, 55, 3000);
  //moveRotate(-120, 25, 3000);
  // moveLift(UP, 1000, 75);
  // moveLinear(27, 25, 3000);
  clamp(OPEN);
  // moveLinear(-25, 45, 3000);
  
  moveRotate(-50, 45, 3000);
  clamp(OPEN);
}

/*
  moveLinear(12, 25, 3000);
  moveStop(hold);
  clamp(CLOSE);
  moveLinear(-12, 25, 3000);
  moveStop(hold);
  clamp(OPEN);
  */

void skills() { //this grabs one yellow goal and gets the win point
  Rings();
  moveLinear(-10, 25, 3000);
  armL.stop(coast);
  armR.stop(coast);//arm falls down
  wait(1, seconds);
  moveLinear(12, 25, 3000); //moves forward to colored goal
  moveStop(hold); //wait
  clamp(CLOSE); //grabs goal

  moveLinear(-4, 25, 3000); //moves backward
  moveStop(hold); //wait
  

  moveRotate(-90, 100, 5000); //turns toward the platform
  clamp(OPEN); //lets go of goal
  moveLinear(-2,25,3000);
  moveRotate(65,100,5000); //turns toward yellow
  moveLinear(43,25,3000); //goes toward goal
  clamp(CLOSE);
  


  moveStop(hold); //wait

  
  clamp(OPEN); //opens claw
  
  moveRotate(100, 80, 5000) ; 
}

void skills120() {
  clamp(OPEN);
 goalApproach(40);  // grabs first goal
  wait(2, seconds);
  moveLinear(-11, 100, 3000); // moves backward with first goal
  moveLift(true, 250, 50);
  armL.setBrake(hold);
  armR.setBrake(hold);
  moveRotate(-50, 50, 3000);   // turns with goal
  moveLinear(68, 100, 3000);  // moves across field
  clamp(OPEN);                // lets go of goal
  moveRotate(14, 100, 3000);  // alines with second goal
  moveLinear(48, 100, 3000);  // grabs second goal
  moveRotate(90, 25, 3000);   // moves to aline with middle yellow goal
}

void Auton3(){ //yellow goal blitz
clamp(OPEN);
goalApproach(60);
moveLinear(-48,100, 3000);
//clamp(OPEN);
}



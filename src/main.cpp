// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Inertial12           inertial      12
// ---- END VEXCODE CONFIGURED DEVICES ----
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       JBormann                                                  */
/*    Created:      Nov. 2019                                                 */
/*    Description:  Trobotics Template File                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "Autons.h"
#include "DriveFunctionsConfig.h"
#include "Functions.h"
#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Controller1.ButtonR1.pressed(cycle_autons);
  Brain.Screen.pressed(cycle_autons);
  return;
}

void autonomous(void) {
  switch (state) {
  case NONE:
    break;

  case AutonR:
    Auton1();
    break;

  case AutonB:
    Auton2();
    break;

  case SKILLS:
    skills();
    break;

  // Default = NO autonomous
  default:
    break;
  }
}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {

  armL.setPosition(0, degrees);
  armR.setPosition(0, degrees);

  while (1) {
    armL.setVelocity(100, percent);
    armR.setVelocity(100, percent);
    claw.setVelocity(100, percent);
    // leave the drive code here, it should work if you set up
    // DriveFunctionsConfig.h properly
    userDrive();

    Brain.Screen.setCursor(1, 1);
    Brain.Screen.clearScreen();
    Brain.Screen.print(armL.position(degrees));
    Brain.Screen.newLine();
    Brain.Screen.print(armR.position(degrees));

    /*if (Controller1.ButtonUp.pressing()) {
      armL.rotateTo(195, rotationUnits::deg, 25, velocityUnits::pct, false);
      armR.rotateTo(195, rotationUnits::deg, 25, velocityUnits::pct, true); // arm goes up
      armL.stop(hold);
      armR.stop(hold);
      moveLinear(10, 25, 3000);
      wait(0.5, seconds);
      clamp(CLOSE);
      wait(1, seconds);
      clamp(OPEN);
      // moveLinear()
    } else {
      armL.stop(hold);
      armR.stop(hold);
    }*/
    if (Controller1.ButtonR1.pressing()) {
      armL.spin(forward);
      armR.spin(forward);
    } else if (Controller1.ButtonR2.pressing()) {
      armL.spin(reverse);
      armR.spin(reverse);
    } else {
      armL.stop(hold);
      armR.stop(hold);
    }

    if (Controller1.ButtonL1.pressing()) {
      claw.spin(forward);
    } else if (Controller1.ButtonL2.pressing()) {
      claw.spin(reverse);
    } else {
      claw.stop(hold);
    }
    wait(20, msec); // Sleep the task for a short amount of time to
  }
}

// Main will set up the competition functions and callbacks.

int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}

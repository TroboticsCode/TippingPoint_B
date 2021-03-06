#include "vex.h"
#include "DriveFunctionsConfig.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor armL = motor(PORT3, GREEN, true);
motor armR = motor(PORT19, GREEN, false);
motor claw = motor(PORT2, GREEN, true);
pot armPot = pot(Brain.ThreeWirePort.H);
bumper clawBumper = bumper(Brain.ThreeWirePort.C);
// VEXcode generated functions


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}
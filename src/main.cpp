#include "main.h"
//Motor Constructors
pros::Motor rightmotorfront (3, pros::E_MOTOR_GEARSET_18, 0, pros::E_MOTOR_ENCODER_DEGREES);
//pros::Motor rightmotormiddle (4, pros::E_MOTOR_GEARSET_18, 0, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rightmotorback (5, pros::E_MOTOR_GEARSET_18, 0, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor leftmotorfront (11, pros::E_MOTOR_GEARSET_18, 0, pros::E_MOTOR_ENCODER_DEGREES);
//pros::Motor leftmotormiddle (12, pros::E_MOTOR_GEARSET_18, 0, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor leftmotorback (13, pros::E_MOTOR_GEARSET_18, 0, pros::E_MOTOR_ENCODER_DEGREES);

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	rightmotorfront.tare_position();
	//rightmotormiddle.tare_position();
	rightmotorback.tare_position();
	leftmotorfront.tare_position();
	//leftmotormiddle.tare_position();
	leftmotorback.tare_position();
}
/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
pros::Controller master (pros::E_CONTROLLER_MASTER);
	while (true) {
//Tank Control Tank Drive Base
	if(master.get_analog(ANALOG_RIGHT_Y)){
		rightmotorfront.move(master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
		//rightmotormiddle.move(master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
		rightmotorback.move(master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
	}
	if(master.get_analog(ANALOG_LEFT_Y)){
		leftmotorfront.move(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
		//leftmotormiddle.move(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
		leftmotorback.move(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
	}
	else{
		leftmotorfront.move(0);
		//leftmotormiddle.move(MOTOR_BRAKE_HOLD);
		leftmotorback.move(0);
		rightmotorfront.move(0);
		//rightmotormiddle.move(MOTOR_BRAKE_HOLD);
		rightmotorback.move(0);
	}

//Arcade Control X Drive Base
	/*if(master.get_analog(ANALOG_LEFT_Y)){
      leftmotorfront.move(master.get_analog(ANALOG_LEFT_Y));
      leftmotorback.move(master.get_analog(ANALOG_LEFT_Y));
      rightmotorfront.move(-master.get_analog(ANALOG_LEFT_Y));
      rightmotorback.move(-master.get_analog(ANALOG_LEFT_Y));
    }
		if(master.get_analog(ANALOG_RIGHT_X)) {
      leftmotorfront.move(master.get_analog(ANALOG_RIGHT_X));
      leftmotorback.move(master.get_analog(ANALOG_RIGHT_X));
      rightmotorfront.move(master.get_analog(ANALOG_RIGHT_X));
      rightmotorback.move(master.get_analog(ANALOG_RIGHT_X));
		}
		else{
    	leftmotorfront.move(0);
    	rightmotorfront.move(0);
      leftmotorback.move(0);
      rightmotorback.move(0);
		}*/

      pros::delay(2);

	}
}

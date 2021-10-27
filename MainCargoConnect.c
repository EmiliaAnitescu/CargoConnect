#pragma config(Sensor, S1,     leftColor,      sensorEV3_Color)
#pragma config(Sensor, S2,     attachmentColor, sensorEV3_Color)
#pragma config(Sensor, S3,     gyro,           sensorEV3_Gyro)
#pragma config(Sensor, S4,     rightColor,     sensorEV3_Color)
#pragma config(Motor,  motorA,          leftAttachment, tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorB,          rightDrive,    tmotorEV3_Large, PIDControl, reversed, driveRight, encoder)
#pragma config(Motor,  motorC,          leftDrive,     tmotorEV3_Large, PIDControl, reversed, driveLeft, encoder)
#pragma config(Motor,  motorD,          rightAttachment, tmotorEV3_Medium, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//



// Global Variables - These can be used anywhere in any function.  They are global in scope.
// These need to be before the include functions so that they can be defined before the compiler wants to use them.  
float wheelDiameterInMM;
int reflectedLightIntensityOnBlack;
int reflectedLightIntensityOnWhite;
float widthBetweenWheelsInMM;
bool forwardMotorMovementIsPositive;


// Files to Include
#include "MiscDriveFunctions.C"
#include "GyroDriveFunctions.C"
#include "EncoderDriveFunctions.C"
#include "EncoderTurnFunctions.C"
#include "LineFollowingFunctions.C"


task main()
{

	// Setup parameters that may be different on different robots
	wheelDiameterInMM = 62.4;				// This is on the side of every lego wheel.
	widthBetweenWheelsInMM = 96.72; 			// Width between wheels in mm.  Each lift arm width is 7.44mm wide
	reflectedLightIntensityOnBlack = 10;			// Color sensor reading when reading black.
	reflectedLightIntensityOnWhite = 100; 			// Color Sensor reading when reading white.
	forwardMotorMovementIsPositive = false;  		// Do the encoders go posiitive when moving forward. (False = negative)


	// Reset the gyroscoe and wait 100ms to settle
	resetGyro(gyro);
	sleep(100);

	// Drive straight using the gyro to get on top of the line to follow
	driveStraightGyroDistance(50, 17, 0, false);

	// Line follow for distance
	lineFollowForDistance(15, 15.5, 2, 2, false);

	// LIne follow until we see the white line
	lineFollowUntilLine(10, 2, 2, 1, false);

	// Line follow until we see the black line
	lineFollowUntilLine(10, 2, 2, 2, false);
	
	


}

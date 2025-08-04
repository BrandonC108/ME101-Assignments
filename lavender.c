/*
Brandon Choi
Stephanie Huang
codename lavender.c
Group 2
*/
task main()
{
	SensorType[S1] = sensorEV3_Touch;
	SensorType[S2] = sensorEV3_Ultrasonic;
	SensorType[S3] = sensorEV3_Color;
	SensorType[S4] = sensorEV3_Gyro;
	wait1Msec(50);
	SensorMode[S3] = modeEV3Color_Color;
	wait1Msec(50);
	SensorMode[S4] = modeEV3Gyro_Calibration;
	wait1Msec(50);
	SensorMode[S4] = modeEV3Gyro_RateAndAngle;
	wait1Msec(50);
	nMotorEncoder[motorA] = 0;

	wait1Msec(2000);


	displayString(2, "Group 2 BC SH");

	while(!getButtonPress(buttonAny))
	{}
	while(getButtonPress(buttonAny))
	{}
	motor(motorA) = motor(motorD) = 50;
	wait1Msec(2000);
	motor(motorA) = motor(motorD) = 0;
	wait1Msec(2000);
	motor(motorA) = motor(motorD) = -20;
	while(nMotorEncoder[motorA] > 0)
	{}
	motor(motorA) = motor(motorD) = 0;

	wait1Msec(2000);
	motor(motorA) = -20;
	motor(motorD) = 20;
	while(getGyroDegrees(S4) < 90)
	{}
	motor(motorA) = motor(motorD) = 0;

	while(SensorValue(S3) != (int)colorRed)
	{}


}

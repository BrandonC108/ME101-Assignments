void configureAllSensors()
{
	SensorType[S1] = sensorEV3_Touch;
	SensorType[S2] = sensorEV3_Ultrasonic;
	SensorType[S3] = sensorEV3_Color;
	wait1Msec(50);
	SensorMode[S3] = modeEV3Color_Color;
	wait1Msec(50);
	SensorType[S4] = sensorEV3_Gyro;
	wait1Msec(50);
	SensorMode[S4] = modeEV3Gyro_Calibration;
	wait1Msec(50);
	SensorMode[S4] = modeEV3Gyro_RateAndAngle;
	wait1Msec(50);
}

void rotateRobot(int angle, int motorPower)
{
	motorPower = abs(motorPower);
	if (angle > 0)
	{
		motor[motorA] = -motorPower;
		motor[motorD] = motorPower;
	}
	else
	{
		motor[motorA] = motorPower;
		motor[motorD] = -motorPower;
	}
	resetGyro(S4);
	while (abs(getGyroDegrees(S4)) < abs(angle))
	{}
	motor[motorA] = motor[motorD] = 0;
}

void display(int groupNum, int lineNum)
{
	displayString(lineNum," Group .%i ", groupNum, " DW BC ");
}

void driveRobot(int motorPower, int driveTime)
{
	motor[motorA] = motor[motorD] = motorPower;
	wait1Msec(driveTime * 1000);
	motor[motorA] = motor[motorD] = 0;
}

void driveMotor(int motorPowerA, int motorPowerD, int driveTime)
{
	motor[motorA] = motorPowerA;
	motor[motorD] = motorPowerD;
	wait1Msec(driveTime * 1000);
	motor[motorA] = motor[motorD] = 0;
}

float buttonPress()
{
	clearTimer(T1);
	while(!getButtonPress(buttonEnter))
	{}
	time1[T1] = 0;
	while(getButtonPress(buttonEnter))
	{}
	return time1[T1];
}

void colorSensed(float timePressed)
{
	while (SensorValue[S3] != (int)colorRed && SensorValue[S3] != (int)colorBlue)
	{}
	if (SensorValue[S3] == (int)colorRed)
	{
		driveMotor(-50, -40, timePressed);
	}
	if (SensorValue[S3] == (int)colorBlue)
	{
		rotateRobot(45, 25);
		driveRobot(50, timePressed);
	}
}



task main()
{
	configureAllSensors();
	display(16, 5);
	buttonPress();
	colorSensed(buttonPress());







}

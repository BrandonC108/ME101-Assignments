
task main()
{
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

	while(SensorValue[S2] != 40+20)
	{}
	motor(motorA) = motor(motorD) = -50;

	wait1Msec(5000);
	motor(motorA) = motor(motorD) = 0;

	while(SensorValue[S3] != (int)colorBlue)
	{}
	float dist = nMotorEncoder[motorA]*(PI*2.75)/180;
	displayString(1, "%f", abs(dist));

	wait1Msec(3000);
	resetGyro(S4);
	motor(motorA) = 10;
	motor(motorD) = -10;
	while(getGyroDegrees(S4) < 180)
	{}

	motor(motorA) = motor(motorD) = 0;


}

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
void startsequence(){
	while(SensorValue[S1] == 0)
	{}
}
int selectColor(){
	displayString (1, "left for color, right for color, up for color, down for color");
	while(!getButtonPress(buttonAny))
	{}
	//wait for button press
	if (getButtonPress(buttonDown)){
		return 1;
	}
	else if (getButtonPress(buttonLeft)){
		return 2;
	}
	else if (getButtonPress(buttonRight)){
		return 3;
	}
	else if (getButtonPress(buttonUp)){
		return 4; //associate colour with numbers
	}
	return 0;
}
void spinWheel(){
	motor[motorA] = 100;
	wait1Msec(1000*20);

}
void slowDown(){

	int randomNum = random(10);
	while (motor[motorA] != 0){
		wait1Msec(3000);
		if (motor[motorA] >= randomNum){
			motor[motorA] -= randomNum;
		}
		else { //makes sure it does not go to negative power
			motor[motorA] = 0;
		}
		wait1Msec(3000);
	}
}
void calibrate(){

}
int findWin(){
	return 1;
}
task main()
{
	configureAllSensors();
	wait1Msec(50);
	startsequence();
	wait1Msec(50);
	selectColor();
	wait1Msec(50);
	spinWheel();
	wait1Msec(50);
	slowDown();
	wait1Msec(2000);
	calibrate();
	wait1Msec(50);
	findWin();
	wait1Msec(50);


}

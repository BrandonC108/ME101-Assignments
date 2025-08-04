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

void spin(int deg)
{
	motor[motorA] = 5;
	nMotorEncoder[motorA] = 0;
	while(nMotorEncoder[motorA] < deg)
	{}
	motor[motorA] = 0;
}


void spinRandom(int speed,int s) {
	int t = rand()%10;
	motor[motorA] = speed;
	wait1Msec(t * 1000);
	motor[motorA] = s;
}

void spinSlow(int timeInitial, int speed )
{
	int decrement = rand()%10;
	motor[motorA] = speed;
	wait1Msec(timeInitial * 1000);
	while(speed > 0)
	{
		// Range between 120-200 ms, between 6-10 s for a cycle to finish
		wait1Msec(200 + 10*decrement);
		speed -= 1;
		motor[motorA] = speed;
	}
	motor[motorA] = 0;
}

void spinToBlack() {
	motor[motorA] = 5;
	while (SensorValue[S3] != (int)colorBlack)
	{}
	nMotorEncoder[motorA] = 0;
	while(nMotorEncoder[motorA] < 30)
	{}
	motor[motorA] = 0;
}

void launchBall() {
	nMotorEncoder[motorD] = 0;
	motor[motorD] = 100;
	while (nMotorEncoder[motorD] < 755)
	{}
	motor[motorD] = 0;
}

void displayColour(int col, string & colour) {

	eraseDisplay();

	if (col == (int)colorNone) {
		colour = "None";
	} else if (col == (int)colorBlack){
		colour = "Black";
	} else if (col == (int)colorBlue){
		colour = "Blue";
	} else if (col == (int)colorBrown){
		colour = "Brown";
	} else if (col == (int)colorGreen){
		colour = "Green";
	} else if (col == (int)colorRed){
		colour = "Red";
	} else if (col == (int)colorWhite){
		colour = "White";
	} else if (col == (int)colorYellow){
		colour = "Yellow";
	}
}

float averageDistance() {
	float totalDistance = 0;
	int count = 0;
	time1[T2] = 0;

	while (time1[T2] < 1500) {
		totalDistance += getUSDistance(S2);
		count++;
	}

	return totalDistance/count;

}



void spinCoin(int deg)
{

	if (deg > 0) {
		motor[motorB] = 5;
		nMotorEncoder[motorB] = 0;
		while(nMotorEncoder[motorB] < deg)
		{}
		motor[motorB] = 0;
	} else if (deg  < 0) {
		motor[motorB] = -5;
		nMotorEncoder[motorB] = 0;
		while(nMotorEncoder[motorB] > deg)
		{}
		motor[motorB]=0;
	}
}

int detected() {

	int count = 0;

	while(!getButtonPress(buttonEnter)){
		//eraseDisplay();
		wait1Msec(50);
		displayString(5, "Press Enter When Ready");
		if(SensorValue[S4] != 0){
				count++;
				wait1Msec(1000);
				//displayString(1,"%i", count);
				resetGyro(S4);
		}

	}

		return count;
}
int winningColor(int col){
	//int col = 0;
	if (col == (int)colorBlack){
		return 4;
	} else if (col == (int)colorBlue){
		return 2;
	} else if (col == (int)colorRed){
		return 1;
	} else if (col == (int)colorWhite){
		return 4;
	} else if (col == (int)colorYellow){
		return 3;
	} else {
		return 0;
	}
}

int checkBallAndColor() {
	wait1Msec(2000);
	float difference = 0;
	float previousDistance = 5.0;
	while (abs(difference) < 1.0) {
		float currentDistance = averageDistance(); //getUSDistance(S2);
		displayString(1, "Distance (cm): %f", currentDistance);
		wait1Msec(500);
		spin(45);
		string colour = "";
		displayColour(SensorValue[S3], colour);
		displayString(2,"%s", colour);
		difference = currentDistance - previousDistance;
		previousDistance = currentDistance;
		displayString(3,"%f", abs(difference));
 	}
	motor[motorA] = 0;
	return winningColor(SensorValue[S3]);
}



void ReleaseCoin(int count) {
	int degrees = 115;

	/*while(!getButtonPress(buttonBack))
	{

		displayString(1,"%i", count);
		if(getButtonPress(buttonAny)){
			spinCoin(degrees);
			wait1Msec(200);
			spinCoin(-degrees);
		}
	}*/


	for(int i = 0; i < count; i++) {
		spinCoin(degrees);
			wait1Msec(200);
			spinCoin(-degrees);
			wait1Msec(200);
		}
}


int PickColor(){
	int colour = 0;
	eraseDisplay();
	displayString(1, "Pick a Color");
	displayString(2, "Red, Blue, Yellow, White");
	displayString(3, "Up , Down, Right , Left ");
	while(!getButtonPress(buttonEnter) && colour == 0){
		if(getButtonPress(buttonUp))
				colour = 1; //red
		if(getButtonPress(buttonDown))
				colour = 2; //blue
		if(getButtonPress(buttonRight))
				colour = 3; //yellow
		if(getButtonPress(buttonLeft))
				colour = 4; //white

	}
	return colour;

}

task main()
{
	configureAllSensors();
	//string colours[] = {"white","yellow",
	nMotorEncoder[motorA] = 0;
	time1[T1] = 0;
	bool stopPlay = false;
	do {
		//wait for coin insert
		int count = detected();
		displayString(1,"%i", count);
		wait1Msec(2000);
		while(count == 0)
		{}
		int colorPick = PickColor();
		while(colorPick == 0)
		{}
		eraseDisplay();
		displayString(2, "Press Enter to Spin");
		while(!getButtonPress(buttonEnter))
		{}
		while(getButtonPress(buttonEnter))
		{}
		//starts game
		spinRandom(20,20);
		launchBall();

		spinSlow(3,50);
		wait1Msec(50);
		spinToBlack();
		wait1Msec(1000);
		int winner = checkBallAndColor();

		if(winner == colorPick)
			ReleaseCoin(count);

		eraseDisplay();
		displayString(2, "Play again?");
		displayString(3, "Press Enter to Play Again");
		displayString(4, "Press Back to Exit");

		while(!getButtonPress(buttonAny)){
			if(getButtonPress(buttonBack)){
				stopPlay = true;
			}//if back, exits game
		}


	} while(stopPlay != true);







}

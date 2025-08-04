#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>

using namespace std;

const int MAXPARK = 50;
const int INDEX = 2; // 0 for student or faculty, 1 for parking spot
const int MAXUPDATE = 30;

int parking(ifstream & fin, string parkingName[MAXPARK], 
	int parkNum[MAXPARK][INDEX])
{
	int num = 0;
	
	for(int i = 0; i < MAXPARK; i++){
		parkNum[i][1] = -1;
		parkNum[i][0] = -1;
		parkingName[i] = ""; // sets all spots to be empty initially
		fin >> parkNum[i][0] >> parkingName[i] >> parkNum[i][1];
		if (parkingName[i] != "")
			num++;
	}
	return num;
}

void updateParker (ifstream & fin, int status[MAXUPDATE], string parkingName[MAXUPDATE])
{
	for(int i = 0; i < MAXUPDATE; i++)
	{
		fin >> status[i] >> parkingName[i];
	}
	return;
}


void removeParker(string name[MAXPARK], string parkName[MAXPARK], 
		int parkNum[MAXPARK][INDEX], int & num)
{
	
	for(int i = 0; i < num; i++){
		if(name[i] == parkName[i]){
			// Mark as removed
			parkName[i] = "";
			parkNum[i][0] = -1;
			parkNum[i][1] = -1;

			// Shift everything left to fill the gap
			for (int j = i; j < num - 1; ++j) {
				parkName[j] = parkName[j + 1];
				parkNum[j][0] = parkNum[j + 1][0];
				parkNum[j][1] = parkNum[j + 1][1];
			}

			// Mark the last element as empty
			parkName[num - 1] = "";
			parkNum[num - 1][0] = -1;
			parkNum[num - 1][1] = -1;

			num--; // Decrease the total count
			return;
		}
	}
	
}

void addParker(string name, int status, string parkName[MAXPARK], 
		int parkNum[MAXPARK][INDEX], int & num, int freePark[MAXPARK])
{
	for(int i = 0; i < MAXPARK; i++){
		if(parkNum[i][0] == -1){
			parkName[i] = name;
			parkNum[i][0] = status; 
			num++;
			return;
		}
	}
}

//lowest valid available parking space, if student starting at 126(after staff, staaff 101-125/ if not lowest 126-150
int numValidspace(int status, string name, status[], string parkName[])
{
	int spaceNum = 0;
	
	if(status == 0) // if they are students
	{
		for (int i = 25, i < MAXPARK, i++)
		{
			if (parkName[i] )
		}
	} else
	{
		
	}
	
}
bool assignParker(int spots, string parkingName[MAXPARK], 
int parkNum[MAXPARK][INDEX], int num)
{
	for (int i = 0; i < num; i++){
		if(parkNum[i][0] == 1 && parkNum[i][1] < 126 && parkNum[i][1]>= 101){
			return true;
		} 
		else if(parkNum[i][0] == 1 && parkNum[i][1] > 126)
		{ // removes their current spot 
			parkNum[i][1] = -1;
			return false;
		}
		else if(parkNum[i][0] == 0 && parkNum[i][1]>= 101)
		{ //removes their current spot
			parkNum[i][1] = -1;
			return false;
		}
	}
}

void sortParker(bool has_spot, string parkingName[MAXPARK], 
	int parkNum[MAXPARK][INDEX], int freePark[MAXPARK], int num, int free)
{

}

void output(ofstream & fout, int status, string name, int spot){
	

	cout << status << " " << name << " " << spot << endl;
}

int main(){
	
	ifstream finPark ("parking_current.txt");
	
	if (!finPark){
		cout << "file failed to open";
		return EXIT_FAILURE;
	}
	ifstream finR ("parking_remove.txt");
	if (!finPark){
		cout << "file failed to open";
		return EXIT_FAILURE;
	}
	ifstream finA ("parking_add.txt");
	if (!finPark){
		cout << "file failed to open";
		return EXIT_FAILURE;
	}
	ofstream fout ("parkingoutput.txt");
	
	string AddName[MAXPARK] = {};
	int AddNum[MAXPARK][INDEX] = {};
		//parallel array
	string RemoveName[MAXPARK] = {};
	int RemoveNum[MAXPARK][INDEX] = {};
		//parallel array
	string parkName[MAXPARK] = {};
	int parkNum[MAXPARK][INDEX] = {};
		//parallel 2D array for status and parking number
	int freePark[MAXPARK] = {101,102,103,104,105,106,107,
	108,109,110,111,112,113,114,115,116,117,118,119,120,121,122
	,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137
	,138,139,140,141,142,143,144,145,146,147,148,149,150};
	
	int free = 50;// to count free parking spots
	
	int number_people = parking(finPark, parkName, parkNum);
	newparking(finA, AddName, AddNum);
	newparking(finR, RemoveName, RemoveNum);
	
	cout << "Initial output" << endl;
	for(int i = 0; i < number_people; i++){
		
		output(fout, parkNum[i][0], parkName[i], parkNum[i][1]);
	}
	
	removeParker(RemoveName, sparkName, parkNum, number_people);
		

	
	cout << "Reassigned output" << endl;
	for(int i = 0; i < number_people; i++){
		
		output(fout, parkNum[i][0], parkName[i], parkNum[i][1]);
	}
	
	finPark.close();
	finR.close();
	finA.close();
	fout.close();
	
	return EXIT_SUCCESS;
}
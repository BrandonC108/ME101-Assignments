/*
	Group 18
	A -  Brandon Choi
	B - Charlotte Ngo
*/

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int MAXPARK = 50;
const int INDEX = 2; // 1 for student or faculty, 0 for parking spot number
const int MAXUPDATE = 30;

int parking(ifstream & fin, string parkingName[MAXPARK], 
	int parkNum[MAXPARK])
{
	int num = 0;
	int status = 0, spot = 0;
	string name = "";
	
	while(fin>> status >> name >> spot){
		for (int i = 0; i < MAXPARK; i++)
		{
			parkingName[spot-101] = name;
			parkNum[spot-101] = status;
			num++;
		}
	}
	return num;
}

/*void updateParker(ifstream & fin, int status[MAXUPDATE], string parkingName[MAXUPDATE])
{
	for(int i = 0; i < MAXUPDATE; i++)
	{
		fin >> status[i] >> parkingName[i];
	}
	return;
}*/
int updateParker(ifstream & fin, int status[MAXUPDATE], 
string parkingName[MAXUPDATE])
{

    int count = 0;
    while (fin >> status[count] >> parkingName[count] && count < MAXUPDATE)

        count ++;
        
    return count;

}
void removeParker(string name[MAXPARK], string parkName[MAXPARK], 
		int parkNum[MAXPARK])
{
	//removes parker
	for(int i = 0; i < MAXPARK; i++){
		for(int j = 0; j < MAXUPDATE; j++){
		//checks for people that need to be removed
			if(parkName[i] == name[j]){
				parkName[i] = "";
				parkNum[i] = -1; //assigns -1 to signal empty
				break;
			}
		}
	}
	
}
const int MINSPACE = 101;
int numValidspace(int status, string name, int Status[30], string parkName[50])
{
	int spaceNum = 0;
	
	if(status == 0) // if they are students
	{
		for (int i = 25; i < MAXPARK ; i++){
		//returns spot number above 125
			if (parkName[i] == ""){
				spaceNum = i + MINSPACE;
				return spaceNum;
			}
		}
	} else if (status == 1)// if they are faculty
	{
		for (int i = 0; i < MAXPARK; i++){
			// returns parking starting from 101
 			if (parkName[i] == ""){
				spaceNum = i + MINSPACE;
				return spaceNum;
			}
		}
				
	}
	return -1;
}

bool assignParker(string name, int status, string parkName[MAXPARK], 
		int parkNum[MAXPARK], int spot)
{
	if(spot == -1)// checks if theres invalid spot
	{
		return false;
	}else { //if spot is valid, assigns people to spot
		parkName[spot - 101] = name;
		parkNum[spot - 101] = status;
		return true; // signals that person was given a spot
	}
	
}



void output(int i, ofstream & fout, int status, string name){
	

	fout << status << " " << name <<  " "<< i + 101 << endl;
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
	ofstream fout ("parking_output.txt");
	
	string AddName[MAXPARK] = {};
	int AddNum[MAXPARK] = {};
		//parallel array
	string RemoveName[MAXPARK] = {};
	int RemoveNum[MAXPARK] = {};
		//parallel array
	string parkName[MAXPARK] = {};
	int parkNum[MAXPARK] = {};
		//parallel array for status and name
	

	
	int number_people = parking(finPark, parkName, parkNum);
	updateParker(finA, AddNum, AddName);
	updateParker(finR, RemoveNum, RemoveName);
	// reads in data
	
	fout << "Initial output" << endl;
	for(int i = 0; i < MAXPARK; i++){
		
		output(i, fout, parkNum[i], parkName[i]);
	}
	fout << endl;
	//outputs initial parking assignments
	removeParker(RemoveName, parkName, parkNum);

	//removes people
	for(int i = 25; i < MAXPARK; i++){
		int spotnum = numValidspace(parkNum[i], parkName[i], parkNum, parkName);
		if (parkNum[i] == 1 && parkName[i] != "")
		//checks for status, and if there is name
		{
			assignParker(parkName[i], parkNum[i], parkName, parkNum, spotnum);
			parkNum[i] = -1;
			parkName[i] = "";
		}
	}
	//reorganizes any faculty members above 125
	int NoSpot = 0;
	string hasNoSpot[MAXUPDATE] = {};
	for (int i = 0; i < MAXUPDATE; i++){
		bool has_spot = false;
		int spotNum = numValidspace(AddNum[i], AddName[i], parkNum, parkName);
		has_spot = assignParker(AddName[i], AddNum[i], parkName, 
					parkNum, spotNum);
		// brings in number that is available
		//assigns parker based on status compared to the spot available
		int j = 0;
		if(has_spot == false && AddName[i] != ""){
			hasNoSpot[NoSpot] = AddName[i];
			NoSpot++; //counts people who were not given a spot
		//saves people who were not given a spot
		}
	}
	// adds in new people with assigned parking for faculty

	fout << "Reassigned output" << endl;
	for(int i = 0; i < MAXPARK; i++){
		
		output(i, fout, parkNum[i], parkName[i]);
	}
	fout << endl;
	//outputs
	fout << "People without assigned parking:" << endl;
	
	for (int i = 0; i < NoSpot; i++){
		if(hasNoSpot[i] != "")
			fout << hasNoSpot[i] << " had no spot" << endl;
	}
	//outputs
	finPark.close();
	finR.close();
	finA.close();
	fout.close();
	
	return EXIT_SUCCESS;
}


/*

Initial output
1 Hamdullahpur_Feridun 101
1 Yerxa_Meagan 102
0  103
1 Musselman_Kevin 104
0  105
0  106
0  107
1 Gryguc_Andrew 108
1 Campbell_Emily 109
0 Lovelace_Ada 110
0  111
0 Archimedes_A 112
0 da_Vinci_Leo 113
1 MacGregor_Carolyn 114
0  115
0 McGregor_Martine 116
1 Gorman_David 117
1 Owen_Bill 118
0  119
1 Nairn_David 120
0  121
1 Katherine_Idzik 122
1 Consell_Ryan 123
1 McKay_Ken 124
1 Vandekerckhove_Sam 125
0 Tesla_Nick 126
0  127
0 Otto_Nick 128
0 Turing_Al 129
1 Teertstra_Peter 130
0 Aho_Alf 131
0 Bell_Alex 132
0 Stephenson_Geo 133
0 Musk_El 134
0 Hopper_Grace 135
0 Oh_Henry 136
1 Milne_Andrew 137
0  138
1 Cramer_Zack 139
0  140
0 Edison_Tom 141
1 Hulls_Carol 142
0  143
1 Payton_Forrest 144
0 Babbage_Chip 145
1 Casale_Matt 146
1 Goel_Vivek 147
1 Harris_Dave 148
0  149
1 Wells_Mary 150

Reassigned output
1 Teertstra_Peter 101
1 Milne_Andrew 102
1 Cramer_Zack 103
1 Musselman_Kevin 104
1 Hulls_Carol 105
1 Payton_Forrest 106
1 Goel_Vivek 107
1 Harris_Dave 108
1 Wells_Mary 109
0 Lovelace_Ada 110
1 Lala_Divya 111
0 Archimedes_A 112
0 da_Vinci_Leo 113
1 McGregor_Martine 114
1 Zhou_Yang 115
1 Dhaliwal_Navdeep 116
1 Gorman_David 117
1 Owen_Bill 118
1 Meunier_Sarah 119
1 Benoit_Michael 120
-1  121
1 Katherine_Idzik 122
1 Consell_Ryan 123
-1  124
1 Vandekerckhove_Sam 125
0 Tesla_Nick 126
0 Payette_Jill 127
0 Otto_Nick 128
0 Turing_Al 129
0 Fleming_San 130
0 Aho_Alf 131
0 Bell_Alex 132
0 Eiffel_Gus 133
0 Wozniak_Stef 134
0 Hopper_Grace 135
0 Clarke_Edi 136
0 Lamarr_H 137
0 Roebling_Em 138
0 Jemison_May 139
0 Jackson_Mary 140
0 Johnson_Kat 141
0 Vaughan_Dot 142
0 Tlaa_Sha 143
0 Curie_Mary 144
0 Babbage_Chip 145
0 Stroustrup_Bj 146
0 Imahara_Gr 147
0 Frize_Molly 148
0 Guppy_Sara 149
0 Roebling_Emma 150

People without assigned parking:
Imhotep_P had no spot
Tepe_Go had no spot
Armstrong_Nick had no spot
Pike_Robby had no spot

*/
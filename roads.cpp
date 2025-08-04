#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

void readData(int Map[372][378], ifstream & fin) {
    char gridtype;
    int Index, lowlim, uplim;

    while (fin >> gridtype >> Index >> lowlim >> uplim) {
        if (gridtype == 'R') {
            // 'R' means row: increment columns in that row
            for (int i = lowlim; i <= uplim && i < 378; ++i) {
                Map[Index][i] += 1;
            }
        }
        else if (gridtype == 'C') {
            // 'C' means column: increment rows in that column
            for (int i = lowlim; i <= uplim && i < 372; ++i) {
                Map[i][Index] += 1;
            }
        }
    }
}

int daysclosed (int Map[372][378] ,bool CMap[372][378], int & Hrow, int & Hcol){
	
	int daysP = 70;
	int longestdays = 0;
	for (int i = 0; i < 372; i++){
		for  (int j = 0; j <378; j++){
			if (Map[i][j]>= daysP){
				CMap[i][j] = true;
				if (Map[i][j] > longestdays){
					longestdays = Map[i][j];
					Hcol = j;
					Hrow = i;
				}
			}
		}
	}
	return longestdays;
}

void output(bool CMap[372][378]){
	
	for (int i = 0; i < 372; i++){
		for  (int j = 0; j <378; j++){
			if (CMap[i][j] == true){
				cout << i << " "<< j << " was closed more than 70 days." << endl;
			}
		}
	} 
}
void printMap(int Map[372][378], ofstream & fout) {
    for (int i = 0; i < 372; ++i) {
        for (int j = 0; j < 378; ++j) {
            fout << Map[i][j] << " ";
        }
        fout << endl;
    }
}


int main (){
	
	ifstream fin("roadsclosed.txt");
	ofstream fout ("roadMap.txt");
	
	int Map[372][378] = {};
	bool CMap[372][378] = {};
	
	int Hrow = -1, Hcol = -1;
	readData(Map, fin);
	
	printMap(Map, fout);
	int longestdays = daysclosed(Map, CMap, Hrow, Hcol);
	if (Hrow != -1 && Hcol != -1) {
	    cout << Hrow << " " << Hcol << " was closed the longest.";
	    cout << " It closed for " << longestdays << " days." << endl;
	} else {
	    cout << "No location was closed for more than 70 days." << endl;
	}


	output(CMap);
	
	fin.close();
	fout.close();
	return 0;
	
}
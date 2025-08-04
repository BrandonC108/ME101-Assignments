#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>

using namespace std;

const int sensors = 15;
const int timeE = 15;

const int length = 225;

const int location = 2;

void readData(ifstream & fin, int location[][2], int wind[][timeE], int rain[][timeE])
{
    string time = "";
    int lat, lon, w, r;

    for (int t = 0; t < timeE; t++) {
        for (int s = 0; s < sensors; s++) {
            fin >> time >> lat >> lon >> w >> r;

            // Only store location once (first time we see it)
            if (t == 0) {
                location[s][0] = lat;
                location[s][1] = lon;
            }

            wind[s][t] = w;
            rain[s][t] = r;
        }
    }
}

void output(ofstream & fout, int location[][2], int wind[][timeE], int rain[][timeE], int observer[length][2], int numObs)
{
    bool warned[sensors] = {}; // Track which sensors triggered warnings

    // Check sensor-based warnings
    for (int i = 0; i < sensors; i++) {
        bool warning = true;
        for (int t = 0; t < timeE; t++) {
            if (wind[i][t] <= 90 || rain[i][t] <= 50) {
                warning = false;
                break;
            }
        }
        if (warning) {
            fout << location[i][0] << " " << location[i][1] << endl;
            warned[i] = true;
        }
    }

    // Check observer-based warnings
    for (int j = 0; j < numObs; j++) {
        bool alreadyWarned = false;
        for (int i = 0; i < sensors; i++) {
            if (location[i][0] == observer[j][0] && location[i][1] == observer[j][1] && warned[i]) {
                alreadyWarned = true;
                break;
            }
        }
        if (!alreadyWarned) {
            fout << observer[j][0] << " " << observer[j][1] << endl;
        }
    }
}

int main(){
	
	
	ifstream fin("sensor.txt");
	
	ifstream fin1("observe.txt");
	
	ofstream fout("thunderstormOutput.txt");
	
	int locations[sensors][location] = {};
	int wind[sensors][timeE] = {};
	int rain[sensors][timeE] = {};
	int observer[length][location] = {};
	
	int numObs = 0;
	
	while (fin1 >> observer[numObs][0] >> observer[numObs][1]){
		numObs++;
		
	}
	readData(fin, locations, wind, rain);
	output(fout, locations, wind, rain, observer, numObs);
	
	
	
	
	
	
	fin.close();
	fin1.close();
	fout.close();
	
	return EXIT_SUCCESS;
	
}
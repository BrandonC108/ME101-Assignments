#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAX = 50;

int mountains(ifstream & fin, string mountain[MAX], int height[MAX])
{
	int numMount = 0;
	fin >> numMount;
	for (int i = 0; i < numMount; i++){
		fin >> mountain[i] >> height[i];
		//  for mountain name, for mountain height
		
	}
	return numMount;
}
void tallest_M(int & tallest, string & tallMount, 
			string mountain[MAX], int height[MAX], int numMount){
	tallest = height[0];
	tallMount = mountain[0];
	for (int i = 1; i < numMount; i++){
		if (height[i] > tallest)
		{
			tallest = height[i];
			tallMount = mountain[i];
		}
	}
}

void output(ofstream & fout, int maxHeight, string mountain, int height){
	
	if (maxHeight-height == 0){
		fout << "Mount "<< mountain << " is the tallest mountain." << endl;
	}
	else {
		fout << "Mount " << mountain << " is " << maxHeight - height 
		<< " meters shorter than the tallest mountain." << endl;
	}
	
}

int main(){
	
	ifstream fin("mountain.txt");
	
	if (!fin){
		return EXIT_FAILURE;
	}
	ofstream fout("TallestOutput.txt");
	
	string mountain[MAX] = {};
	int height[MAX] = {};
	
	int NumMount = mountains(fin, mountain, height);
	int tallest = 0;
	string tallMount = "";
	tallest_M(tallest, tallMount, mountain, height, NumMount);
	
	//cout << tallest << " " << tallMount;
	for (int i = 0; i < NumMount; i++){
		output(fout, tallest, mountain[i], height[i]);
	}
	
	fin.close();
	fout.close();
	
	return EXIT_SUCCESS;
}
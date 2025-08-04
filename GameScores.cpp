#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAX = 50;

int numPeople (ifstream & fin, string People[MAX], int Score[MAX][20]){
	
	int num = 0;
	
	for (int i = 0; i < MAX; i++)
	{
		fin >> People[i];
		if (People[i] != "")
			num++;
		for(int j = 0; j < 20; j++)
		{
			fin>> Score[i][j];
		}
	}
	return num;
}
int findName (string People[MAX], string Name){
	for (int i = 0; i < MAX; i++){
		if(Name == People[i])
			return i;
		else
			return -1;
	}
	
}

void UpdateScore(int NameIndex, int Game, int highScore, int Score[MAX][20]){
	
	if(NameIndex >= 0)
	{
		Score[NameIndex][Game] = highScore;
	}
}

void output(ofstream & fout, string name, int Score[MAX][20], int NameIndex){
	fout << name << " ";
	for (int i = 0; i < 20; i++)
		fout << Score[NameIndex][i] << " ";
	fout << endl;
}

int main (){
	
	ifstream finMain ("gameScores.txt");
	ifstream fin1 ("newScores1.txt");
	ifstream fin2 ("newScores2.txt");
	ofstream fout ("NewScoreOutput.txt");
	if(!finMain || !fin1 || !fin2)
	{
		return EXIT_FAILURE;
	}
	string People[MAX] = {};
	int Score[MAX][20] = {};
	
	int numberPeople = numPeople(finMain, People, Score);
	
	string name = "";
	int gameNum = 0, gameScore = 0;
	while(fin1 >> name >> gameNum >> gameScore){
		UpdateScore(findName(People, name), gameNum, gameScore, Score);
	}
	while(fin2 >> name >> gameNum >> gameScore){
		UpdateScore(findName(People, name), gameNum, gameScore, Score);
	}
	for (int i = 0; i < numberPeople; i++)
		output(fout, People[i], Score, i);
	
	fout.close();
	finMain.close();
	fin1.close();
	fin2.close();
}
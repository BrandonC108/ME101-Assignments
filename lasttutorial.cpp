#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

const size = 50;

void InitialBook(int & numBook, ifstream & fin, 
				titles[size], score[size][size])
{
	for (int i = 0; i < numBook; i++){
		fin >> titles[i] ;
		for(int j = 0; j < numBook; j++){
			fin >> score[i][j];
		}
	}	
		
}

void addBook(int & numBook, ifstream & fin, 
titles[size], score[size][size], newscore[size]){
	
	fin >> titles[numBook];

	for (int i = 0; i < numBook; i++){
		
		fin >> newscore[i];
		for(int j = 0; j < numBook; j++)
			score[i][j] = newscore [i];
			score [j][i] = newscore [i];
	}
	score[numBook][numBook];
	
	numBook++;
	
}

int main(){
	
	ifstream fin (" similar.txt");
	
	if(!fin){
		return EXIT_FAILURE;
		
	}
	int numBook = 0;
	fin >> numBook;
	
	string titles[size] = {};
	
	int score[50][50] = {};
	
	InitialBook(numBook, fin, titles, score);
	
	ifstream fin2 ("newBooks1.txt");
	if(!fin2){
		return EXIT_FAILURE;
	}
	
	int newscore[size] = {};
	
	addBook(numBook, fin2, newscore);

	
	
}

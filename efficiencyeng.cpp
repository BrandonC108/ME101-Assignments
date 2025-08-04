#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("comp_efficiency.txt");
	
	if(!fin)
	{
		cout << "file open invalid";
		return EXIT_FAILURE;
	}
	
	ofstream fout("output_eff.txt");
	double efficiency = 1 , high_eff = -1, low_eff = 2, last_eff = 0;
	string total_cmp = "", high_cmp = "", low_cmp = "", last_cmp = "";
	double comp_eff = 0;
	string name = "";
	
	while (fin >> name >>comp_eff)
	{
		efficiency *= comp_eff;
		
		if(comp_eff > high_eff)
		{
			high_eff = comp_eff;
			high_cmp = name;
		}
		if(comp_eff < low_eff)
		{
			low_eff = comp_eff;
			low_cmp = name;
		}
	}
	
	fout << "efficiency " << efficiency <<endl
		 << "max " << high_cmp << " " << high_eff << endl
		 << "min " << low_cmp << " " << low_eff << endl;
	
	fin.close();
	fout.close();
	
	return EXIT_SUCCESS;
}
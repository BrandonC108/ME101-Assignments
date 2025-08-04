/* 
	Group 16 Brandon Choi , Bianca Cortero
*/
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iomanip>


using namespace std;


int main(){
	ofstream fout("taxiout2.txt");
	ifstream fin("taxi.txt");
	
	if (!fin){
		
		cout << "file opened unsuccessfully.";
		return EXIT_FAILURE;
	}
	
	bool has_ogood = 0;
	int num_stops = 0, trip_count = 0;
	double x = 0, y = 0;
	double month_total = 0 , total_cost = 0;
	
	fout << setw(6) << " trip#" << setw(6) << " stops" 
			<< setw(5) << " over" << setw(9) << " tripDist"
			<< setw(9) << " tripCost" << setw(10) << " totalDist"
			<< setw(10) << " totalCost" << endl;
	
	while (fin >> has_ogood >> num_stops){
		
		double dist_total = 0;
		double last_x = 0, last_y = 0;
		for (int count = 1; count <= num_stops; count++){
			
			fin >> x >> y;
			dist_total += sqrt(pow((x-last_x),2)+pow((y-last_y),2));
			last_x = x;
			last_y = y;
			
		}
		dist_total += sqrt(pow((last_x),2)+pow((last_y),2));
		
		trip_count += 1;
		double trip_cost = 0;
		trip_cost += 18.5*num_stops + dist_total*2.85;
	
		if (has_ogood == 1){
			trip_cost *= 1.2;
		}
		month_total += dist_total;
		total_cost += trip_cost;
		
		if (trip_count <=6 || (trip_count-6)%10 == 0){
		
			fout << fixed << setprecision(2);
			fout << setw(6) << trip_count << setw(6) << num_stops 
				<< setw(5) << has_ogood << setw(9) << dist_total
				<< setw(9) << trip_cost << setw(10) << month_total
				<< setw(10) << total_cost << endl;
		}
		
	}
	
	
	
	
	
	
	fin.close();
	fout.close();
	return EXIT_SUCCESS;
}

/* 

  trip# stops over tripDist tripCost totalDist totalCost
     1     1    0    20.40    76.64     20.40     76.64
     2     2    1    13.07    89.09     33.47    165.73
     3     4    1    40.72   228.05     74.18    393.78
     4     3    1    44.20   217.78    118.39    611.55
     5     1    1    11.03    59.93    129.42    671.48
     6     2    0    21.65    98.70    151.07    770.18
    16     2    0    38.55   146.88    586.92   2543.35
    26     3    0    52.02   203.76   1025.51   4340.67
    36     3    1    44.43   218.56   1421.14   6032.28
    46     1    1    23.05   101.03   1768.19   7603.15
    56     3    0    73.87   266.03   2241.21   9465.03
    66     3    0    59.90   226.23   2723.44  11456.32
    76     1    1    27.68   116.86   3157.72  13193.79
    86     1    0    27.46    96.77   3577.86  14850.97
    96     3    0    39.43   167.88   3964.90  16480.56
   106     3    0    49.34   196.12   4297.56  17902.59
   116     3    0    76.20   272.67   4719.05  19589.59
   126     3    0    49.24   195.83   5116.50  21267.42
   136     1    0    29.26   101.89   5452.83  22619.92
   146     3    1    55.88   257.71   5832.74  24178.35
   156     1    0    24.63    88.70   6295.13  26075.60
   166     3    0    45.26   184.48   6830.14  28378.37
   176     2    1    47.54   206.97   7336.67  30482.27
   186     2    1    62.09   256.75   7805.48  32528.72
   196     3    1    61.32   276.32   8399.18  34908.53
   206     1    1    16.19    77.57   8826.53  36757.36
   216     2    1    28.74   142.69   9198.79  38275.93
   226     1    0    26.25    93.31   9528.62  39677.10
  



*/
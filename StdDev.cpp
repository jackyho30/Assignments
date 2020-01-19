#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

int main(const int argc, const char* const argv[]) {
	int rc = 0;
	
	if (argc < 2) {
		cerr << "Error: Unable to compute standard deviations over data set because no valid voltage readings were given"<<endl;
		return -1;
	}	
	int z = argc;
	int y = 1;
	float num = 0;
	float avg = 0;
	bool end = false;
	
	while (y != z){
		if (atof(argv[y]) > 0 && atof(argv[y]) < 150){
			num +=1 ;
			avg = avg + atof(argv[y]);
		}
		if (atof(argv[y]) < 0){
			end = true;
		}
		y += 1;
	}
	
	if (end == false){
		cerr << "Error: Missing terminator; exiting" <<endl;
		return -1;
	}
	
	y = 1;
	float volt = atof(argv[y]);
	avg = avg/num;
	
	if (num == 0) {
		cerr << "Error: Unable to compute standard deviations over data set because no valid voltage readings were given"<<endl;
		return -1;
	}
	double N = num;
	double total = 0;
	double delta = 0;
	double population = 0;
	double sample = 0;
	if (end == true){
		y = 1;
		volt = atof(argv[y]);
		while (num >=1 ){
			
			if (volt >=150 || volt == 0){
				cout <<"Warning invalid voltage reading " <<volt<< "ignored in calculation" << endl;				
				y += 1;
				volt = atof(argv[y]);
				rc = 1;
			}
			else if (volt <0){
				num = 0;
			}
			else if (volt > 0 && volt <150){
				delta = pow((volt - avg),2);
				y += 1;
				volt = atof(argv[y]);
				num -= 1 ;
				total += delta;
			}
		}
	}
	population = sqrt((1/N)*total);
	
	sample = sqrt((1/(N-1))*total);
	
		
	cout<< "Number of voltage readings: "<<N<< endl;
	
	if ((sample <= 0 && population <= 0 )||( N==0 )||(total ==0)) {
		cout<< "Population standard deviation: undefined" <<endl;
		cout<< "Sample standard deviation: undefined" <<endl;
	}
	else if (total != 0 && N==0){
		cout<< "Population standard deviation: infinity" <<endl;
		cout<< "Sample standard deviation: infinity" <<endl;
	}
	else{
		cout<< "Population standard deviation: " <<population<< endl;
		cout<< "Sample standard deviation: "<<sample<< endl;
	}
	return rc;
}
	
	
	
	
	
	
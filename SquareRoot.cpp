#include <iostream>
#include <stdlib.h>
using namespace std;

int main(const int argc, const char* const argv[]) {
	
	float num = atof(argv[1]);
	float x = 1;
	
	
	if (num < 0) {
		cerr <<"Error: cannot take the square root of a non-positive number; exiting" <<endl;
		return -1;
	}
	
	if (argc >2) {
		cerr << "Error: Expected 1 arguments; received " <<argc-1<<"; ignoring extraneous arguments"<<endl;
		
	}
		
	
	while ((num - x*x)/num > 0.00001 || -1*(num- x*x) /num > 0.00001) {
		x = (x+num/x)*0.5;
	}
	
	cout << "The square root of " << num << " is " << x << endl;
	return 0; 
}
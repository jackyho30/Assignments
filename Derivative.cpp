#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

int main(const int argc, const char* const argv[]) {
	int rc = 0;
	
	if (argc <2) {
		cerr << "Error: Expected 1 arguments; received " <<argc-1<<"; exiting" <<endl;
		return -1;
	}
	if (argc >2) {
		cerr << "Error: Expected 1 arguments; received " <<argc-1<<"; ignoring extraneous arguments"<<endl;
		;
	}
	
	if (argc >= 2) {
		float t = atof(argv[1]);
		float x = 0.0001;
		extern float f(float t);
		float s = (f(t+x) - f(t)) / x;
		cout << "The slope of f(t) at t = " <<t<< " is " << s << endl;
	}
	return rc;
}
		
	
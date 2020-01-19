#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

int main(const int argc, const char* const argv[]) {
	int rc = 0;
	
	if (argc <2) {
		cerr << "Error: Expected 1 arguments; received " <<argc-1<<"; exiting" <<endl;
		rc = -1;
		return rc;
	}
	if (argc >2) {
		cerr << "Warning: Expected 1 arguments; received " <<argc-1<<"; ignoring extraneous arguments"<<endl;
		rc = -1;
	}
	
	float t = atof(argv[1]);
	extern float f(float t);
	float s = (f(t+h)- f(t))/0.0001;
	cout << "The slope of f(t) at t = " <<t<< " is " << s << endl;
	return rc;
}
		
	
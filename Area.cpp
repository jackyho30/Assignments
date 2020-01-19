#include <iostream>
#include <stdlib.h>

using namespace std;
int main(const int argc, const char* const argv[]) {
	int rc = 0;
	//0.01 * ((f(x+0.01) +f(x))/2)
	//check for extra arguments and ignore if so
	if (argc > 3) {
		cout << "Warning: Expected 2 arguments; received " << argc-1 << "; ignoring extraneous arguments" <<endl; 
		return 1;
	}
	//check for too little arguments and end program if so
	if (argc < 3){
		cerr << "Error: Expected 2 arguments; received " << argc - 1 << "; exiting" << endl;
		return -1;
	}
	/*
	A = first x value
	x = copy of A to manipulate
	B = secon x value
	extern float f(float x) = function declaration
	a = total area
	sa = sections of smaller area
	*/
	float A = atof(argv[1]);
	float x = atof(argv[1]);
	float B = atof(argv[2]);
	extern float f(float x);
	float a = 0;
	float sa = 0;
	// Check that value A is smaller than B so we have a proper domain to check
	if (A > B) {
		cerr << "Error: invalid input"<< endl;
		return -1;
	}
	// Calculate the smaller areas and add them to the total area
	while (x < B){
		sa = 0.01 * ((f(x+0.01) +f(x))/2);
		a = a + sa;
		x = x +0.01;
	}

	cout << "The area under f(x) from " << A << " to " << B << " is " << a << endl;
	return rc;

}	
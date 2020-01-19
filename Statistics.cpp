#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;
int main(const int argc, const char* const argv[]) {
	int rc = 0;
	// if no voltages are given
	if (argc < 2) {
		cerr << "Error: Unable to compute statistics over data set because no valid voltage readings were given"<<endl;
		return -1;
	}
	int z = 1;
	float volt = atof(argv[z]);
	float args = argc-1;
	float max = 0;
	float min = 150;
	float total = 0;
	float x = 0;
	float avg = 0;
	float end = args+1;
	bool finish = false;
	bool negative = false;
	// runs while there are still arguments to check
	while (args > 0) {
		// checks off 1 argument from list and sets num to check next voltage
		args -= 1;
		z = z + 1;
		if (z == end) {
			finish = true;
		}
		// check if volt is in valid range
		if (volt > 0 && volt < 150) {
			// add to the total voltage and add to the number of valid voltages
			total = total + volt;
			x += 1;
			// change the max volt if in range
			if (volt > max) {
				max = volt;
			}
			// change the min volt if in range
			if (volt < min) {
				min = volt;
			}
		}
		if (volt>150) {
			// if voltage is not valid
			cout << "Warning: invalid voltage reading " <<volt<<" ignored in calculation" <<endl;
			rc = 1;
		}
		if (volt<0) {
			// if voltage is not valid
			negative=true;
		}
		// set the new voltage for the next test
		if (finish != true) {
			volt = atof(argv[z]);
		}
	}
	// calculate the average volt
	if (negative == true && x == 0) {
		cout << "Error: Unable to compute statistics over data set because no valid voltage readings were given"<<endl;
		rc= -1;
		return rc;
	}
	avg = total/x;
	// display error if no valid voltages were found 
	if (x == 0) {
		cerr << "Error: Unable to compute statistics over data set because no valid voltage readings were given"<<endl;
		return -1;
	}
	cout << "Number of voltage readings: " <<x<< endl;
	cout << "Minimum voltage: " <<min<< endl;
	cout << "Average voltage: " <<avg<< endl;
	cout << "Maximum voltage: " <<max<< endl;
	return rc;
}
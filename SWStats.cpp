#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;
int main(const int argc, const char* const argv[]) {
	int rc = 0;
	// if no voltages are given
	if (argc < 3){
		cerr << "Error: Unable to compute statistics over data set because there were not enough inputs" << endl;
		rc = -1;
		return rc;
	}
	
	int z = 2;
	float volt = atof(argv[z]);
	float args = argc-2;
	float max = 0;
	float min = 150;
	float total = 0;
	float y = 0;
	float end = args+2;
	bool finish = false;
	bool negative = false;
	
	bool initial = false;
	float argsInitial = args;
	float num = 0;
	int k = 2; 

	int windowSize = atoi(argv[1]);
	bool slide = true;
	float curMax = 0;
	float curMin = 150;
	
	if (windowSize <= 0){
		cerr << "Error: Non-positive window size invalid; exiting" << endl;
		return -1;
	}
	// Check all numbers for a terminator first
	while (argsInitial > 0 && initial == false) {
		num = atof(argv[k]);
		if (num < 0) {
			initial = true;
		}
		argsInitial -= 1;
		k += 1;
		
	}
	// End program if there is no terminator
	if (initial == false) {
		cerr << "Error: Missing terminator" <<endl;
		return -1;
	}
	
	//Column headings
	cout << "Window Size: " <<windowSize<<endl;
	cout << "Sample   Value  SWMinimum SWMaximum" << endl;
	// runs while there are still arguments to check
	while (args > 0) {
		//sets warning to false at beginning of loop
		bool warning = false;
		// checks off 1 argument from list and sets z to check next voltage
		args -= 1;
		// checks too see if all inputs have been checked
		if (z == end) {
			finish = true;
		}
		// if voltage is not valid
		if (volt<0) {
			negative = true;
			args = -1;
			finish = true;
		}
		
		// check if arguments are still availible for checking
		if (finish != true) {
			// add to the number of valid voltages
			y += 1;
			//check for invalid voltage and set warning to true if so
			if (volt >= 150 || volt == 0) {
				cout << "Warning: Invalid voltage reading " <<volt<<" ignored in calculation" <<endl;
				warning = true;
				rc = 1;
			}
			// change the max volt if in range
			else {
				int i = 0;
				curMax = 0;
				curMin = 150;
				while (i < (atoi(argv[1]))) {
					
					if ((z - i > 1) && (atof(argv[z-i]) > 0) && (atof(argv[z-i]) <150)){
						if (atof(argv[z-i]) > 0 && atof(argv[z-i]) < 150 && atof(argv[z-i]) > curMax) {
							curMax = atof(argv[z-i]);
						}
						// change the min volt if in range
						if (atof(argv[z-i]) > 0 && atof(argv[z-i]) < 150 && atof(argv[z-i]) < curMin) {
							curMin = atof(argv[z-i]);
						}
					
					
					}
					i += 1;
				}
				// print output for row if voltage was valid
				if (warning != true){
					cout << y << "	 " << volt << "	" << curMin << "	  " << curMax << endl;
				}
			}
			// set the new voltage for the next test
			z = z + 1;
			volt = atof(argv[z]);
		}
	}
	if (negative == true && y == 0) {
		cerr << "Error: Unable to compute statistics over data set because no valid voltage readings were given"<<endl;
		return -1;
	}
	if (negative != true){
		cerr << "Error: Missing terminator" <<endl;
		return -1;
	}
	// display error if no valid voltages were found 
	if (y == 0) {
		cerr << "Error: Unable to compute statistics over data set because no valid voltage readings were given"<<endl;
		return -1;
	}

	return rc;
}
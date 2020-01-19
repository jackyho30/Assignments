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
	float y = 0;
	float end = args+1;
	bool finish = false;
	bool negative = false;
	
	bool initial = false;
	float argsInitial = args;
	float num = 0;
	int k = 1; 
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
	cout << "Sample   Value  Minimum Average Maximum" << endl;
	// runs while there are still arguments to check
	while (args > 0) {
		//sets warning to false at beginning of loop
		bool warning = false;
		// checks off 1 argument from list and sets z to check next voltage
		args -= 1;
		z = z + 1;
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
			x += 1;
			y += 1;
			//check for invalid voltage and set warning to true if so
			if (volt>150) {
				cout << "Warning: Invalid voltage reading " <<volt<<" ignored in calculation" <<endl;
				warning = true;
				y -= 1;
				rc = 1;
			}
			// add to total voltage if valid
			if (volt > 0 && volt < 150){
				total = total + volt;
			}
			// change the max volt if in range
			if (volt > 0 && volt < 150 && volt > max) {
				max = volt;
			}
			// change the min volt if in range
			if (volt > 0 && volt < 150 && volt < min) {
				min = volt;
			}
			// print output for row if voltage was valid
			if (warning != true){
				cout << x << "	 " << volt << "	" << min << "	" << total/y << "	" <<max<< endl;
			}
			
		// set the new voltage for the next test
		volt = atof(argv[z]);
		}


	}
	

	if (negative == true && y == 0) {
		cout << "Error: Unable to compute statistics over data set because no valid voltage readings were given"<<endl;
		return -1;
	}

	
	if (negative != true){
		cerr << "Error: Missing terminator" <<endl;
	}
	// calculate the average volt

	
	// display error if no valid voltages were found 
	if (x == 0) {
		cerr << "Error: Unable to compute statistics over data set because no valid voltage readings were given"<<endl;
		return -1;
	}

	return rc;
}
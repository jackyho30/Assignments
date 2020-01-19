#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;
int main(const int argc, const char* const argv[]) {
	int rc = 0;
	// if no voltages are given
	if (argc < 3) {
		cerr << "Error: Unable to compute statistics over data set because not enough valid readings were given"<<endl;
		return -1;
	}

	
	int z = 2;
	float volt = atof(argv[z]);
	float a = atof(argv[1]);
	float b = 0 ; 
	float args = argc-2;
	float max = 0;
	float min = 150;
	float total = 0;
	float x = 0;
	float y = 0;
	float end = args+2;
	float prevAvg = 0;
	bool finish = false;
	bool negative = false;
	bool first = true;

	
	if (a < 0 || a >1){
		cerr << "Error: Alpha value " <<a<< " not within accepted range; exiting" <<endl;
		return -1;
	}
	
	//Column headings
	cout << "Sample   Value  EWMA" << endl;
	
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
		if (volt<=0) {
			negative = true;
			args = -1;
			finish = true;
		}
		// check if arguments are still availible for checking
		if (finish != true) {
			// add to the sample number
			x += 1;
			y += 1;
			//check for invalid voltage and set warning to true if so
			if (volt >= 150 || volt == 0) {
				cout << "Warning: Invalid voltage reading " <<volt<<" ignored in calculation" <<endl;
				warning = true;
				y -= 1;
				rc = 1;
			}
			// add to total voltage if valid
			if (volt > 0 && volt < 150){
				total = total + volt;
			}
			// print output for row if voltage was valid
			if (warning != true){
				if (first == true) {
					first = false;
					prevAvg = volt;
				}
				else 
					prevAvg = (a * volt) + ((1-a) *prevAvg);
					cout << x << "	 " << volt << "	" <<  prevAvg<< endl;
			}
			
		// set the new voltage for the next test and save the last volt
		
		volt = atof(argv[z]);
		}


	}
	

	if (negative == true && x == 0) {
		cout << "Error: Unable to compute statistics over data set because no valid voltage readings were given"<<endl;
		rc= -1;
		return rc;
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
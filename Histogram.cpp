#include <iostream>
#include <stdlib.h>

using namespace std;
int main(const int argc, const char* const argv[]) {
	int rc = 0;
	
	if (argc < 2) {
		cerr << "Error: Unable to compute histogram over data set because no valid voltage readings were given"<<endl;
		return -1;
	}
	
	int x = 0;
	int y = 1;
	float volt = atof(argv[y]);
	int buckets[10] = {0,0,0,0,0,0,0,0,0,0};
	bool initialize = false;
	float N = 0;
	


	while (initialize == false && y != argc){
		if (volt < 0){
			initialize = true;
			y = 0;
		}
		x += 1;
		y += 1;
		volt = atof(argv[y]);
		
	}
	
	if (initialize == false){
		cerr << "Error: Missing terminator; exiting" <<endl;
		return -1;
	}
	
	volt = atof(argv[y]);
	
	while (initialize == true && x >= 1){

		if (volt > 0 && volt < 106){
			buckets[0] += 1;
			N += 1;
		}
		else if (volt >= 106 && volt < 109){
			buckets[1] += 1;
			N += 1;
		}
		else if (volt >= 109 && volt < 112){
			buckets[2] += 1;
			N += 1;
		}	
		else if (volt >= 112 && volt < 115){
			buckets[3] += 1;
			N += 1;
		}	
		else if (volt >= 115 && volt < 118){
			buckets[4] += 1;
			N += 1;
		}	
		else if (volt >= 118 && volt < 121){
			buckets[5] += 1;
			N += 1;
		}	
		else if (volt >= 121 && volt < 124){
			buckets[6] += 1;
			N += 1;
		}	
		else if (volt >= 124 && volt <= 127){
			buckets[7] += 1;
			N += 1;
		}	
		else if (volt > 127 && volt < 150){
			buckets[8] += 1;
			N += 1;
		}
		else if (volt == 0 || volt >= 150){
			buckets[9] += 1;
			cout << "Warning: invalid voltage reading "<< volt << " ignored in calculation"<<endl;
			rc = 1;
		}
		x -= 1;
		y += 1;
		if (x != 0){
			volt = atof(argv[y]);
		}
	
	}
	cout << "Number of voltage readings: " << N <<endl;
	cout << "Voltage readings (0-106): " << buckets[0] <<endl;
	cout << "Voltage readings [106-109): " << buckets[1] <<endl;
	cout << "Voltage readings [109-112): " << buckets[2] <<endl;
	cout << "Voltage readings [112-115): " << buckets[3] <<endl;
	cout << "Voltage readings [115-118): " << buckets[4] <<endl;
	cout << "Voltage readings [118-121): " << buckets[5] <<endl;
	cout << "Voltage readings [121-124): " << buckets[6] <<endl;
	cout << "Voltage readings [124-127]: " << buckets[7] <<endl;
	cout << "Voltage readings (127-150): " << buckets[8] <<endl;
	cout << "Invalid readings: " << buckets[9] <<endl;
	

	return rc;
}
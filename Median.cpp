#include <iostream>
#include <stdlib.h>
using namespace std;
int main(const int argc, const char* const argv[]) {
	int rc = 0;
	// return error if no value are given
	if (argc < 2) {
		cerr << "Error: Unable to compute median over data set because no valid voltage readings were given"<<endl;
		return -1;
	}
	/* 
	z = number of arguments
	y = count for number in input
	x = number of valid readings
	a = used to check each reading in array
	num = for array of voltages
	med = median
	volt = current voltage reading
	*/
	
	int z = argc;
	int y = 1;
	int x = 0;
	int a = 1;
	float num[z];
	float med = 0;
	float volt = atof(argv[y]);
	bool array = true;
	bool sort = true;
	

	// making the array
	while (array == true) {
		if (volt < 150 && volt > 0) {
			x += 1;
			num[x] = atof(argv[y]);
		}
		if (volt > 150) {
			cout << "Warning: invalid voltage reading " << argv[y] << " ignored in calculations" << endl;
			rc = 1;
		}
		
		y += 1;
		volt = atof(argv[y]);
		
		if (volt < 0){
			array = false;
		}
	}
	if (x == 0) {
		cerr << "Error: Unable to compute statistics over data set because no valid voltage readings were given"<<endl;
		return -1;
	}	

	
	// sort numbers in the array starting from one based on whether it is greater than the next number in line
	while (sort == true){
		sort = false;
		while (num[a] > num[a+1]){
			//float b holds onto the first variable so that we can switch the numbers
			float b = num[a];
			num[a] = num[a+1];
			num[a+1] = b;
			a += 1;
			sort = true;
			}
	}
	//for even number in array
	//odd
	if (x% 2 == 1){
		med = num[(x+1)/2];
	}
	//even
	else{
		med = (num[x/2] + num[(x/2)+1])/2;
	}

	cout << "Number of voltage readings: " << x << endl;
	cout << "Median voltage: " << med << endl;
	
	return rc;
}
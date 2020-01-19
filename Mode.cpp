

int mode(const int dataset[], const int size, int modes[]){
	if (size < 0){
		return -1;
	}
	if (size == 0){
		return 0;
	}
	

	int NIILAN = 0;
	int uniqueN = 0;
	int old[size];
	int highest = 0;
	int numberModes = 0;
	bool swap = true;
	bool unique = true;


	for (int y = 0; y < size; y++){
		for (int z = 0; z < uniqueN ; z++){
			if (dataset[y] == old[z]){
				unique = false;
			}
		}
		if (unique == true){		
			for (int z = 0; z < size; z++){
				if (dataset[y] == dataset[z]){
					NIILAN += 1;
				}
			}
			if (NIILAN == highest){
				modes[numberModes]= dataset[y];
				numberModes += 1;
			}
			if (NIILAN > highest){
				highest = NIILAN;
				for (int x = 0; x < numberModes; x++){
					modes[x]=0;
				}
				numberModes = 0;
				modes[numberModes] = dataset[y];
				numberModes += 1;
			}
			
		
		}
		NIILAN = 0;
	}

	while (swap == true){
		swap = false;
		for (int y = 0; y < numberModes; y++){
			if (modes[y] > modes [y+1]){
				float temporary = modes[y+1];
				modes[y+1] = modes[y];
				modes[y] = temporary;
				swap = true;
			}
		}
	}


	return numberModes;
}


#ifndef MARMOSET_TESTING

/*
 * Marmoset doesn't see anything in here
 *
 * Use this space to test your code
 */

#include <cstdlib>  // atoi
#include <iostream> // cout, endl

using namespace std;

#define MIN_ARGS 2

int main(const int argc, const char* const argv[]){
	
	if (argc < MIN_ARGS){              // not enough inputs
		return -1;
	}
	int sz = argc - 1;                // 1 for name
	int input[sz];                    // to hold inputs

	for (int i = 0; i < sz; ++i){      // loop over all inputs, store in array
		input[i] = atoi(argv[i + 1]);   // atoi = string to integer
	}
	int modes[sz];                    // there will be at most as many modes
                                    // as there are numbers

	int ret = mode(input, sz, modes); // call the function

	cout << "Function returned: " << ret << " modes" << endl;
	cout << "Modes were: ";
	for (int i = 0; i < ret; ++i){     // loop over and print all modes
		cout << ' ' << modes[i];
		cout << endl;
	}
	return 0;
}

#endif

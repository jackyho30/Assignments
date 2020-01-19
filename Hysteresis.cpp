#include <iostream>
#include <stdlib.h>
using namespace std;

int countZerosAndOnes(const int zeroOneData[], const int numSamples, const int kMax, int& zeroCount, int& oneCount){
	enum State { START, DONE, GOT_ZERO, GOT_ONE, GOT_KTH_ZERO, GOT_KTH_ONE };
	if (numSamples <= 0){
		return -1;
	}
	if (kMax < 0){
		return -1;
	}
	int i = 0;
	int k = 0;
	oneCount = 1;
	zeroCount = 0;
	float input = zeroOneData[i];
	State s = START;
	while (s != DONE){
			
		//Process transitions
		
		switch(s){
			case START:
				if (input != 1 && input != 0){
					return -1; 
				}
				if (input == 1){
					s = GOT_ONE;
				}
				else{
					s = GOT_KTH_ZERO;
				}
				
				break;
				
			case GOT_ONE:
				++i;
				if (input != 1 && input != 0){
					return -1; 
				}
				if (input == 1){
					s = GOT_ONE;
				}
				else if (input == 0){
					s = GOT_KTH_ZERO;
					k = 0;
					//keep checking the same number in GOT_KTH_ZERO
					i -= 1;
				}
				if (i >= numSamples){
					i -= 1;
					s = DONE;
				}
				break;
				
			case GOT_ZERO:
				++i;
				if (input != 1 && input != 0){
					return -1; 
				}
				if (input == 0){
					s = GOT_ZERO;
				}
				else if (input == 1){
					s = GOT_KTH_ONE;
					k = 0;
					//keep checking the same number in GOT_KTH_ONE
					i -= 1;
				}
				if (i >= numSamples){
					i -= 1;
					s = DONE;
				}
				break;
			case GOT_KTH_ONE:
				++k;
				++i;
				if (input != 1 && input != 0){
					return -1; 
				}
				//this goes before the k>kmax check because if the sequence were [0,1,0],
				//if k>kmax check was above the 0 check, when 0 is being checked, k=2 and 
				//the value would be 0, if kmax was 1 then one count would increment when unintended
				if (input == 1){
					s = GOT_KTH_ONE;
				}
				
				else{
					s = GOT_ZERO;
					k = 0;
				}
				if (k >kMax){
					s = GOT_ONE;
					oneCount += 1;
					if (i >= numSamples){
						i -= 1;
					}
				}
				
				break;
			case GOT_KTH_ZERO:
				++i;
				++k;
				if (input != 1 && input != 0){
					return -1; 
				}
				if (input == 0){
					s = GOT_KTH_ZERO;
				}
				else{
					s = GOT_ONE;
					k = 0;
				}
				if (k >kMax){
					s = GOT_ZERO;
					zeroCount += 1;
					if (i >= numSamples){
						i -= 1;
					}
				}
				
				break;
			case DONE:
				return 0;
			default:
				return -1;
		}
		input = zeroOneData[i];
	}
	return 0;
}
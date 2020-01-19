#include <iostream>
#include <stdlib.h>
using namespace std;

int countZerosAndOnes(const int zeroOneData[], const int numSamples, int& zeroCount, int& oneCount){
	enum State { START, DONE, GOT_ZERO, GOT_ONE };
	if (numSamples <= 0)
		return -1;
	int i = 0;
	State s = START;
	while (s != DONE && i <= numSamples){
		if (i == numSamples){
			i-=1;
			s = DONE;
		}
			
		float input = zeroOneData[i];
		//Process transitions
		
		switch(s){
			case START:
				if (input != 1 && input != 0){
					return -1; 
				}
				if (input == 1){
					oneCount = 0;
					zeroCount = 0;
					s = GOT_ONE;
					++i;
					oneCount += 1;
				}
				else{
					oneCount = 0;
					zeroCount = 0;
					s = GOT_ZERO;
					++i;
					zeroCount += 1;
				}
				
				break;
				
			case GOT_ONE:
				if (input != 1 && input != 0){
					return -1; 
				}
				if (input == 1){
					s = GOT_ONE;
					++i;
				}
				else{
					s = GOT_ZERO;
					++i;
					zeroCount += 1;
				}
				break;
				
			case GOT_ZERO:
				if (input != 1 && input != 0){
					return -1; 
				}
				if (input == 1){
					s = GOT_ONE;
					++i;
					oneCount += 1;
				}
				else{
					s = GOT_ZERO;
					++i;
				}
				break;
			case DONE:
				return 0;
			default:
				return -1;
		}
	}
	return 0;
}

	
	
	
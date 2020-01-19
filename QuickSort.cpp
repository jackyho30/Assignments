int partition(int data[], const int lo, const int hi){
	if (lo < 0){
		return -1;
	}
	if (lo == hi){
		return -1;
	}
	
	int pivot = data[hi];
	int i = lo;
	int pivoti = lo;
	int temp = 0;
	while (i < hi){
		if (data[i] < pivot){
			temp = data[i];
			data[i] = data[pivoti];
			data[pivoti] = temp;
			pivoti++;
		}
		i++;
	}
	//swap the pivot with the last location of pivoti
	temp = data[i];
	data[i] = data[pivoti];
	data[pivoti] = temp;
	return pivoti;
}


void quickSortHelper(int data[], const int lo, const int hi){
	/*
	* Implement your sort here
	* Should call partition() to do the partition
	* Should call iteself to sort each partition
	*/

	int pivoti = 0;
	if ((hi-lo)>0){
		pivoti = partition(data, lo, hi);
		//for left half
		quickSortHelper(data, lo, pivoti-1);
		//for right half
		quickSortHelper(data, pivoti + 1, hi);
	}
}


int quickSort(int data[], const int numElements){
	/*
	* Implement your fuction here
	* Should call quickSortHelper() to do the sort
	*/
	if (numElements < 0){
		return -1;
	}
	int lo = 0;
	int hi = numElements -1;

	quickSortHelper(data, lo, hi);
	

	return 0;
}


#ifndef MARMOSET_TESTING

/*
 * Marmoset doesn't see anything in here
 *
 * Use this space to test your code
 */

#include <iostream> // cout, endl
#include <stdlib.h> // srandom(), random()

using namespace std;

// print an array in comma separated format
void printArray(const int data[], const int numElements){
	int i = 0;
	while (i < numElements-1) {
		cout << data[i] << ", ";
		++i;
	}
	cout << data[numElements-1] << endl;
}


int main(void){
	int sz = 10; // array size

	srandom(0);  // deterministic seed for random()
               // change 0 to a different number to get a different random array 

	int data[sz];
	int i = 0;
	while (i < sz) { // fill array with random values
		data[i] = (int)random();
		++i;
	}

	cout << "Array is: ";
	printArray(data, sz);

	int ret = quickSort(data, sz); // sort the array

	cout << "After sorting, array is: ";
	printArray(data, sz);

  // check the return code
	if (ret < 0){
		cout << "quickSort() indicated error" << endl;
	}
	else if (ret > 0){
		cout << "quickSort() indicated warning" << endl;
	}
	return 0;
}


#endif

int binarySearchHelper(const int data[], const int lo, const int hi, const int numberToFind){
	if (hi < 0 || hi < lo){
		return -1;
	}

	int middleElement = (lo + hi)/2;
	if (data[middleElement] == numberToFind){
		return middleElement;
	}
	else if (data[middleElement] < numberToFind){
		return binarySearchHelper(data, middleElement+1, hi, numberToFind);
	}
	else if (data[middleElement] > numberToFind){
		return binarySearchHelper(data, lo, middleElement-1, numberToFind);
	}
	else{
		return -1;
	}
}
int binarySearch(const int data[], const int numElements, const int numberToFind){
	if (numElements <= 1){
		return -1;
	}
	int lo = 0;
	int hi = numElements-1;
	return binarySearchHelper(data, lo, hi, numberToFind);
	
}

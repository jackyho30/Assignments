#include <iostream>
#include <math.h>

using namespace std;

float getNextNumber() {
  static int i = 0;
  const int dataSz = 6;
  float data[] = { 1, 2, 3, 2, 4, 5 };
  if (i < dataSz) {
    float retVal = data[i];
    ++i;
    return retVal;
  }
  else {
    return NAN;
  }
}

// State machine to determine if sequence of floats is sorted

int sorted() {
  enum State { START, UNKNOWN, ASCENDING, DESCENDING, DONE, UNSORTED };

  State s = START;
  float prev;
  
  while (s != DONE && s != UNSORTED) {
    float input = getNextNumber();

    // Process transitions
    switch(s) {
    case START:
      if (isnan(input))
	s = DONE;
      else 
	s = UNKNOWN;
      break;

    case UNKNOWN:
      if (isnan(input))
	s = DONE;
      else if (input > prev)
	s = ASCENDING;
      else if (input < prev) 
	s = DESCENDING;
      break;

    case ASCENDING:
      if (isnan(input))
	s = DONE;
      else if (input < prev) 
	  s = UNSORTED;
      break;

    case DESCENDING:
      if (isnan(input))
	s = DONE;
      else if (input > prev) 
	s = UNSORTED;
      break;

    case DONE:
    case UNSORTED:
    default:
      cerr << "An unknown error occurred." << endl;
      exit(-1);
      break;
    }

    // Process actions on entering the state
    switch (s) {
    case UNKNOWN:
    case ASCENDING:
    case DESCENDING:
      prev = input;
      break;

    case DONE:
      return 1;
      break;

    case UNSORTED:
      return 0;
      break;
      
    case START:
    default:
      cerr << "An unknown error occurred." << endl;
      exit(-1);
      break; 
    }
  }
  return 1;
}

int main() {
  if (sorted()) 
    cout << "The data is sorted" << endl;
  else
    cout << "The data is not sorted" << endl;
  return 0;
}

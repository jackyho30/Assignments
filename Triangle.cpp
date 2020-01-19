#include <iostream>
#include <stdlib.h>
#include <cmath>

int main(const int argc, const char* const argv[]) {
	
	using namespace std;
	int rc = 0;
	
	/*if (argc <7) {
		cerr <<argv[0]<< "usage error: expected 6 arguments; recieved " <<argc-1<<" exiting" <<endl;
		rc = -1;
	}
	if (argc >7) {
		cerr <<argv[0]<< "usage warning: expected 6 arguments; recieved " <<argv-1 <<" exiting"<<endl;
		rc = 1;
	}*/
	
	float x1 = atof(argv[1]);
	float y1 = atof(argv[2]);
	float x2 = atof(argv[3]);
	float y2 = atof(argv[4]);
	float x3 = atof(argv[5]);
	float y3 = atof(argv[6]);
	
	float s1 = sqrt(pow(x1-x2,2) + pow(y1-y2,2)) ;
	float s2 = sqrt(pow(x2-x3,2) + pow(y2-y3,2)) ;
	float s3 = sqrt(pow(x1-x3,2) + pow(y1-y3,2)) ;
	float s = 0.5*(s1+s2+s3);
	float a = sqrt(s*(s-s1)*(s-s2)*(s-s3));
    
	cout << "The area of the triangle formed by points ("<<x1<<","<<y1<<"), ("<<x2<<","<<y2<<"), and ("<<x3<<","<<y3<<") is: "<<a<< endl;
    
	return rc;
}
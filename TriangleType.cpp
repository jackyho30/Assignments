#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

int main(const int argc, const char* const argv[]) {
	int rc = 0;
	
	/*if (argc <7) {
		cerr << "Error: Expected 6 arguments; received " <<argc-1<<"; exiting" <<endl;
		rc = -1;
		return rc;
	}
	if (argc >7) {
		cerr << "Warning: Expected 6 arguments; received " <<argc-1<<"; ignoring extraneous arguments"<<endl;
	}*/
	
	float x1 = atof(argv[1]);
	float y1 = atof(argv[2]);
	float x2 = atof(argv[3]);
	float y2 = atof(argv[4]);
	float x3 = atof(argv[5]);
	float y3 = atof(argv[6]);
	
	float a = sqrt(pow(x1-x2,2) + pow(y1-y2,2)) ;
	float b = sqrt(pow(x2-x3,2) + pow(y2-y3,2)) ;
	float c = sqrt(pow(x1-x3,2) + pow(y1-y3,2)) ;
	float s = 0.5*(a+b+c);
	
	//cosine law cosC= (a^2+b^2-c^2)/2ab
	float ang1 = acos((pow(a,2)+ pow(b,2)- pow(c,2))/(2*a*b))*180/M_PI;
	float ang2 = acos((pow(b,2)+ pow(c,2)- pow(a,2))/(2*b*c))*180/M_PI;
	float ang3 = acos((pow(c,2)+ pow(a,2)- pow(b,2))/(2*c*a))*180/M_PI;
	
	bool rightAng = false;
	bool obtuse = false;
	bool acute = false;
	bool equilateral = false;
	bool isosceles = false;
	bool scalene = false;
	
	float area = sqrt(s*(s-a)*(s-b)*(s-c));
    
	cout << "The area of the triangle formed by points ("<<x1<<","<<y1<<"), ("<<x2<<","<<y2<<"), and ("<<x3<<","<<y3<<") is: "<<area<< endl;
	
	if ((fabs(ang1 - 90.0) < ang1 * 0.1) || (fabs(ang2 - 90.0) < ang2 * 0.1) || (fabs(ang3 - 90.0) < ang3 * 0.1) ){
		rightAng = true;
	}
	else if (ang1 > 90.0 || ang2 > 90.0 || ang3 > 90.0){
		obtuse = true;
	}
	else if (ang1 < 90.0 && ang2 < 90.0 && ang3 < 90.0){
		acute = true;
	}
	
	if ((fabs(a-b) < a*0.1) && (fabs(b-c) < b*0.1)) {
		equilateral = true;
	}
	else if ((fabs(a-b) < a*0.1) || (fabs(b-c) < b*0.1) || (fabs(c-a) < c*0.1)) {
		isosceles = true;
	}
	else if ((fabs(a-b) > a*0.1) && (fabs(b-c) > b*0.1) && (fabs(c-a) > c*0.1)) {
		scalene = true;
	}
		
	if (equilateral == true){
		if (rightAng == true) {
			cout << "The triangle formed by points (" <<x1<< ", " <<y1<< "), (" <<x2<< ", " <<y2<< "), and (" <<x3<< ", " <<y3<< ") is: equilateral right angle" <<endl;
			return rc;
		}
		else if (obtuse == true) {
			cout << "The triangle formed by points (" <<x1<< ", " <<y1<< "), (" <<x2<< ", " <<y2<< "), and (" <<x3<< ", " <<y3<< ") is: equilateral obtuse" <<endl;
			return rc;
		}
		else if (acute == true) {
			cout << "The triangle formed by points (" <<x1<< ", " <<y1<< "), (" <<x2<< ", " <<y2<< "), and (" <<x3<< ", " <<y3<< ") is: equilateral acute" <<endl;
			return rc;
		}
	}
	if (isosceles == true) {
		if (rightAng == true) {
			cout << "The triangle formed by points (" <<x1<< ", " <<y1<< "), (" <<x2<< ", " <<y2<< "), and (" <<x3<< ", " <<y3<< ") is: isosceles right angle" <<endl;
			return rc;
		}
		else if (obtuse == true) {
			cout << "The triangle formed by points (" <<x1<< ", " <<y1<< "), (" <<x2<< ", " <<y2<< "), and (" <<x3<< ", " <<y3<< ") is: isosceles obtuse" <<endl;
			return rc;
		}
		else if (acute == true) {
			cout << "The triangle formed by points (" <<x1<< ", " <<y1<< "), (" <<x2<< ", " <<y2<< "), and (" <<x3<< ", " <<y3<< ") is: isosceles acute" <<endl;
			return rc;
		}
	}
	if (scalene == true) {
		if (rightAng == true){
			cout << "The triangle formed by points (" <<x1<< ", " <<y1<< "), (" <<x2<< ", " <<y2<< "), and (" <<x3<< ", " <<y3<< ") is: scalene right angle" <<endl;
			return rc;
		}
		else if (obtuse == true) {
			cout << "The triangle formed by points (" <<x1<< ", " <<y1<< "), (" <<x2<< ", " <<y2<< "), and (" <<x3<< ", " <<y3<< ") is: scalene obtuse" <<endl;
			return rc;
		}
		else if (acute == true) {
			cout << "The triangle formed by points (" <<x1<< ", " <<y1<< "), (" <<x2<< ", " <<y2<< "), and (" <<x3<< ", " <<y3<< ") is: isosceles acute" <<endl;
			return rc;
		}

	}
	return 0;
}
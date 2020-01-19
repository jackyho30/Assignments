#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

// The polynomial struct keeps the most significant coeff
// in the first coeff[] element, the second in the second
// and so on.

struct Polynomial {
	int    degree;
	float* coeff;
};

float evaluate(const Polynomial p, const float x) {
	float product = 0;
	
	if (p.degree < 0) {
		cerr << "Parameter p is not a polynomial; p.degree = " << p.degree << endl;
		return -1;
	}
	//<= for constant value
	for (int i = 0; i <= p.degree; i++) {
		product += p.coeff[i] * pow(x, p.degree - i);
	}
	return product;
}

Polynomial add(const Polynomial p1, const Polynomial p2) {
	//take the difference of the degrees to see which polynomial is higher degree
	//start adding at the degree of the smaller polynomial
	//for example if p1 is deg 5 and p2 is deg 3 we want to start adding coefficients at deg 3
	//to do this we will access the larger array at index + difference which is 2 in this case
	//but what about for the coefficients before this in the larger array?
	int difference = 0;
	int larger = 0;
	int newDeg = 0;
	
	int error1 = 0;
	int error2 = 0;
	
	
	if (p1.degree < 0){
		error1 = 1;
	}
	if (p2.degree < 0){
		error2 = 1;
	}
	else if (p1.degree > p2.degree){
		difference = p1.degree - p2.degree;
		larger = p1.degree;
		newDeg = 1;
	}
	else if (p2.degree > p1.degree){
		difference = p2.degree - p1.degree;
		larger = p2.degree;
		newDeg = 2;
	}
	else {
		larger = p1.degree;
		newDeg = 1;
	}
	float* addition = new float[larger];
	
	for (int i = 0; i <= larger; i++) {
		if (newDeg == 1){
			if (i < difference){
				addition[i] = p1.coeff[i];
			}
			else {
				addition[i] = p1.coeff[i] + p2.coeff[i-difference];
			}
		}
		else if (newDeg == 2){
			if (i < difference){
				addition[i] = p2.coeff[i];
			}
			else {
				addition[i] = p2.coeff[i] + p1.coeff[i-difference];
			}
		}
	}
	
	Polynomial added;
	
	added.coeff = addition;
	
	if (newDeg == 1){
		added.degree = p1.degree;
	}
	else if (newDeg == 2){
		added.degree = p2.degree;
	}
	if (error1 == 1 || error2 == 1){
		added.degree = -1;
	}
	return added;
	
}

Polynomial derivative(const Polynomial pIn) {
	//array will be 1 less because degree of polynomial is 1 less in derivative
	float* coefficients = new float[pIn.degree-1];
	
	//same format as down in the main function
	Polynomial deriv;
	
	//set errors for when the return is entered into displayPolynomial
	if (pIn.degree < 0){
		deriv.degree = -1;
		return deriv;
	}
	
	if (pIn.degree == 0 ){
		deriv.degree = pIn.degree;
		return deriv;
	}
		
	
	for (int i = 0; i < pIn.degree; i++) {
		coefficients[i] = pIn.coeff[i] * (pIn.degree - i);
	}
	

	
	deriv.degree = pIn.degree - 1;
	deriv.coeff = coefficients;
	
	return deriv;
		
}

int displayPolynomial(const Polynomial p) {
	if (p.degree < 0) {
		cerr << "Parameter p is not a polynomial; p.degree = " << p.degree << endl;
		return -1;
	}
	cout << "\"";
	for (int i = 0; i < p.degree; ++i) {
		if (p.coeff[i] == 1){ 
			cout << "x";
		}
		else{
			cout << p.coeff[i] << "x";
		}
		if ((p.degree - i) > 1) {
			cout <<  "^" <<  (p.degree - i);
		}
		cout << " + ";
	}
	cout << p.coeff[p.degree] << "\"";
	return 0;
}

#ifndef MARMOSET_TESTING

int main() {
	float coeff[] = {1, 2, 3};   // x^2 + 2x + 3
	int degree = 2;
	Polynomial p0;
	Polynomial p1;
	Polynomial p2;
  
	p0.degree = 0;
	p0.coeff = coeff;
	p1.degree = 1;
	p1.coeff = coeff;
	p2.degree = 2;
	p2.coeff = coeff;

	cout << "When x = 2.2, ";
	displayPolynomial(p0);
	cout << " evalates to: " << evaluate(p0,2.2) << endl << endl;

	cout << "When x = 2.2, ";
	displayPolynomial(p1);
	cout << " evalates to: " << evaluate(p1,2.2) << endl << endl;

	cout << "When x = 2.2, ";
	displayPolynomial(p2);
	cout << " evalates to: " << evaluate(p2,2.2) << endl << endl;


	Polynomial p = add(p1,p2);
	cout << "p1 + p2 =  ";
	displayPolynomial(p);
	cout << endl;
 
	Polynomial pDer = derivative(p);
	cout << "dp/dx =  ";
	displayPolynomial(pDer);
	cout << endl;
 
	return 0;
}

#endif

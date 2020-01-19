#include <iostream>
#include <math.h>
#include "ClassyPoly.h"
using namespace std;

///////////////////////////////////////////////////////////////////////////
//
// Public operators and methods


//derivative
Polynomial Polynomial::dx() const {
	if (_degree < 0){
		Polynomial basic(-1,NULL);
	}
	return derivative();
}
//evaluate
float Polynomial::operator()(const float x) const {
	if (_degree < 0){
		Polynomial basic(-1,NULL);
	}
	return evaluate(x);
}
//add
Polynomial Polynomial::operator+(const Polynomial& p) const {
	if (_degree < 0 || p._degree < 0){
		Polynomial basic(-1,NULL);
	}
	return add(p);
}

//multiply
Polynomial Polynomial::operator*(const Polynomial& p) const {
	if (_degree < 0 || p._degree < 0){
		Polynomial multiply(-1,NULL);
		return multiply;
	}
	
	//array will be 1 more because there is a degree 0 in the array
	float* coefficients = new float[p._degree+1]();
	
	int multDeg = _degree + p._degree;
	
	for  (int i = 0; i <= p._degree; i++) {
		for (int x = 0; x <= _degree; x++) {
			int position = i+x;
			coefficients[position] += p._coeff[i] * _coeff[x];
		}
	}
	
	Polynomial multiply(multDeg,coefficients);
	
	return multiply;
		
	
}
//equal
void Polynomial::operator=(const Polynomial& p) {
	//same as constructor and destructor
	float* coefficients = new float[p._degree+1];
	
	if (p._degree < 0) {
		_degree = -1;
		_coeff = NULL;
	}
	else{
		_degree = p._degree;
		delete[] _coeff;
		for (int i = 0; i <= p._degree; i++){
			coefficients[i] = p._coeff[i];
		}
		_coeff = coefficients;
	}
}
//equal equal
bool Polynomial::operator==(const Polynomial& p) const {
	if (_degree != p._degree || _degree < 0 || p._degree < 0){
		return false;
	}
	else {
		for (int i = 0; i <= _degree; i++){
			//check if the two polynomials difference is within 10^-5
			if (fabs(_coeff[i] - p._coeff[i]) <= 0.0001){
				return true;
			}	
		}
	}
	return false;
}

///////////////////////////////////////////////////////////////////////////
//
// Constructors and Destructor
//
// Note: no default constructor
//

Polynomial::Polynomial(const Polynomial& p) {
	if (p._degree < 0) {
		_degree = -1;
		_coeff = NULL;
		
	}
	//array will be 1 more because there is a degree 0 in the array
	else{
		float* coefficients = new float[p._degree+1];
		//else statement here because this for loop would run even if the degree was invalid
		_degree = p._degree;
		for (int i = 0; i <= p._degree; i++) {
			coefficients[i] = p._coeff[i];
		}
		_coeff = coefficients;
	}
	
}

Polynomial::Polynomial(const int degree, const float coeff[]) {
	if (degree < 0) {
		_degree = -1;
		_coeff = NULL;
		
	}
	//array will be 1 more because there is a degree 0 in the array
	else{
		float* coefficients = new float[_degree+1];
		//else statement here because this for loop would run even if the degree was invalid
		_degree = degree;
		for (int i = 0; i <= degree; i++) {
			coefficients[i] = coeff[i];
		}
		_coeff = coefficients;
	}
	
}

Polynomial::~Polynomial() {
	delete[] _coeff;
}

///////////////////////////////////////////////////////////////////////////
//
// Private Methods
//

float Polynomial::evaluate(const float x) const {
	float product = 0;
	
	if (_degree < 0) {
		return -1;
	}
	//<= for constant value
	for (int i = 0; i <= _degree; i++) {
		product += _coeff[i] * pow(x, _degree - i);
	}
	return product;
}

Polynomial Polynomial::add(const Polynomial& pIn) const {
	//take the difference of the degrees to see which polynomial is higher degree
	//start adding at the degree of the smaller polynomial
	//for example if p1 is deg 5 and p2 is deg 3 we want to start adding coefficients at deg 3
	//to do this we will access the larger array at index + difference which is 2 in this case
	//but what about for the coefficients before this in the larger array?
	int difference = 0;
	int larger = 0;
	int newDeg = 0;
	
	
	if (_degree < 0){
		Polynomial added(-1,NULL);
		return added;
	}
	if (pIn._degree < 0){
		Polynomial added(-1,NULL);
		return added;
	}
	else if (_degree > pIn._degree){
		difference = _degree - pIn._degree;
		larger = _degree;
		newDeg = 1;
	}
	else if (pIn._degree > _degree){
		difference = pIn._degree - _degree;
		larger = pIn._degree;
		newDeg = 2;
	}
	else {
		larger = _degree;
		newDeg = 1;
	}
	float* addition = new float[larger];
	
	for (int i = 0; i <= larger; i++) {
		if (newDeg == 1){
			if (i < difference){
				addition[i] = _coeff[i];
			}
			else {
				addition[i] = _coeff[i] + pIn._coeff[i-difference];
			}
		}
		else if (newDeg == 2){
			if (i < difference){
				addition[i] = pIn._coeff[i];
			}
			else {
				addition[i] = pIn._coeff[i] + _coeff[i-difference];
			}
		}
	}
	int addedDegree = 0;
	if (newDeg == 1){
		addedDegree = _degree;
	}
	else if (newDeg == 2){
		addedDegree = pIn._degree;
	}
	Polynomial added(addedDegree,addition);
	return added;
}

Polynomial Polynomial::derivative() const {
	//array will be 1 less because degree of polynomial is 1 less in derivative
	float* coefficients = new float[_degree-1];
	
	//set errors for when the return is entered into displayPolynomial
	if (_degree < 0){
		Polynomial deriv(-1, NULL);
		return deriv;
	}
	
	if (_degree == 0 ){
		Polynomial deriv(0,NULL);
		return deriv;
	}
		
	for (int i = 0; i < _degree; i++) {
		coefficients[i] = _coeff[i] * (_degree - i);
	}
	
	Polynomial deriv(_degree-1,coefficients);
	
	return deriv;
}


///////////////////////////////////////////////////////////////////////////
//
// Test driver
// Some very limited testing; should test ==
// 

#ifndef MARMOSET_TESTING

int main() {
	float coeff[] = {1, 2, 3, 4};   // x^2 + 2x + 3
	Polynomial p0(1,coeff);
	Polynomial p1(2,coeff);
	Polynomial p2(3,coeff);
  
	cout << "When x = 2.2, \"" << p0 << "\" evalates to: " << p0(2.2) << endl << endl;
	cout << "When x = 2.2, \"" << p1 << "\" evalates to: " << p1(2.2) << endl << endl;
	cout << "When x = 2.2, \"" << p2 << "\" evalates to: " << p2(2.2) << endl << endl;

	Polynomial p = p1 + p2;
	Polynomial q = p1 * p2;											
	cout << "p1 + p2 =  " << p << endl << endl;
	cout << "p1 * p2 =  " << q << endl << endl;
 
	cout << "dp/dx =  " << p.dx() << endl;
	cout << "dq/dx =  " << q.dx() << endl;
 
	return 0;
}

#endif
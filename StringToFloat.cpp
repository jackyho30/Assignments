#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <float.h>

using namespace std;

float stringToFloat(const char input[]){
	enum State {START, DONE, NUMBER, DECIMAL, DECIMAL_NUMBER, EXPONENT, EXPONENT_NUMBER, SIGN_NUMBER, SIGN_EXPONENT};
	
	if (input[0] == '\0'){
		return NAN;
	}
	int i = 0;
	char character = input[i];
	int number = input[i] - '0';
	
	int num = 0;
	int decimal = 0;
	int exponent = 0;
	int sign = 0;
	
	
	float product = 0;
	int negative = 0;
	int exponentNegative = 0;
	int decimalCount = 0;
	float exponentFinal = 0;
	float decimalFinal = 0;
	int signNumberCount = 0;
	int signExponentCount = 0;
	
	State s = START;
	while (s != DONE){
		
		if (number >= 0 && number <= 9){
			num = 1;
		}
		else if (character == 'e' || character == 'E' || character == '.' || character == '-' || character == '+' || character == '\0'){
			if (character == 'e' || character == 'E'){
				exponent = 1;
			}
			else if (character == '.'){
				decimal = 1;
			}
			else if (character == '\0'){
				s = DONE;
			}
			else{
				sign = 1;
			}
			
		}
		else{
			return NAN;
		}
		//Process transitions
		switch(s){
			case START:
				if (sign == 1){
					s = SIGN_NUMBER;
					sign = 0;
				}
				else if (decimal == 1){
					s = DECIMAL;
				}
				else if (num == 1){
					s = NUMBER;
				}
				else {
					s = EXPONENT;
				}
				break;
				
			case SIGN_NUMBER:
				++i;
				if (character == '-' && signNumberCount == 0){
					negative = 1;
					signNumberCount = 1;
				}
				else if (character == '+' && signNumberCount == 0){
					s = SIGN_NUMBER;
					signNumberCount = 1;
				}
				else if (num == 1){
					s = NUMBER;
					i -= 1;
				}
				else if (decimal == 1){
					s = DECIMAL;
					i -= 1;
				}
				else {
					return NAN;
				
				}
				break;
				
			// will only ever come in here if exponent or decimal has not occured yet
			case NUMBER:
				i++;
				
				if (num == 1){
					product = (product*10) + number;
					s = NUMBER;
					num = 0;
				}
				else if (decimal == 1){
					s = DECIMAL;
				}
				else if (exponent == 1){
					s = EXPONENT;
				}
				else {
					return NAN;
				}
					
				break;
				
			case DECIMAL:
				i++;
				if (num == 1){
					s = DECIMAL_NUMBER;
					i--;
				}
				else if (exponent == 1){
					s = EXPONENT;
				}
				else {
					return NAN;
				}
				break;
				
			case DECIMAL_NUMBER:
				i++;
				decimalCount+=1;
				
				if (num == 1){
					decimalFinal = (decimalFinal * 10) + number;
					s = DECIMAL_NUMBER;
					num = 0;
				}
				else if (exponent == 1){
					s = EXPONENT;
				}
				else {
					return NAN;
				}
				break;
				
			case EXPONENT:
				if (sign == 1 && signExponentCount == 0){
					s = SIGN_EXPONENT;
					signExponentCount = 1;
				}
				else if (num == 1 && signExponentCount == 0){
					s = EXPONENT_NUMBER;
					signExponentCount = 1;
				}
				else {
					return NAN;
				}
				break;
			
			case SIGN_EXPONENT:
				++i;
				if (character == '-'){
					exponentNegative = 1;
				}
				else if (character == '+'){
					s = SIGN_EXPONENT;
				}
				else if (num == 1){
					s = EXPONENT_NUMBER;
					i--;
				}
				else {
					return NAN;
				}
				break;
				
			case EXPONENT_NUMBER:
				i++;
				/*if (input[i] == '\0'){
					i--;
				*/
				if (num == 1){
					exponentFinal = (exponentFinal * 10) + number;
					s = EXPONENT_NUMBER;
					num = 0;
				}
				else {
					return NAN;
				}
				break;
				
			case DONE:
				product = product + (decimalFinal * pow(10,decimalCount*-1));
				if (negative == 1){
					product = product * -1;
				}
				if (exponentNegative == 1){
					exponentFinal = exponentFinal * -1;
				}
				
				product = product * pow(10,exponentFinal);
				break;
				
			default:
				break;
				
		}
		character = input[i];
		number = input[i] - '0';
	}
	return product;
}
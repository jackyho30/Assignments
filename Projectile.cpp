#include <math.h>

float projectileDestination(const float initialHeight,const float initialVelocity,const float mass,const float initialAngle){
	float angleRadians = initialAngle * M_PI/180;
	float componentY = initialVelocity * sin(angleRadians);
	float componentX = initialVelocity * cos(angleRadians);
	float discriminant = sqrt(((initialVelocity * sin(angleRadians)) * (initialVelocity * sin(angleRadians))) + (4 * 4.9 * initialHeight));
	float timeMinus= ((-1 * componentY) - discriminant)/-9.8;
	float timePlus = ((-1 * componentY) + discriminant)/-9.8;
	
	float d = 0;
	
	if (initialHeight<0){
		return NAN;
	}
	if (initialVelocity <= 0){
		return NAN;
	}
	if (mass <= 0){
		return NAN;
	}
	if (initialAngle < -90 || initialAngle >90){
		return NAN;
	}
	
	if (timeMinus > 0){
		d = componentX * timeMinus;
	}
	else if (timePlus > 0){
		d = componentX * timePlus;
	}
	return d;

}

#ifndef MARMOSET_TESTING

/*
 * Marmoset doesn't see anything in here
 *
 * Use this space to test your code
 */

#include <iostream> // cout, endl

using namespace std;

int main(void){
	// parameters
	float height   = 10;
	float velocity = 10;
	float mass     = 1;
	float angle    = 30;

  // call the function and print the result
	float dest = projectileDestination(height, velocity, mass, angle);
	cout << "The desination of a projectile with: " << endl;
	cout << "Height: "   << height   << endl;
	cout << "Velocity: " << velocity << endl;
	cout << "Mass: "     << mass     << endl;
	cout << "Angle: "    << angle    << endl;
	cout << "is: "       << dest     << endl;

	return 0;
}

#endif
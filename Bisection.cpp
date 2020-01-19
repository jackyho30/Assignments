#include <math.h> // NAN

extern float f(float t); // you are finding the root of this
                         // (provided by marmoset)

static float bisectionHelper(const float left, const float right,
                             const float minIntervalSize
                             /* add what you want here */)
{
  /*
   * Your code here
   *
   * This function should call itself
   */

  return NAN;
}

float bisection(const float left, const float right,
                const float minIntervalSize)
{
  /*
   * Your code here
   *
   * This function should call bisectionHelper()
   */

  return NAN;
}

#ifndef MARMOSET_TESTING

/*
 * Marmoset doesn't see anything in here
 *
 * Use this space to test your code
 */

#include <cstdlib>  // atof
#include <iostream> // cout, endl

using namespace std;


float f(float t)
{
  // sample function f()
  // will have roots at t = 2 and 5
  // try bisecting between 4 and 6 to find t = 5 root
  // or between 1 and 3 to find t = 2 root
  return (t - 2) * (t - 5);
}

#define EXPECTED_ARGS 3

int main(const int argc, const char* const argv[])
{ 
  if (argc != EXPECTED_ARGS)    // incorrect number of arguments
    return -1;
 
 
  float lbound = atof(argv[1]); // atof = string to float
  float rbound = atof(argv[2]);
 
  float int_sz = 0.01;          // minimum interval

  // call bisection
  float root   = bisection(lbound, rbound, int_sz);
 
  cout << "f(t) has a root between t = " << lbound
       << " and t = " << rbound
       << " at t = " << root << endl; 

  return 0;
}

#endif
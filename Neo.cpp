////////////////////////////////////////////////////////////////////////////////
//
// Neo.cpp
// Test Driver for SafeMatrix class
// Inputs:  none
// Outputs: Results of testing SafeMatrix Class, displayed to cout
// Operation: test all methods of SafeMatrix class
//
// Change History
// 26 November 2018; PASW; Initial version: only implements
//                                          (1) basic test setup
//                                          (2) testing of ...
//                                          (3) display of results
//

#include <iostream>
#include "SafeMatrix.h"
#include "TestCase.h"

using namespace std;


////////////////////////////////////////////////////////////////////////////////
//
// Testcases for appendRow()
// Uses class TestCase
//


class TestAppendRow : public TestCase {
public:
  bool testBasicAppend();
  bool testMismatchAppend();
  bool testNaMAppend();

  bool run();
  int  setup() { return 0; } ;

#define NUM_COLS 3
  TestAppendRow() : data1(0,NUM_COLS), data2(-1,0) {};
private:
  SafeMatrix data1;
  SafeMatrix data2;             // Should be NaM
};

bool TestAppendRow::run() {
  setup();
  if (!testBasicAppend() ||
      !testMismatchAppend() ||
      !testNaMAppend()) 
    return false;
  return true;
}

bool TestAppendRow::testBasicAppend() {
  float data[] = { 1.1, 2.2, 3.3 };
  bool retVal = false;
  const char desc[] = "Append Row: Basic Append";
  if (!data1.appendRow(NUM_COLS, data) ||
      (data1(0,0) != data[0]) ||
      (data1(0,1) != data[1]) ||
      (data1(0,2) != data[2]))
    retVal = false;
  else
    retVal = true;
  _perTestCaseResults[_testcaseNumber] = retVal;
  output(desc);
  cleanup();
  return retVal;
}

bool TestAppendRow::testMismatchAppend() {
  float data[] = { 1.1, 2.2, 3.3 };
  bool retVal = true;
  const char desc[] = "Append Row: Mismatch Append";
  if (data1.appendRow(NUM_COLS-1, data))
    retVal = false;
  if (((data1.dimensions()).rows != 1) || 
      ((data1.dimensions()).cols != NUM_COLS)) 
    retVal = false;
  _perTestCaseResults[_testcaseNumber] = retVal;
  output(desc);
  cleanup();
  return retVal;
}

bool TestAppendRow::testNaMAppend() {
  float data[] = { 1.1, 2.2, 3.3 };
  bool retVal = true;
  const char desc[] = "Append Row: NaM Append";
  if (data2.appendRow(0, data))
    retVal = false;
  if (!data2.isNaM())
    retVal = false;
  _perTestCaseResults[_testcaseNumber] = retVal;
  output(desc);
  cleanup();
  return retVal;
}

////////////////////////////////////////////////////////////////////////////////
//
// Testcases for operator()
// Uses class TestCase
//


class TestParens : public TestCase {
public:
  int testRHSValid();
  int testLHSValid();
  int testRHSInvalid();
  int testLHSInvalid();

  bool run() { return false; } ;
  int  setup() { return false; } ;
  void cleanup() { };

};

////////////////////////////////////////////////////////////////////////////////
//
//

int main() {

  TestCase t0;
  t0.run();

  TestAppendRow t1;
  t1.run();

  TestParens t2;
  t2.run();

  t0.terminate();
  
  return 0;
}

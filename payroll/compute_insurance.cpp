// Author: Kyle Culp
// File: compute_insurance.cpp

#include <string>
#include <iostream>
using namespace std;

double compute_insurance(char inscode) {
	if(inscode == 'N') {
		return 0;
	}
	if(inscode == 'S') {
		return 9.50;
	}
	if(inscode == 'F') {
		return 24.75;
	}
  return 0;
}

#if __INCLUDE_LEVEL__ < 1
int main() {
  cout << compute_insurance('N') << endl;
  cout << compute_insurance('S') << endl;
  cout << compute_insurance('F') << endl;
}
#endif

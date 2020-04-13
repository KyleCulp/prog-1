// Author: Kyle Culp
// File: compute_gross_pay.cpp

#include <string>
#include <iostream>
using namespace std;

double compute_gross_pay(double rate, double hours) {
	if(hours > 40) {
		double overtimeHours = hours - 40;
		// Base rate for 40 hours, overtime for past that
		return (40 * rate) + (overtimeHours * (2 * rate));
	}

	return rate * hours;
}

#if __INCLUDE_LEVEL__ < 1
int main() {
  cout << compute_gross_pay(10.00, 35.2) << endl;
  cout << compute_gross_pay(10.00, 40.00) << endl;
  cout << compute_gross_pay(10.00, 48.7) << endl;
}
#endif

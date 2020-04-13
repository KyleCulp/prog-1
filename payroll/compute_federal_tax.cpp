// Author: Kyle Culp
// File: compute_federal_tax.cpp

#include <string>
#include <iostream>
using namespace std;

double compute_federal_tax(double PYE) {
	if(PYE < 8000) {
		return 0;
	}
	if(8000 <= PYE && PYE < 20000) {
		return ((PYE - 8000) * 0.15) / 52;
	}
	if(PYE >= 20000) {
		double middlePay = ((20000 - 8000) * 0.15);
		return (middlePay + ((PYE - 20000) * 0.28)) / 52;
	}
} 

#if __INCLUDE_LEVEL__ < 1
int main() {
  cout << compute_federal_tax(7650) << endl;
  cout << compute_federal_tax(8000) << endl;
  cout << compute_federal_tax(17000) << endl;
  cout << compute_federal_tax(20000) << endl;
  cout << compute_federal_tax(21000) << endl;
}
#endif

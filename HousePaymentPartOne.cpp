// Kyle Culp
// Programming 1
// Due: 2/13/2020
// House Payment Part 1
// Get the monthly payment cost for a loan by providing
// the principal, yearly interest rate, and the loan length

#include <iostream>
#include <iomanip> 
#include <math.h> 
using namespace std; 

/* 
* mp: (p * mir) / 1 - (1 / 1 + mir) ^ (12 * y)
* tophalf: (p * mir)
* bottomhalf: 1 - (1 / 1 + mir) ^ (12 * y)
* mp: monthly payment
* p: principal
* mir: interest rate for 1 month
* y: year
* yir: interest rate for 1 year
*/ 

double calculateMonthlyPayment(double principal, double yir, double years) {
  // Monthly interest rate
  double mir = yir / 1200;

  double bottomHalf = mir + 1;
  bottomHalf = 1 / bottomHalf;
  bottomHalf = pow(bottomHalf, 12 * years);
  bottomHalf = 1 - bottomHalf;

  double topHalf = principal * mir;

  return topHalf / bottomHalf;
}

int main() {
  double principal, yir, years;
  cout << setprecision(2) << fixed;

  cout << "Enter the principal: ";
  cin >> principal;
  cout << "Enter the yearly interest rate (in decimal format): ";
  cin >> yir;
  cout << "Enter the loan length (in years): ";
  cin >> years;

  double monthlyPayment = calculateMonthlyPayment(principal, yir, years);

  cout << "Monthly Payment: $" << monthlyPayment << endl;

  return 0;
}

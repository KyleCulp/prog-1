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

// quick function to handle yir -> mir, then multiply against remaining balance
double getMonthlyInterest(double remainingBalance, double yir) {
  return remainingBalance * (yir / 1200);
}

// Print first eight months of the payment plan to table
void printFirstEight(double principal, double yir, double years) {
  double monthlyPayment = calculateMonthlyPayment(principal, yir, years);
  double totalPaid, monthlyInterest, principalPaid, totalPrincipalPaid, remainingBalance = principal;

  // All numbers get cut off after 2 decimals, rounded up
  cout << setprecision(2) << fixed;

  for(int i=1; i<=8; i++) {
    totalPaid += monthlyPayment;
    monthlyInterest = getMonthlyInterest(remainingBalance, yir);
    principalPaid = monthlyPayment - monthlyInterest;
    totalPrincipalPaid += principalPaid;
    remainingBalance -= principalPaid;


    
    cout << setw(1) << "|";
    cout << setw(5) << i;
    cout<< setw(12) << monthlyPayment;
    cout << setw(12) << totalPaid; 
    cout << setw(12) << monthlyInterest; 
    cout << setw(12) << principalPaid;
    cout << setw(12) << totalPrincipalPaid;
    cout << setw(12) << remainingBalance;
    cout << setw(1) << " |\n";
  }
}

void printTable(double principal, double yir, double years) {
  string dashBar = " ------------------------------------------------------------------------- ";
  double monthlyPayment = calculateMonthlyPayment(principal, yir, years);

  cout << setprecision(2) << fixed;


  // Top table info
  cout << dashBar << endl;
  cout << setw(1) << "|";
  cout << setw(12) << "Principal " << principal;
  cout << setw(16) << "Interest Rate " << yir;
  cout << setw(8) << "Years " << years;
  cout << setw(12) << "Payment " << monthlyPayment;
  cout << setw(3) << "|" << endl;
  cout << setw(1) << "|"; 
  cout << setw(74) << "|";

  // Table Headers
  cout << setw(1) << "|";
  



  cout << "\n|  Month    Pay        Total       Monthly     Principal   Total    Reamining  |";
  cout << "\n|                       Paid       Interest       Paid    Principal   Balance  |";
  cout << "\n|                                                           Paid               |";

  cout << "\n|                                                                              |\n";
  printFirstEight(principal, yir, years);
  cout << "|    -         -           -             -           -         -          -    |\n";
  // printLastEight(principal, yir, years);
  cout << " ------------------------------------------------------------------------------";
}

int main() {
  double principal = 70000, yir = 9.5, years = 30;

  // cout << "Please enter the Principal: ";
  // cin >> principal;
  // cout << "Please enter the Yearly Interest Rate, in decimal format: ";
  // cin >> yir;
  // cout << "Please enter the loan length, in years: ";
  // cin >> years;

  printTable(principal, yir, years);
}

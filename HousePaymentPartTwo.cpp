  
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

  // Top half of equation
  double topHalf = principal * mir;

  // Bottom half of equation
  double bottomHalf = mir + 1;
  bottomHalf = 1 / bottomHalf;
  bottomHalf = pow(bottomHalf, 12 * years);
  bottomHalf = 1 - bottomHalf;

  return topHalf / bottomHalf;
}

double getMonthlyInterest(double remainingBalance, double yir) {
  return remainingBalance * (yir / 1200);
}

// Print first eight months of the payment plan to table
void printFirstEight(double principal, double yir, double years) {
  double monthlyPayment = calculateMonthlyPayment(principal, yir, years);
  double totalPaid, monthlyInterest, principalPaid, totalPrincipalPaid, remainingBalance = principal;

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

// Print last eight months of the payment plan to table
void printLastEight(double principal, double yir, double years) {
  double monthlyPayment = calculateMonthlyPayment(principal, yir, years);
  double totalPaid, monthlyInterest, principalPaid;
  double totalPrincipalPaid, remainingBalance = principal;

  for(int i=1; i<=(years * 12) - 8; i++) {
    totalPaid += monthlyPayment;
    monthlyInterest = getMonthlyInterest(remainingBalance, yir);
    principalPaid = monthlyPayment - monthlyInterest;
    totalPrincipalPaid += principalPaid;
    remainingBalance -= principalPaid;
  }


  // Same thing as printTopHalf's loop, except we're starting where the loop above ended
  for(int i=(years * 12) - 7; i<=years * 12; i++) {
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
  cout << setprecision(2) << fixed;
  double monthlyPayment = calculateMonthlyPayment(principal, yir, years);


  cout << " ------------------------------------------------------------------------------";
  cout << "\n|  Principal " << principal << "    Interest Rate " <<  yir << "     Years " << years << "     Payment " << monthlyPayment << " |";
  cout << "\n|                                                                              |";

  cout << "\n|  Month    Pay        Total       Monthly     Principal   Total    Reamining  |";
  cout << "\n|                       Paid       Interest       Paid    Principal   Balance  |";
  cout << "\n|                                                           Paid               |";

  cout << "\n|                                                                              |\n";
  // Print first eight months of payments 
  printFirstEight(principal, yir, years);
  cout << "|    -         -           -             -           -         -          -    |\n";

  // Print last eight months of payments
  printLastEight(principal, yir, years);
  cout << " ------------------------------------------------------------------------------";
}

int main() {
  double principal, yir, years;

  cout << "Enter the principal: ";
  cin >> principal;
  cout << "Enter the yearly interest rate (in decimal format): ";
  cin >> yir;
  cout << "Enter the loan length (in years): ";
  cin >> years;

  printTable(principal, yir, years);

  return 0;
}

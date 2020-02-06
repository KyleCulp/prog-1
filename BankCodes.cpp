
// Kyle Culp
// Programming 1
// Due: 2/6/2020
// Bank Codes
// Enter a bank code to verify if it's valid

#include <iostream>
#include <iomanip> 
using namespace std;

int bankCode, codeArr[9], productArr[9], sum;

// Loop through length of bankCode's digits
void getDigits() {
  for(int i=0; i < 9; i++)  { 
    // Set digit into array
    codeArr[8 - i] = bankCode % 10;

    // Reduce bankCode by one digit
    bankCode = bankCode / 10;
  }
}

void printMultipliers() {
  for(int i=0; i < 8; i++) {
    // Multipliers are 7, 3, 9 respectively
    // Repeating in that order until done
    if(i % 3 == 0) {
      cout << setw(4) << 7;
    } else if (i % 3 == 1) {
      cout << setw(4) << 3;
    } else {
      cout << setw(4) << 9;
    }
  }
  
  cout << endl;
}

int main() {
  cout << "Enter the bank code: ";
  cin >> bankCode;

  getDigits();

  // Print Bank Number one digit at a time
  for(int i=0; i < 9; i++) {
    cout << setw(4) << codeArr[i];
  }

  // New line
  cout << endl;

  // Print Multipliers
  printMultipliers();

  // Multiply, save & print out product
  for(int i=0; i < 8; i++) {
    if(i % 3 == 0) {
      productArr[i] = codeArr[i] * 7;
      cout << setw(4) << productArr[i];
    } else if (i % 3 == 1) {
      productArr[i] = codeArr[i] * 3;
      cout << setw(4) << productArr[i];
    } else {
      productArr[i] = codeArr[i] * 9;
      cout << setw(4) << productArr[i];
    }
  }

  // New line
  cout << endl;

  // Print subtotals
  for(int i=0; i < 8; i++) {
    sum += productArr[i];
    cout << setw(4) << sum;
  }

  // New line
  cout << endl;
  
  // Print Sum
  cout << sum << endl;

  // Print check digit
  cout << codeArr[8] << endl;

  // match the ones place of sum
  // with the check digit & determine
  // if bankcode is valid
  if((sum % 10) == codeArr[8]) {
    cout << "the check code is valid" << endl;
  } else { 
    cout << "the check code is invalid" << endl;
  }

  return 0;
}

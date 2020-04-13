// Kyle Culp
// Programming 1
// Due: 4/13/2020
// Payroll Program
// Read in a file, calculate its contents and display them in a tabular format

#include <iostream>
#include <iomanip>
#include <fstream> 
#include <string>
#include "compute_gross_pay.cpp"
#include "compute_insurance.cpp"
#include "compute_federal_tax.cpp"
using namespace std;

// External Functions
double compute_gross_pay(double rate, double hours);
double compute_insurance(char inscode);
double compute_federal_tax(double PYE);

struct Person {
	string name;
	double rate;
	double hours;
	double inscode;
	double socialTax;
	double stateTax;
	double fedTax;
	double net;
};

int getTotalPeople() {
    ifstream payRoll("payroll.fil"); 
	int totalPeople = 0;
    string line;

	// Get amount of people in file
	while (getline(payRoll, line)) {
		totalPeople++;
	}
	payRoll.close();

	return totalPeople;
}

void printHeading() {
	cout << setw(2) << setprecision(2) << fixed;
	cout << setw(16) << "NAME";
	cout << setw(8) << "RATE";
	cout << setw(8) << "HOURS";
	cout << setw(8) << "INS";
	cout << setw(8) << "SOC";
	cout << setw(8) << "STATE";
	cout << setw(10) << "FED";
	cout << setw(10) << "NET";
	cout << setw(1) << "\n";
	// New Line
	cout << setw(40) << "";
	cout << setw(8) << "SEC";
	cout << setw(8) << "TAX";
	cout << setw(10) << "TAX";
	cout << setw(1) << "\n";
	cout << setw(1) << "\n";
}


void printPeople(Person People[], int peopleSize) {
	for(int i=0; i < peopleSize; i++) {
		cout << setw(16) << People[i].name;
		cout << setw(4) << People[i].rate; // Unsure why it needs to be 4
		cout << setw(8) << People[i].hours;
		cout << setw(8) << People[i].inscode;
		cout << setw(8) << People[i].socialTax;
		cout << setw(8) << People[i].stateTax;
		cout << setw(10) << People[i].fedTax;
		cout << setw(10) << People[i].net;
		cout << setw(1) << "\n";
	}
}

int main () {
  // Setup Functions
	printHeading();
	int totalPeople = getTotalPeople();

  char cname[20];
  double rate, hours;
  char inscode;
	Person People[totalPeople];
	int loopTracker = 0;
  ifstream infile("payroll.fil");

  while (infile.get(cname, 21)) {
    // Dedicate first 20 characters to name
    string name = cname;
		infile >> rate >> hours >> ws >> inscode >> ws;  

		double gross = compute_gross_pay(rate, hours);
		double insCost = compute_insurance(inscode);
		double socialCost = gross * 0.07;
		double stateTax = gross * 0.03;
		double PYE = gross * 52;
		double fedTax = compute_federal_tax(PYE);
		double netPay = gross - insCost - socialCost - stateTax - fedTax;

		// Declare person
		Person person;

		person.name = name;
		person.rate = rate;
		person.hours = hours;
		person.inscode = insCost;
		person.socialTax = socialCost;
		person.stateTax = stateTax;
		person.fedTax = fedTax;
		person.net = netPay;

		People[loopTracker] = person;
		loopTracker++;
	}

  printPeople(People, loopTracker);

  infile.close();
  return 0;
}

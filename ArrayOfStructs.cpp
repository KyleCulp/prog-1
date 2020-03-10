// Kyle Culp
// Programming 1
// Due: 3/10/2020
// Sort an Array of Structs 
// Read in data from a file, put it in an array of structs, and sort said array

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector> 
#include <cctype>
#include <cstdlib> 
using namespace std;

// 2D Array to hold data easier
string Data[11][4];

// Person struct with 4 Fields
struct Person {
	string name;
	string gender;
	string age;
	string height;
};

// Array of People structs
Person People[12];

void fillData() {
  // declare file variable
	ifstream songsFile; 
	songsFile.open("data.txt");
  int loopTracker = 0;
  for(string line; getline(songsFile, line); loopTracker++) {
    // Every 4th line is a new Person
    // Every number inbetween multiples of 4 is added to the 2nd
    // Dimension of the array
    Data[loopTracker / 4][loopTracker % 4] = line;
	}

	songsFile.close();
}

void fillArrays(int dataSize) {
	for(int i; i < dataSize; i++) {
		People[i].name = Data[i][0];
		People[i].gender = Data[i][1];
		People[i].age = Data[i][2];
		People[i].height = Data[i][3];
	}
}

void printArray(int dataSize) {
	cout << setprecision(2) << fixed;
	cout << " ------------------------------------------------------";
	cout << setw(1) << " |\n";
	cout << setw(1) << "|";
	cout << setw(24) << "Name";
	cout << setw(12) << "Gender";
	cout << setw(6) << "Age";
	cout << setw(12) << "Height";
	cout << setw(1) << " |\n";
	cout << " ------------------------------------------------------\n";

	for(int i = 0; i < dataSize; i++) {
		cout << setw(1) << "|";
		cout << setw(24) << People[i].name;
		cout << setw(12) << People[i].gender;
		cout << setw(6) << People[i].age;
		cout << setw(12) << People[i].height;
		cout << setw(1) << " |\n";
	}
	cout << " ------------------------------------------------------\n";
}

// Sort ascending order by age
void sortArrayByAge(int dataSize) {
	for(int i = 1; i < dataSize; i++) {
		for(int k = 0; k < dataSize - i; k++) {
      Person PersonHolder;
      // Convert ages to ints
			int age = atoi(People[k].age.c_str());
      int nextAge = atoi(People[k + 1].age.c_str());
			if(age > nextAge) {
        // Assign current person to temp
        PersonHolder = People[k];
        // Sign next person over current person
        People[k] = People[k + 1];
        // Sign current person to next persons spot
        People[k + 1] = PersonHolder;
      }
		}
	}
}

// Sort descending order by name
void sortArrayByLastName(int dataSize) {
	for(int i = 1; i < dataSize; i++) {
		for(int k = 0; k < dataSize - i; k++) {
      Person PersonHolder;
      // If Current is less than 0, then next item is greater
      int identifier = People[k].name.compare(People[k + 1].name);
      if(identifier < 0) {
        // Assign current person to temp
        PersonHolder = People[k];
        // Sign next person over current person
        People[k] = People[k + 1];
        // Sign current person to next persons spot
        People[k + 1] = PersonHolder;
      }
		}
	}
}

int main () {
  fillData();

  // Get file size
  int fileSize = 0;
	ifstream in("data.txt");
  // Arg filler, blank
	string hold; 
	while(getline(in, hold)) {
		fileSize++;
	}
  // End file size getting

  int dataSize = fileSize / 4;

	// Fill Array of Structs with test data
	fillArrays(dataSize);
	// Print Unsorted Array
	printArray(dataSize);

	// Sort Array by Age, Ascending Order
	sortArrayByAge(dataSize);
	// Print Sorted by Ascending Order Array
	printArray(dataSize);

	// Sort Array by Name, Descending Order
  sortArrayByLastName(dataSize);
	// Print Sorted by Descending Order Array
	printArray(dataSize);

	return 0;
}

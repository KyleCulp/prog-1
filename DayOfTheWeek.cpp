// Kyle Culp
// Programming 1
// Due: 1/28/2020
// Day of the Week
// Read in a specific date, and write out the Day of the Week.

#include <iostream>
using namespace std;

string weekdays[7] = {
  "Saturday", "Sunday", "Monday",
  "Tuesday", "Wednesday", "Thursday", "Friday"
};

int getTableEntry(int month) {
  int tableEntry;
  switch(month) {
    case 1: // January
      tableEntry = 1;
      break;
    case 2: // February
      tableEntry = 4;
      break;
    case 3: // March
      tableEntry = 4;
      break;
    case 4: // April
      tableEntry = 0;
      break;
    case 5: // May
      tableEntry = 2;
      break;
    case 6: // June
      tableEntry = 5;
      break;
    case 7: // July
      tableEntry = 0;
      break;
    case 8: // August
      tableEntry = 3;
      break;
    case 9: // September
      tableEntry = 6;
      break;
    case 10: // October
      tableEntry = 1;
      break;
    case 11: // November
      tableEntry = 4;
      break;
    case 12: // December
      tableEntry = 6;
      break;
    default: // Unsafe default
      tableEntry = 0;
      break;
  }

  return tableEntry;
}

int main() {
  int day, month, year;
  cout << "Please enter the day: ";
  cin >> day;
  cout << "Please enter the month: ";
  cin >> month;
  cout << "Please enter the year: ";
  cin >> year;

  // table entry in seperate function 
  int tableEntry = getTableEntry(month);
  int t = tableEntry + day + year + 6;
  t += year / 4 - year / 100 + year / 400;


  // Account for leapyears
  if((year % 400) && (month <= 2)) {
    t--;
  } else if(year % 100 == 0) {
    // Not a leap year;
  } else if((year % 4 == 0) && (month <= 2)) {
    t--;
  }

  int dotw = t % 7;
  // Print out the weekday from
  // weekdays array
  cout << weekdays[dotw];

  return 0;
}

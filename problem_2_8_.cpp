#include<iostream>
#include<string>
using namespace std;
 //leap year : sana kabissa 
bool IsLeapYear(short Year) {
	// leap year awwl shrt /400 
	if (Year % 400 == 0) {
		return true;
	}
	else if (Year % 100 == 0) {
		return false;
	}
	else if (Year % 4 == 0) {
		return true;
	}
	else {
		return false;
	}
}
short ReadYear() {
	short Year;
	cout << "Please enter a year to check:";
	cin >> Year;
	return Year;
}
int main() {
	short Year = ReadYear();
	if (IsLeapYear(Year))
		cout << "\nYeah,Year[" << Year << "] is a leap year";
	else
		cout << "\nNo,Year[" << Year << "] is not a leap year \n";
	system("pause>0");
	return 0;
}


	

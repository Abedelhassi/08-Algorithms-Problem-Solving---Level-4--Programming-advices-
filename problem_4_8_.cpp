#include<iostream>
#include<string>
using namespace std;
bool isLeapYear(short Year) {
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short NumberOfDaysInYear(short Year) {
	return isLeapYear(Year) ? 366 : 365; //shortcut if else
}
short NumberOfHoursInYear(short Year) {
	return NumberOfDaysInYear(Year) * 24;
}
int NumberOfMinutesInYear(short Year) {
	return NumberOfHoursInYear(Year) * 60;
}
int NumberOfSecondInYear(short Year) {
	return NumberOfMinutesInYear(Year) * 60;
}
short ReadYear() {
	short Year;
	cout << "\nPlease enter a year to check? ";
	cin >> Year;
	return Year;
}
int main() {
	short Year = ReadYear();
	cout << "\nNumber of days in year : [" << Year << "] is " << NumberOfDaysInYear(Year);
	cout << "\nNumber of hours in year : [" << Year << "]is " << NumberOfHoursInYear(Year);
	cout << "\nNumber of minutes i  year : [" << Year << "] is " << NumberOfMinutesInYear(Year);
	cout << "\nNumber of Seconds in year [" << Year << "] is :" << NumberOfSecondInYear(Year);
	system("pause>0");
	return 0;
}
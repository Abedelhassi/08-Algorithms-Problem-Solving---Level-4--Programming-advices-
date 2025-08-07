#include<iostream>
#include<string>
using namespace std;

struct sDate {
	short Year;
	short Month;
	short Day;
};
bool isLeapYear(short Year) {
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);

}
short NumberOfDaysInMonth(short Month, short Year) {
	if (Month < 1 || Month>12)
		return 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}
bool IsLastDayInMonth(sDate Date) {
	return (Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year));
}
bool IsLastMonthInYear(short Month) {
	return (Month == 12);
}
short ReadDay() {
	short Day;
	cout << "\nPlease enter a day ? ";
	cin >> Day;
	return Day;
}
short ReadMonth() {
	short Month;
	cout << "\nPlease enter a Month ? ";
	cin >> Month;
	return Month;
}
short ReadYear() {
	short Year;
	cout << "\nPlease enter a year ? ";
	cin >> Year;
	return Year;
}
sDate  ReadFullDate() {
	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}
int main() {
	sDate Date1 = ReadFullDate();
	if (IsLastDayInMonth(Date1))
		cout << "\n,Yes,Day is last day in month ";
	else
		cout << "\nNope,Day isn t last day in month";
	if (IsLastMonthInYear(Date1.Month))
		cout << "Yes,Month is last month in year ";
	else
		cout << "\nNo,Month is not last month in year";
	system("pause>0");
	return 0;
}


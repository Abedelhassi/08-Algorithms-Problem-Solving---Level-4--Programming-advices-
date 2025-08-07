#include<iostream>
using namespace std;
bool isLeapYear(short Year) {
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);

}
short NumberOfDaysInMonth(short Month, short Year) {
	if (Month < 1 || Month>12)
		return 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}
short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year) {
	short TotalDays = 0;
	for (int i = 1; i <= Month - 1; i++) {
		TotalDays += NumberOfDaysInMonth(i, Year);
	}
	TotalDays += Day;
	return TotalDays;
}
struct sDate {
	short Year;
	short Month;
	short Day;
};
sDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year) {
	sDate Date;
	short RemainingDays = DateOrderInYear;
	short MonthDays = 0;
	Date.Year = Year;
	Date.Month = 1; 
	while (true) {
		MonthDays = NumberOfDaysInMonth(Date.Month, Year);
		if (RemainingDays > MonthDays) {
			RemainingDays -= MonthDays;
			Date.Month++;
		}
		else {
			Date.Day = RemainingDays;
			break;
		}
	}
	return Date;
}
short ReadDay() {
	short Day;
	cout << "\nPlease enter a day :";
	cin >> Day;
	return Day;

}
short ReadMonth() {
	short Month;
	cout << "\nPlease enter a month :";
	cin >> Month;
	return Month;

}
short ReadYear() {
	short Year;
	cout << "\nPlease enter a year :";
	cin >> Year;
	return Year;
}
int main() {
	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();
	short DayOrderInYear = NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);
	cout << "\nNumber of Days from the begining of the year is " << DayOrderInYear << "\n\n";
	sDate Date;
	Date = GetDateFromDayOrderInYear(DayOrderInYear, Year);
	cout << "Date for [" << DayOrderInYear << "] is : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");
	return 0;
}

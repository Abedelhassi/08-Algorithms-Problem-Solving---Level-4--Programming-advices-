#include<iostream>
#include<string>
using namespace std;
bool isLeapYear(short Year) {
	// if year is divisible by 4 AND not divisible by 100// OR if year is divisible by 400// then it is a leap year
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short DayOfWeekOrder(short Day, short Month, short Year) {
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	// Gregorian://0:sun, 1:Mon, 2:Tue...etc
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return arrDayNames[DayOfWeekOrder];
}
short NumberOfDaysInMonth(short Month, short Year) {
	if (Month < 1 || Month>12)
		return 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}
string MonthShortName(short MonthNumber) {
	string Months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	return (Months[MonthNumber - 1]);
}
void PrintMonthCalender(short Month, short Year) {
	int NumberOfDays;
	int current = DayOfWeekOrder(1, Month, Year);
	NumberOfDays = NumberOfDaysInMonth(Month, Year);
	printf("\n________________________%s_______________\n\n", MonthShortName(Month).c_str());
	//colom:
	printf(" Sun   Mon  Tue  Wed  Thu  Fri  Sat\n");
	//space:
	int i;
	for (i = 0; i < current; i++)
		printf("           ");
	for (int j = 1; j <= NumberOfDays; j++) {
		printf("%5d", j);
		if (++i == 7) {
			i = 0;
			printf("\n");
		}
	}
	printf("\n____________________________________________________\n");
}
void PrintYearCalendar(int Year) {
	printf("\n___________________________________________\n\n");
	printf("                     Calendar-%d\n", Year);
	printf("_______________________________________________\n");
	for (int i = 1; i <= 12; i++) {
		PrintMonthCalender(i, Year);
	}
	return;
}


short ReadYear() {
	short Year;
	cout << "please enter year";
	cin >> Year;
	return Year;
}
int main() {
	PrintYearCalendar(ReadYear());
	system("pause >0");
	return 0;
}
#include<iostream>
#include<string>
using namespace std;
struct sDate {
	short Year;
	short Month;
	short Day;
};
bool IsDate1EqualDate2(sDate Date1, sDate Date2) {
	return (Date1.Year == Date1.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false  ) : false) : false;
}
short ReadDay() {
	short Day;
	cout << "\nPlease read a day: ";
	cin >> Day;
	return Day;
}
short ReadMonth() {
	short Month;
	cout << "\nPlease read a month: ";
	cin >> Month;
	return Month;
}
short ReadYear() {
	short Year;
	cout << "\nPlease read a year: ";
	cin >> Year;
	return Year;
}
sDate ReadFullDate()
{
	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}
int main() {
	sDate Date1 = ReadFullDate();
	sDate Date2 = ReadFullDate();
	if (IsDate1EqualDate2(Date1, Date2))
		cout << "\nYes,Date1 is equal to date 2 ";
	else
		cout << "\nNo,Date 1 is NOT equal to  date 2 ";
	system("pause>0");
	return 0;
}


//overlap period :
// wAY 1 chourout yasr way 2 : 2 cases

#include <iostream>
using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;

};
struct stPeriod {
    stDate StartDate;
    stDate EndDate;
};


bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}
bool IsDate1EqualDate2(stDate Date1, stDate Date2) {
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}
bool IsDate1AfterDate2(stDate Date1, stDate Date2) {
    // hna kna 9adrin ndirou function o5ra bs7 lhdf hwa reusability m3naha nwadou nst5dmou nfs l code 
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}
enum enDataCompare { Before = -1, Equal = 0, After = 1 };
enDataCompare CompareDates(stDate Date1, stDate Date2) {
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDataCompare::Before;
    if (IsDate1EqualDate2(Date1, Date2))
        return enDataCompare::Equal;
    /* if(isdata1after )
    return equal
    */
    // hada asr3 :
    return enDataCompare::After;
}
bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2) {
    if (CompareDates(Period2.EndDate, Period1.StartDate) == enDataCompare::Before || CompareDates(Period2.StartDate, Period1.EndDate) == enDataCompare::After)
        return false;
    else
        return true;
}
short ReadDay()
{
    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}
short ReadMonth()
{
    short Month;
    cout << "Please enter a Month? ";
    cin >> Month;
    return Month;
}
short ReadYear()
{
    short Year;
    cout << "Please enter a Year? ";
    cin >> Year;
    return Year;
}
stDate ReadFullDate()
{
    stDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}
stPeriod ReadPeriod() {
    stPeriod Period;
    cout << "\nEnter start date:\n";
    Period.StartDate = ReadFullDate();
    cout << "\nenter end date : \n";
    Period.EndDate = ReadFullDate();
    return Period;
}
int main()
{
    cout << "\nEnter Period 1:";
    stPeriod Period1 = ReadPeriod();
    cout << "\nEnter Period 2:"; 
    stPeriod Period2 = ReadPeriod(); 
    if (IsOverlapPeriods(Period1, Period2))    
        cout << "\nYes, Periods Overlap\n"; 
    else     
        cout << "\nNo, Periods do not Overlap\n";
   
    system("pause>0");
    return 0;
}
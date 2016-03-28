#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

class Date
{
    int year,month,day;
public:
    Date();
    Date(int y,int m,int d)
    {
        setDate(y,m,d);
    }
    int getYear(){return year;}
    int getMonth(){return month;}
    int getDay(){return day;}
    void setDate(int y,int m,int d)
    {
        year = y,month = m,day = d;
    }
    void print()
    {
        cout<<year<<"/"
            <<setfill('0')<<setw(2)<<month<<"/"
            <<setfill('0')<<setw(2)<<day<<endl;
    }
    void addOneDay();
    int IsLeapYear()
    {
        return (year%4==0&&year%100!=0)||(year%400==0);
    }
};
void Date::addOneDay()
{

    if (month==12) {
        if (day==31) {
            year =year+1;
            month =1 ;
            day =1;
        }
        else
            day +=1;

    }

    else if (month==1||month==3||month==5||month==7||month==8||month==10) {

        if (day==31) {
            month= month + 1;
            day =1;
        }
        else
            day +=1;

    }
    else if (month==4||month==6||month==9||month==11) {

        if (day==30) {
            month+=1;
            day=1;
        }
        else
            day += 1;
    }

    else if (month==2) {
        if (IsLeapYear()) {
            if (day==29) {
                day =1,month =3;
            }
            else
            {
                day+=1;
            }
        }
        else if (!IsLeapYear()) {
            if (day==28) {
                day =1,month =3;
            }
            else
            {
                day+=1;
            }
        }

    }


}
int main()
{
    int t;
    cin>>t;
    for (int var = 0; var < t; ++var) {
        int y,m,d;
        cin>>y>>m>>d;
        Date date(y,m,d);
        cout<<"Today is ";
        date.print();

        date.addOneDay();
        cout<<"Tomorrow is ";
        date.print();
    }
    return 0;
}

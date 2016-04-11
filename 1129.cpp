#include <iostream>
#include <string>
using namespace std;
class CDate
{
private:

public:
    int year, month, day;
   CDate(){}
   CDate(int y, int m, int d) { year = y; month = m; day = d; }
   ~CDate(){}
   bool isLeapYear() { return (year%4 == 0 && year%100 != 0) || year%400 == 0; }
   int getYear() { return year; }
   int getMonth() { return month; }
   int getDay() { return day; }
   int getDayofYear()
   {
   int i, sum=day;
   int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
   int b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

       if (isLeapYear())
           for(i=0;i<month;i++)   sum +=b[i];
       else
           for(i=0;i<month;i++)   sum +=a[i];

        return sum;
   }
};
class Software
{
    string name,type,media;
    CDate date;
public:

    Software(){}
    Software(string tname,string ttype,string tmedia,int tyear,int tmonth,int tday) :
        name(tname),type(ttype),media(tmedia),date(tyear,tmonth,tday)
    {}
    ~Software(){}
    Software(Software &s)
    {

        name=s.name;
        type="B";
        media="H";
//        date(s.date);
//        this->date(s.date.year,s.date.getMonth(),s.date.getDay());
//  date(s.date.year,s.date.month,s.date.day);
        date.year=s.date.year;
        date.month=s.date.month;
        date.day=s.date.day;
    }
    string Show_Type()
    {
        if (type=="O") {
            return "original";
        }
        if (type=="B") {
            return "backup";
        }
        if (type=="T") {
            return "trial";
        }
    }
    string Show_Media()
    {
        if (media=="D") {
            return "optical disk";
        }if (media=="H") {
            return "hard disk";
        }
        if (media=="U") {
            return "USB disk";
        }
    }
    void Print()
    {
        cout<<"name:"<<name<<endl
           <<"type:"<<Show_Type()<<endl
          <<"media:"<<Show_Media()<<endl;

        if (date.getYear()==0&&
            date.getMonth()==0&&
             date.getDay()==0)
        {
            cout<<"this software has unlimited use"<<endl;
        }
        else if (date.getYear()<=2015&&
            date.getMonth()<=4&&
            date.getDay()<7)
        {
            cout<<"this software has expired"<<endl;
        }
        else {
            cout<<"this software is going to be expired in "
               <<date.getDayofYear()-97<<" days"<<endl;
        }
        cout<<endl;
    }
};

int main()
{
    int t;
    cin>>t;
    cin.get();
    for (int var = 0; var < t; ++var) {
        string name,type,media;
        int year,month,day;
        cin>>name>>type>>media>>year>>month>>day;

        Software ori(name,type,media,year,month,day);
        ori.Print();

        Software aft(ori);
        aft.Print();
    }

    return 0;
}

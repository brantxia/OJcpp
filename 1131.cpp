#include <iostream>
#include <cmath>
#include <vector>
#include <cctype>
#include <string>
using namespace std;

class Counter
{
protected:
    int value;
public:
    Counter() {}
    Counter(int tvalue):
        value(tvalue)
    {}
    ~Counter() {}

    void Increment()
    {
        value++;
    }
};

class LoopCounter:public Counter
{
    friend class Clock;
private:
    int min_value,max_value;
public:
    LoopCounter()
    {

    }
    LoopCounter(int tvalue):
        Counter(tvalue)
    {
        min_value=0;
        max_value=60;
    }
    ~LoopCounter() {}
    void Increment()
    {
        value = (value)%max_value;
    }

};
class Clock
{
private:
    LoopCounter hour,minute,second;
public:
    Clock() {}
    Clock(int thour,int tminute,int tsecond) :
    hour(thour),minute(tminute),second(tsecond)
    {}
    ~Clock() {}
    void Time(int s)
    {
        int sum = hour.value*3600 + minute.value*60 + second.value +s;
        hour.value = (sum/3600)%24;
        minute.value = (sum%3600)/60;
        second.value = (sum%3600)%60;
    }
    void Showtime()
    {
        cout<<hour.value<<":"<<minute.value<<":"<<second.value<<endl;
    }
};
int main()
{
    int n;
    cin>>n;
    for (int var = 0; var < n; ++var) {
        int hour,minute,second;
        cin>>hour>>minute>>second;
        Clock clock(hour,minute,second);

        int s;
        cin>>s;
        clock.Time(s);
        clock.Showtime();
    }
    return 0;
}


#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;

int fna1(int a)
{
    return a*a;
}

double fna2(double a)
{
    return sqrt(a);
}

void fna3(string &a)
{
    int len = a.length();
    for (int i = 0; i < len; ++i) {
        a[i]=toupper(a[i]);
    }
}

int main()
{
    int t;
    cin>>t;
    for (int var = 0; var < t; ++var) {

        int (*fnb1)(int a);
        double (*fnb2)(double a);
        void (*fnb3)(string a);
        fnb1 = fna1;
        fnb2 = fna2;
        fnb3 = fna3;

        char alpha;
        cin>>alpha;
        if (alpha=='I') {
            int aint;
            cin>>aint;
            cout<<fnb1(aint)<<endl;
        }
        else if (alpha=='F') {
            double adouble;
            cin>>adouble;
            cout<<fnb2(adouble)<<endl;
        }
        else if (alpha=='S') {
            string astring;
            cin>>astring;
            fnb3(astring);
        }
    }
    return 0;
}


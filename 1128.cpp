#include <iostream>
#include <cmath>
#include <cctype>
#include <string>
using namespace std;

class CTelNumber
{
public:
    string number;
    CTelNumber(string a):
    number(a)
    {
        int len = a.length();
        if (len!=7) {
            number = "Illegal phone number";
        }
        for (int i = 0; i < len; ++i) {
            if (!isdigit(a[i])) {
                number = "Illegal phone number";
            }
        }
        if (!(number[0]=='2'||number[0]=='3'||number[0]=='4'||
              number[0]=='5'||number[0]=='6'||number[0]=='7')) {
            number = "Illegal phone number";
        }

    }
    CTelNumber(CTelNumber& c) {
        this->number=c.number;
        if (number[0]=='2'||number[0]=='3'||number[0]=='4') {
            number.insert(0,"8");
        }
        if (number[0]=='5'||number[0]=='6'||number[0]=='7') {
            number.insert(0,"2");
        }
    }
    ~CTelNumber(){}
};
int main()
{
    int t;
    cin>>t;
    cin.get();
    for (int var = 0; var < t; ++var) {
        string a;
        getline(cin,a);

        CTelNumber orictel(a);
        CTelNumber aftctel(orictel);
        cout<<aftctel.number<<endl;
    }
    return 0;
}


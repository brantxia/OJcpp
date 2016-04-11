#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

class CTriangle
{
public:
    CTriangle() {}
    CTriangle(double ta,double tb,double tc):
    a(ta),b(tb),c(tc)
    {
        Judge_Type();
    }
    int Judge_Type()
    {
        Bubble_Sort();
        if (a+b<c) {
           tri_type = {"no triangle"};
           return 0;
        }

        else{
            if (a==b&&b==c&&a==c) {
                tri_type ={"equilateral triangle"};
            }
            else if (a==b&&c==1.414*a) {
                tri_type = {"isosceles right triangle"};
            }
            else if (a==b) {
                tri_type = {"isosceles triangle"};
            }
            else if (a*a+b*b==c*c) {
                tri_type = {"right triangle"};
            }
            else {
                tri_type = {"general triangle"};
            }
            return 1;
        }

    }

    void Bubble_Sort()
    {
        double m[3];
        m[0] = a,m[1] = b,m[2] = c;
        int flag ;
        for (int p = 2; p >=0; --p) {
            flag = 0;
            for (int i = 0; i < p; ++i) {
                if (m[i]>m[i+1]) {
                    swap(m[i],m[i+1]);
                    flag = 1;
                }
            }
            if (flag==0) {
                break;
            }
        }
        a=m[0],b=m[1],c=m[2];

    }

    double Cal_Area()
    {
        if (tri_type!="no triangle") {
            double p,s;
            p = (a+b+c)*0.5;
            s = sqrt(p*(p-a)*(p-b)*(p-c));
            return s;
        }
        else
            return 0;
    }
    string Get_Type()
    {
        return tri_type;
    }

    ~CTriangle()
    {
        a=0,b=0,c=0;
        tri_type = "no triangle";
    }

    double a,b,c;
    string tri_type;
};

int main()
{
    int t;
    cin>>t;
    for (int var = 0; var < t; ++var) {
        double ta,tb,tc;
        cin>>ta>>tb>>tc;
        CTriangle ctr(ta,tb,tc);

        if (ctr.tri_type!="no triangle") {
            cout<<ctr.tri_type;
            cout<<", "
               <<setiosflags(ios::fixed)<<setprecision(1)
              <<ctr.Cal_Area()<<endl;
        }
        else
            cout<<ctr.tri_type<<endl;
    }
    return 0;
}

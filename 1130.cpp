#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <memory>
#include <iomanip>
using namespace std;

class CFraction
{
private:
    int fz, fm;
public:

     void init(int fz_val, int fm_val)
     {
         fz = fz_val;
         fm = fm_val;
     }
     CFraction add(const CFraction &r);
     CFraction sub(const CFraction &r);
     CFraction mul(const CFraction &r);
     CFraction div(const CFraction &r);
     int getGCD();   // 求对象的分子和分母的最大公约数
     void print();
};

CFraction CFraction::add(const CFraction &r)
{
    int nfz,nfm;
    nfm = fm *(r.fm);
    nfz =fz*(r.fm) + (r.fz)*fm;
    CFraction q;
    q.init(nfz,nfm);
    q.init(nfz/q.getGCD(),nfm/q.getGCD());
    return q;

}
CFraction CFraction::sub(const CFraction &r)
{
    int nfz,nfm;
    nfm = fm *(r.fm);
    nfz =fz*(r.fm) - (r.fz)*fm;
    CFraction q;
    q.init(nfz,nfm);
    q.init(nfz/q.getGCD(),nfm/q.getGCD());
    return q;
}
CFraction CFraction::mul(const CFraction &r)
{
    int nfz,nfm;
    nfm = fm *(r.fm);
    nfz =fz*(r.fz);
//    cout<<nfm<<nfz;
    CFraction q;
    q.init(nfz,nfm);
//    cout<<q.getGCD()<<"*";
    q.init(nfz/q.getGCD(),nfm/q.getGCD());
    return q;
}
CFraction CFraction::div(const CFraction &r)
{
    int nfz,nfm;
    nfm = fm *(r.fz);
    nfz =fz*(r.fm);
    CFraction q;
    q.init(nfz,nfm);
    q.init(nfz/q.getGCD(),nfm/q.getGCD());
    return q;
}

int CFraction::getGCD()
{
    int a,b;
    if (fz>fm) {
        a=fz;
        b=fm;
    }
    else
    {
        a=fm;
        b=fz;
    }

    while((a%b)!=0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return b;
}

int GCD(int fz,int fm)
{
    int a,b;
    if (fz>fm) {
        a=fz;
        b=fm;
    }
    else
    {
        a=fm;
        b=fz;
    }

    while((a%b)!=0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return b;
}


void CFraction::print()
{
    cout<<fz<<"/"<<fm<<endl;
}
int main()
{
    int t;
    cin>>t;
    for (int var = 0; var < t; ++var) {
        CFraction c1,c2;
        int x1,y1,x2,y2;
        char k1,k2;
        cin>>x1>>k1>>y1;
        cin>>x2>>k2>>y2;
        c1.init(x1,y1);
        c2.init(x2,y2);

        CFraction d1;
        d1=c1.add(c2);
        d1.print();

        CFraction d2;
        d2=c1.sub(c2);
        d2.print();

        CFraction d3;
        d3=c1.mul(c2);
        d3.print();

        CFraction d4;
        d4=c1.div(c2);
        d4.print();
    }
    return 0;
}

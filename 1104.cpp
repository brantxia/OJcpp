#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

class CAccount
{
public:
    int account;
    string name;
    float balance;
    CAccount(){}
    CAccount(int taccount,string tname,float tbalance):
        account(taccount),name(tname),balance(tbalance)
    {}
    ~CAccount(){}
    void Deposit(float ck)
    {
        balance = balance + ck;
        cout<<"saving ok!"<<endl;
    }
    void Withdraw(float qk)
    {
        if(qk>balance)
        {
            cout<<"sorry! over balance!"<<endl;
        }
        else
        {
            balance = balance - qk;
            cout<<"withdraw ok!"<<endl;
        }

    }
    void Check()
    {
        cout<<"balance is "<<balance<<endl;
    }
};

class CCreditcard:public CAccount
{
public:
    float limit;
    CCreditcard(){}
    CCreditcard(int taccount,string tname,float tbalance,float tlimit):
        CAccount(taccount,tname,tbalance),limit(tlimit)
    {}
    ~CCreditcard(){}
    void Withdraw(float qk)
    {
        if((qk-balance)>limit)
        {
            cout<<"sorry! over limit!"<<endl;
        }
        else
        {
            balance = balance -qk;

            cout<<"withdraw ok!"<<endl;
        }

    }
};

int main()
{
    int account1;
    cin>>account1;
    string name1;
    cin>>name1;
    float balance1;
    cin>>balance1;
    float ck1,qk1;
    cin>>ck1>>qk1;

    CAccount ca(account1,name1,balance1);
    ca.Check();
    ca.Deposit(ck1);
    ca.Check();
    ca.Withdraw(qk1);
    ca.Check();
 //
    int account2;
    cin>>account2;
    string name2;
    cin>>name2;
    float balance2;
    cin>>balance2;
    float limit2;
    cin>>limit2;

    CCreditcard cc(account2,name2,balance2,limit2);
    cc.Check();
    float ck2,qk2;
    cin>>ck2;
    cc.Deposit(ck2);
    cc.Check();
    cin>>qk2;
    cc.Withdraw(qk2);
    cc.Check();
    //
    return 0;
}

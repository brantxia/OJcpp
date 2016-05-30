#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class BaseAccount
{
public:
    string name;
    string account;
    int balance;
    BaseAccount(string tname,string taccount,int tbalance) :
        name(tname),account(taccount),balance(tbalance)
    {}
    void Deposit(int deposit)
    {
        balance += deposit;
    }
    virtual void Withdraw(int withdraw)
    {
        if (withdraw>balance) {
            cout<<"insufficient"<<endl;
        }
        else
            balance -= withdraw;
    }
    virtual void Display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
    }
};

class BasePlus : public BaseAccount
{
public:
    int limit;
    int limit_sum;
    BasePlus(string tname,string taccount,int tbalance) :
        BaseAccount(tname,taccount,tbalance)
    {
        limit = 5000;
        limit_sum = 0;
    }

    virtual void Withdraw(int withdraw)
    {
        if (withdraw<=balance) {
            balance -= withdraw;
            limit_sum = 0;
        }
        else if (withdraw>balance&&withdraw<=(balance+limit-limit_sum)) {
            balance = 0;
            limit_sum = (withdraw - balance);
        }
        else if (withdraw>(balance+limit-limit_sum)) {
            cout<<"insufficient"<<endl;
        }
    }
    virtual void Display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance;
        cout<<" limit:"<<limit-limit_sum<<endl;
    }
};

int main()
{
    int t;
    cin>>t;
    for (int var = 0; var < t; ++var) {
        string name;
        cin>>name;
        string account;
        cin>>account;
        int balance;
        cin>>balance;

        int deposit1,withdraw1,deposit2,withdraw2;
        cin>>deposit1>>withdraw1>>deposit2>>withdraw2;

        if (account[1]== 'A') {
            BaseAccount a(name,account,balance);
            BaseAccount *p =&a;
            p->Deposit(deposit1);
            p->Withdraw(withdraw1);
            p->Deposit(deposit2);
            p->Withdraw(withdraw2);
            p->Display();
        }
        if (account[1]== 'P') {
            BasePlus a(name,account,balance);
            BaseAccount *p =&a;
            p->Deposit(deposit1);
            p->Withdraw(withdraw1);
            p->Deposit(deposit2);
            p->Withdraw(withdraw2);
            p->Display();
        }
    }
    return 0;
}





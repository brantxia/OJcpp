#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Animal
{
public:
    string name;
    int age;
    Animal(){}
    Animal(string tname,int tage) :
        name(tname),age(tage)
    {}
    virtual void Speak() = 0;
};

class Tiger : public Animal
{
public:
    Tiger(string tname,int tage) :
        Animal(tname,tage)
    {}
    virtual void Speak()
    {
        cout<<"Hello,I am "<<name
           <<",AOOO"<<"."<<endl;
    }
};

class Dog : public Animal
{
public:
    Dog(string tname,int tage) :
        Animal(tname,tage)
    {}
    virtual void Speak()
    {
        cout<<"Hello,I am "<<name
           <<",WangWang"<<"."<<endl;
    }
};

class Duck : public Animal
{
public:
    Duck(string tname,int tage) :
        Animal(tname,tage)
    {}
    virtual void Speak()
    {
        cout<<"Hello,I am "<<name
           <<",GAGA"<<"."<<endl;
    }
};

class Pig : public Animal
{
public:
    Pig(string tname,int tage) :
        Animal(tname,tage)
    {}
    virtual void Speak()
    {
        cout<<"Hello,I am "<<name
           <<",HENGHENG"<<"."<<endl;
    }
};
int main()
{
    int t;
    cin>>t;
    for (int var = 0; var < t; ++var) {
        string type,name;
        int age;
        cin>>type>>name>>age;

        if (type=="Tiger") {
            Tiger tiger(name,age);
            Animal *p = &tiger;
            p->Speak();
        }
        else if (type=="Dog") {
            Dog dog(name,age);
            Animal *p = &dog;
            p->Speak();
        }
        else if (type=="Duck") {
            Duck duck(name,age);
            Animal *p = &duck;
            p->Speak();
        }
        else if (type=="Pig") {
            Pig pig(name,age);
            Animal *p = &pig;
            p->Speak();
        }
        else
            cout<<"There is no "<<type
               <<" in our Zoo."<<endl;
    }
    return 0;
}

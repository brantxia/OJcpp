#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

int num = 0;
class Robot
{
private:
    string name;
    int blood,hurt,defense;
    string type;
    int level;
public:
    Robot(){}
    Robot(string tname,string ttype,int tlevel):
        name(tname),type(ttype),level(tlevel)
    {
        set(type);
    }
    void set(string stype)
    {
        type = stype;
        blood = level * 5;
        hurt = level * 5;
        defense = level * 5;

        if (stype == "N") {}
        else if (stype == "A") {
            hurt = level * 10;
        }
        else if (stype == "D") {
            defense = level * 10;
        }
        else if (stype == "H") {
            blood = level * 50;
        }
    }

    friend Transform(Robot &a, string stype);

    void Print()
    {
        cout<<name<<"--"<<type<<"--"
           <<level<<"--"<<blood<<"--"
          <<hurt<<"--"<<defense<<endl;
    }
};

int Transform(Robot &r1,string stype)
{
    if (stype != r1.type) {
        r1.set(stype);
        num++;
        return 1;
    }
    else
        return 0;
}

int main()
{
    int t;
    cin>>t;
    for (int var = 0; var < t; ++var) {
        string name;
        string type;
        int level;
        string stype;
        cin>>name>>type>>level>>stype;
        Robot r1(name,type,level);
        Transform(r1,stype);
        r1.Print();
    }
    cout<<"The number of robot transform is "<<num<<endl;
    return 0;
}

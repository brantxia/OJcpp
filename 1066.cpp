#include <iostream>
#include <string>
using namespace std;
int substr(string &str1,string &str2,int index)
{
    int len = str1.size();
    if (index<1||index>len) {
        return 0;
    }
    else if(index>=1&&index<=len)
    {
        str2 = str1.substr(index-1);
        return 1;
    }
}
int main()
{
    int t;
    cin>>t;
    for (int var = 0; var < t; ++var) {
        string str1,str2;
        cin.ignore();
        getline(cin,str1);

        int index;
        cin>>index;

        if (substr(str1,str2,index)) {
            cout<<str2<<endl;
        }
        else
            cout<<"IndexError"<<endl;
        }

    return 0;
}


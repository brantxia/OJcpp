#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for (int var = 0; var < t; ++var) {
        int n;
        cin>>n;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        int num;
        cin>>num;

        int *p=&a[n/2];
        cout<<*(--p)<<" ";
        ++p;
        cout<<*(++p)<<endl;
        --p;
        cout<<*(p-n/2+num-1);

    }
    return 0;
}


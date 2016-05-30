#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class nstack : public stack<T>
{
public:
    int max;
    nstack()
    {
        max = 10;
    }
    void inflate(int lenth);
    nstack & operator = (nstack & rightValue);
    void show();
};

template <typename T>
void nstack<T>::show()
{
    stack<int> a;
    while(!this->empty())
    {
        a.push(this->top());
        this->pop();
    }
    while(!a.empty())
    {
        cout<<a.top();
        a.pop();
    }
    cout<<endl;
}


template <typename T>
nstack<T>& nstack<T>::operator = (nstack<T> & rightValue)
{
    stack<int> a;
    while(!this->empty())
    {
        a.push(this->top());
        this->pop();
    }

    stack<int> b;
    while(!rightValue.empty())
    {
        b.push(rightValue.top());
        rightValue.pop();
    }

    while (!b.empty()) {
        this->push(b.top());
        b.pop();
    }
    while (!a.empty()) {
        rightValue.push(a.top());
        a.pop();
    }
    return *this;
}

int main()
{
    int n1,n2;
    cin>>n1>>n2;

    int z1[n1];
    for (int i = 0; i < n1; ++i) {
        cin>>z1[i];
    }
    int z2[n2];
    for (int i = 0; i < n2; ++i) {
        cin>>z2[i];
    }

    nstack<int> s1;
    nstack<int> s2;

    for (int i = 0; i < n1; ++i) {
        s1.push(z1[i]);
    }
    for (int i = 0; i < n2; ++i) {
        s2.push(z2[i]);
    }

    s2.pop();
    s2 = s1;

    s1.show();
    s2.show();

    return 0;
}





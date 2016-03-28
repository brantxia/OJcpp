#include <iostream>

using namespace std;
class CStack
{
public:
    CStack()
    {
        cout<<"Constructor."<<endl;
        size = 10;
        top = 0;
    }
    CStack(int s)
    {
        cout<<"Constructor."<<endl;
        size = s;
        top = 0;
        a=new int[size];
    }

    int get(int index)
    {
        return a[index];
    }
    void push(int n)
    {
        if (!isFull()) {
            a[top] = n;
            top = top + 1;
        }
    }
    int pop()
    {
        if (!isEmpty()) {
            top = top - 1;
            return a[top];
        }
    }
    int isEmpty()
    {
        if(top==0)
        {
            return 1;
        }
        else
            return 0;
    }
    int isFull()
    {
        if (top==size) {
            return 1;
        }
        else
            return 0;
    }

    ~CStack()
    {
        cout<<"Distructor."<<endl;
    }
private:
    int *a;
    int size;
    int top;
};

int main()
{

    int t,var,i,j;
    cin>>t;
    for (var= 0; var < t; ++var) {
        int size;
        cin>>size;
        int a[size];
        for (i = 0; i < size; ++i) {
            cin>>a[i];
        }
        CStack stack(size);
        for ( j = 0; j < size; ++j) {
            stack.push(a[j]);
        }
        for (i = 0; i < size-1; ++i) {
            cout<<stack.pop()<<" ";
        }
        cout<<stack.pop()<<endl;
    }
    return 0;
}

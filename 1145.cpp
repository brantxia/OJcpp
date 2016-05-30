#include <iostream>
#include <cmath>
#include <cctype>
#include <string>
using namespace std;

class Array
{
public:
    int *a;
    int size;
    Array()
    {
        cout<<"Constructor."<<endl;
        a = new int[10];
    }
    Array(int tsize) :
        size(tsize)
    {
        cout<<"Constructor."<<endl;
        a = new int[10];
    }
    Array(const Array& tarray):
        size(tarray.size)
    {
        a = new int[10];
        for (int i = 0; i < size; ++i) {
            a[i] = tarray.a[i];
        }
    }
    ~Array()
    {
        delete []a;
        cout<<"Distructor."<<endl;
    }
    void Input(int ta[])
    {
        for (int i = 0; i < size; ++i) {
            a[i] = ta[i];
        }
    }
    void Output()
    {
        for (int i = 0; i < size-1; ++i) {
            cout<<a[i]<<" ";
        }
        cout<<a[size-1]<<endl;
    }
    void Sort()
    {
        int flag;
        for (int p = size-1; p >= 0; p--) {
            flag = 0;
            for (int i = 0; i < p; ++i) {
                if (a[i]>a[i+1]) {
                    swap(a[i],a[i+1]);
                    flag = 1;
                }
            }
            if (flag==0) {
                break;
            }
        }
    }
    void Insert(int value)
    {
        size++;
        a[size-1] = value;
        Sort();
    }
    void Mdelete(int index)
    {
        for (int i = index; i < size; ++i) {
            a[i] = a[i+1];
        }
        size--;
    }
};

int main()
{
    int t;
    cin>>t;
    for (int var = 0; var < t; ++var)
    {
        int n;
        cin>>n;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }

        Array array(n);
        array.Input(a);
        array.Sort();
        cout<<"after sort:";
        array.Output();

        int val_inserted;
        cin>>val_inserted;
        array.Insert(val_inserted);
        cout<<"after insert:";
        array.Output();

        int key_deleted;
        cin>>key_deleted;
        array.Mdelete(key_deleted);
        cout<<"after delete:";
        array.Output();
    }
    return 0;
}


#include <iostream>
#include <string>
#include <vector>
using namespace std;\

class Matrix
{
public:
    int m,n;
    int **data;

    Matrix(int a[][10],int tm,int tn):
        m(tm),n(tn)
    {
        data=new int*[m];  //先创建m行
        for(int i=0;i<m;i++)
        { data[i]=new int[n]; }  //再创建n列

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                data[i][j] = a[i][j];
            }
        }
    }

    Matrix& operator + (Matrix& s);
    void Print();
};

Matrix& Matrix::operator + (Matrix& s)
{
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] += s.data[i][j];
        }
    }
    return *this;
}
void Matrix::Print()
{
    int i,j;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n-1; ++j) {
            cout<<data[i][j]<<" ";
        }
        cout<<data[i][j];
        cout<<endl;
    }
}

int main()
{
    int t;
    cin>>t;
    for (int var = 0; var < t; ++var) {
        int m,n;
        cin>>m>>n;
        int a[10][10],b[10][10];

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin>>a[i][j];
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin>>b[i][j];
            }
        }

        Matrix x1(a,m,n);
        Matrix x2(b,m,n);

        (x1 + x2).Print();
    }
    return 0;
}

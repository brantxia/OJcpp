#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class Shape
{
public:
    double area;
    Shape() {}
    ~Shape() {}

    virtual double Area() = 0;

};

class Circle : public Shape
{
public:
    double r;
    Circle(double tr) :
        r(tr)
    {}
    virtual double Area()
    {
        return 3.14 * r * r;
    }

};

class Square : virtual public Shape
{
public:
    double l;
    Square(double tl):
        l(tl)
    {
    }
    virtual double Area()
    {
        return l * l;
    }
};

class Rectangle : virtual public Shape
{
public:
    double l,w;
    Rectangle(double tl,double tw):
        l(tl),w(tw)
    {
    }
    virtual double Area()
    {
        return  l * w;
    }
};


int main()
{
    int t;
    cin>>t;
    for (int var = 0; var < t; ++var) {
        double cr,sl,rl,rw;
        cin>>cr>>sl>>rl>>rw;
//        vector<Shape*> s(3);
        Shape *sh[3];

        Circle c(cr);
        Square s(sl);
        Rectangle r(rl,rw);
        sh[0] = &c;
        sh[1] = &s;
        sh[2] = &r;
        for (int i = 0; i < 3; ++i) {
            cout<<setiosflags(ios::fixed)<<setprecision(2)<<sh[i]->Area()<<endl;
        }

//        cout<<setiosflags(ios::fixed)<<setprecision(2)
//        <<c.area;
    //    s[1] = Circle(cr);
    //    cout<<s[1].Area();
    }

    return 0;
}





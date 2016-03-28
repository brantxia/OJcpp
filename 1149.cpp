#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    double x,y;
public:
    Point()
    {
        x=0;y=0;
    }
    Point(double x_value,double y_value)
    {
        x = x_value;
        y = y_value;
    }
    double getX()
    {
        return x;
    }
    double getY()
    {
        return y;
    }
    void setXY(double x1,double y1)
    {
        x = x1;
        y = y1;
    }
    void setX(double x_value)
    {
        x = x_value;
    }
    void setY(double y_value)
    {
        y = y_value;
    }
    double getDisTo(Point &p)
    {
        return sqrt(pow(x-p.getX(),2)+pow(y-p.getY(),2));
    }
//    ~Point();
};

class Circle
{
    Point centre;
    double radius;
public:
    Circle()
    {
        radius = 1;
        centre.setXY(0,0);
    }
//    ~Circle();
    Circle(double x,double y,double r)
    {
        centre.setXY(x,y);
        radius = r;
    }
    double getArea()
    {
        return 3.14*radius*radius;
    }
    void moveCentreTo(double x1,double y1)
    {
        centre.setXY(x1,y1);
    }
    int contain(Point &p)
    {
        if (centre.getDisTo(p)<=radius) {
            return 1;
        }
        else
            return 0;
    }
};

int main()
{

    double x,y,r;
    cin>>x>>y>>r;
    Circle circle(x,y,r);

    int n;
    cin>>n;
    double nx[n],ny[n];
    for (int i = 0; i < n; ++i) {
        cin>>nx[i]>>ny[i];
        Point point1(nx[i],ny[i]);
        if (circle.contain(point1)) {
            cout<<"inside"<<endl;
        }
        else
            cout<<"outside"<<endl;
    }


    cout<<"after move the centre of circle:"<<endl;
    double mx,my;
    cin>>mx>>my;
    circle.moveCentreTo(mx,my);
    for (int i = 0; i < n; ++i) {

        Point point2(nx[i],ny[i]);
        if (circle.contain(point2)) {
            cout<<"inside"<<endl;
        }
        else
            cout<<"outside"<<endl;
    }

    return 0;
}


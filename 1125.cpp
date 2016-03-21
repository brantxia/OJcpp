#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <memory>
#include <iomanip>
using namespace std;

class Point
{
    double x,y;
public:
    Point()
    {
        x=0,y=0;
    };
    Point(double x_value,double y_value)
    {
        x = x_value;
        y = y_value;
    };
    double getX();
    double getY();
    void setX(double x_value);
    void setY(double y_value);
    double distanceToAnotherPoint(Point p);
};

double Point::getX()
{
    return x;
}
double Point::getY()
{
    return y;
}
void Point::setX(double x_value)
{
    x = x_value;
}
void Point::setY(double y_value)
{
    y = y_value;
}

double Point::distanceToAnotherPoint(Point p)
{
    double x1 = getX();
    double y1 = getY();
    double x2 = p.getX();
    double y2 = p.getY();
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

int main()
{
    int t;
    cin>>t;
    for (int var = 0; var < t; ++var) {
        double p1[2];
        double p2[2];
        for (int i = 0; i < 2; ++i) {
            cin>>p1[i];
        }
        for (int i = 0; i < 2; ++i) {
            cin>>p2[i];
        }
        Point pa(p1[0],p1[1]);
        Point pb(p2[0],p2[1]);

        cout<<"Distance of Point("
           <<setiosflags(ios::fixed)<<setprecision(2)<<p1[0]<<","<<p1[1]
          <<") to Point("
         <<p2[0]<<","<<p2[1]
         <<") is ";
//        cout<<setiosflags(ios::fixed);
        cout<<pa.distanceToAnotherPoint(pb)<<endl;

    }


    return 0;
}

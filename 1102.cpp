#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class C2D
{
public:
	double x,y;
	
	C2D()
	{}
	C2D(double tx,double ty):
	x(tx),y(ty)
	{}
	
	~C2D(){}
	double getDistance(double x1,double y1)
	{
		return sqrt(pow(x-x1,2)+pow(y-y1,2));
	}
};

class C3D:public C2D
{
public:
	double z;
	C3D()
	{}
	C3D(double tx,double ty,double tz):
	z(tz),C2D(tx,ty)
	{}
	~C3D(){}
	double getDistance(double x1,double y1,double z1)
	{
		return sqrt(pow(x-x1,2)+pow(y-y1,2)+pow(z-z1,2));
	}
};


int main()
{
	double x1,y1;
	cin>>x1>>y1;
	C2D p1(x1,y1);
	
	double x2,y2,z2;
	cin>>x2>>y2>>z2;
	C3D p2(x2,y2,z2);
	
	double x3,y3,z3;
	cin>>x3>>y3>>z3;
	C3D p3(x3,y3,z3);
	
	cout<<p1.getDistance(0,0)<<endl;
	cout<<p2.getDistance(0,0,0)<<endl;
	cout<<p3.getDistance(0,0,0)<<endl;
	
	C2D p4(p3.x,p3.y);
	cout<<p4.getDistance(0,0)<<endl;
	return 0;
}
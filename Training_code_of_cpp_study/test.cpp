#include<iostream>
#include<string>
using namespace std;
const double pi = 3.14;
 
class Circle
{
public:
	Circle(double r) 
	{
		radius = r;
	}
	virtual void area() {};
	virtual void volume() {};
protected:
	double radius;
};
 
class Sphere: public Circle			//球体
{
public:
	Sphere(double r) :Circle(r) {}
	void area();
	void volume();
 
};
void Sphere::area()
{
	double a = 4.0*pi*radius*radius;
	cout << "球体的面积为：" << a << "平方米" << endl;
}
void Sphere::volume()
{
	double v = 4.0 / 3.0*pi*radius*radius*radius;
	cout << "球体的体积为：" << v << "立方米" << endl;
}
 
class Column: public Circle			//圆柱体
{
public:
	Column(double r, double h) :Circle(r) { height = h; }
	void area();
	void volume();
protected:
	double height;
};
void Column::area()
{
	double a = 2.0*pi*radius*(height+radius);
	cout << "圆柱体的面积为：" << a << "平方米" << endl;
}
void Column::volume()
{
	double v = pi*radius*radius*height;
	cout << "圆柱体的体积为：" << v << "立方米" << endl;
}
 
int main()
{
	Sphere s(5.0);
	Column c(1.0, 6.0);
	
	s.area();		
	s.volume();
 
	c.area();
	c.volume();
 
	system("pause");
	return 0;
}

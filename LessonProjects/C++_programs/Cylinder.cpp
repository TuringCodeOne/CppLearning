#include<iostream>
using namespace std;

class Round
{
private:
	double radius;
	const double PI;
public:
	Round(double radius = 0) :PI(3.14) {}
	void setRadius(double r);
	void showRad();
	double getGirth();
	double getArea();
};

void Round::setRadius(double r)
{
	radius = r;
}

void Round::showRad()
{
	cout << "radius: " << radius << endl;
}

double Round::getGirth()
{
	cout << "Girth: " << 2 * PI*radius << endl;
	return(2 * PI*radius);
}

double Round::getArea()
{
	cout << "Area: " << PI * radius*radius << endl;
	return(PI*radius*radius);
}


class Cylinder
{
private:
	Round area;
	double height;
public:
	Cylinder(Round area = 0, double height = 0) {}
	void getVol();
	void getHeight();
	void getSurface();
	void setHeight(double h);
	void setR(double r);
};


void Cylinder::getVol()
{
	cout << "volume: " << area.getArea()*height << endl;
}

void Cylinder::getSurface()
{
	cout << "Surface area: " << area.getGirth()*height + area.getArea() * 2 << endl;
}

void Cylinder::setHeight(double h)
{
	height = h;
}

void Cylinder::getHeight()
{
	cout << "Height: " << height << endl;
}

void Cylinder::setR(double r)
{
	area.setRadius(r);
}

int main()
{
	Cylinder v;
	v.setHeight(5);
	v.setR(2);
	v.getHeight();
	v.getSurface();
	v.getVol();
	return 0;
}
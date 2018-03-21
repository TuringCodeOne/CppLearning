#include<iostream>
#include"Tectangle.h"
using namespace std;

int main()
{
	Rectangle angle1;
	Rectangle angle2=angle1;
	angle1.GetAll();
	angle2.GetAll();
	angle1.SetLeft(2);
	angle1.SetBottom(4);
	angle2.SetRight(8);
	angle2.SetBottom(5);
	angle1.GetAll();
	angle2.GetAll();
	return 0;
}
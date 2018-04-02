#include<iostream>
using namespace std;
#include<string>
class Student
{
private:
	string name;
	string num;
	int point;
	
public:
	Student(){}
	void SetName();
	void SetNum();
	void SetPoint();
	void getAll();
	int getPoint();
	
};

void Student::SetName()
{
	cin >> name;
}

void Student::SetNum()
{
	cin >> num;
}

void Student::SetPoint()
{
	cin >> point;
}

int Student::getPoint()
{
	return point;
}

void Student::getAll()
{
	cout << "Name: " << name << '\t'<<'\t';
	cout << "Number: " << num << '\t';
	cout << "Point: " << point << endl;
}
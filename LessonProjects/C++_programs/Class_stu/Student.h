#include<iostream>
#include<string>
using namespace std;

class Student 
{
private:
	string name;
	string num;
	int age;
public:
	Student();
	Student(string name, string num, int age);
	void modify_name(string name);
	void modify_num(string num);
	void modify_age(int age);
	void get_info();
};

Student::Student()
{
	cout << "Please input the name number and age of a new student: " << endl;
}

Student::Student(string a, string b, int c)
{
	name = a;
	num = b;
	age = c;
}

void Student::modify_age(int a) { age = a; }
void Student::modify_num(string a) { num = a; }
void Student::modify_name(string a) { name = a; }


void Student::get_info()
{
	cout << "Name: " << name << '\t' << "Number: " << num << '\t' << "Age: " << age << endl;
}

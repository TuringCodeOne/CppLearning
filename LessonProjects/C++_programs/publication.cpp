#include<iostream>
#include<string>
using namespace std;

class Publication
{
private:
	string title;
	string name;
	double price;
	string date;
public:
	Publication(string title, string name, double price, string date)
	{
		this->title = title;
		this->name = name;
		this->price = price;
		this->date = date;
	}
	void inputData()
	{
		cout << "Title: ";
		cin >> title;
		cout << "\t"<<"Name: ";
		cin >> name;
		cout << "\t" << "Price: ";
		cin >> price;
		cout << "\t" << "Date: ";
		cin >> date;
	}
	void display()
	{
		cout << "Title: " << title<<"\t";
		cout << "Name: " << name << "\t";
		cout << "Price: " << price << "\t";
		cout << "Date: " << date << "\t";
	}
	
};

class Book :public Publication
{
private:
	int page;
public:
	Book(string t, string n, double p, string d, int page) :Publication(t, n, p, d)
	{
		this->page = page;
	}
	void inputData() 
	{ 
		cout << "Page: ";
		cin >> page;
	}
	void display() 
	{
		Publication::display();
		cout << "Page: " << page << endl;
	}
};

class Tape :public Publication
{
private:
	double playTime;
public:
	Tape(string t, string n, double p, string d, double playTime):Publication(t,n,p,d)
	{
		this->playTime = playTime;
	}
	void inputData() 
	{
		cout << "PlayTime: ";
		cin >> playTime;
	}
	void display() {
		Publication::display();
		cout << "PlayTime: " << playTime << endl;
	}
};

int main()
{
	Publication A("Science","IT",899,"2018-05-07");
	Book B("Science", "IT", 899, "2018-05-07", 375);
	Tape T("Science", "IT", 899, "2018-05-07", 600);

	A.display();
	cout << endl;
	B.display();
	T.display();


	return 0;
}
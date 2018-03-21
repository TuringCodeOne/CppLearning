#include<iostream>
using namespace std;

class Rectangle
{
private:
	int left, top;
	int right, bottom;
public:
	Rectangle(int l = 0, int t = 0, int r = 0, int b = 0); 
	
	~Rectangle() {};
	void Assign(int l, int t, int r, int b);
	void SetLeft(int t);
	void SetRight(int t);
	void SetTop(int t);
	void SetBottom(int t);
	int GetLeft();
	int GetRight();
	int GetBottom();
	int GetTop();
	void GetAll();
};


Rectangle::Rectangle(int l , int t , int r , int b)
{
	if (l == r)
	{
		left = l;
		right = r;
	}
	if (b == t)
	{
		top = t;
		bottom = b;
	}
}; 

void Rectangle::Assign(int l, int t, int r, int b)
{
	if(l==r)
	{
		left = l;
		right = r;

	}
	if(b==t)
	{
		top = t;
		bottom = b;
	}
		
}

void Rectangle::SetLeft(int t)
{
	left = right = t;
}

void Rectangle::SetRight(int t)
{
	left = right = t;
}

void Rectangle::SetTop(int t)
{
	top = bottom = t;
}

void Rectangle::SetBottom(int t)
{
	top = bottom = t;
}

void Rectangle::GetAll()
{
	
	cout << "Right: " << right << '\t';
	cout << "Left: " << left << '\t' <<'\t';
	cout << "Bottom: " << bottom << '\t';
	cout << "Top: " << top << endl;
}

int Rectangle::GetLeft()
{
	cout << "Left: " << left << endl;
	return left;
}

int Rectangle::GetRight()
{
	cout << "Right: " << right << endl;
	return right;
}

int Rectangle::GetTop()
{
	cout << "Top: " << top << endl;
	return top;
}

int Rectangle::GetBottom()
{
	cout << "Bottom: " << bottom << endl;
	return bottom;
}

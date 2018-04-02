#include<iostream>
#include"Student.h"
using namespace std;

int main()
{
	int n,j,i,k;
	Student temp;
	cout << "Please input the amount of student: ";
	cin >> n;
	Student *ptr = new Student[n];
	if (ptr == NULL)	
		return 0;
	for ( i = 0; i < n; i++)
	{
		cout << "Please input the name number and point of the student "<<i+1<<": ";
		ptr[i].SetName();
		ptr[i].SetNum();
		ptr[i].SetPoint();
	}
	
	for (int i = 0; i < n; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (ptr[j].getPoint() > ptr[k].getPoint())
				k = j;
		}
		if (i != k)
		{
			temp = ptr[i];
			ptr[i] = ptr[k];
			ptr[k]= temp;
		}
	}

	for (i = 0; i < n; i++)
	{
		ptr[i].getAll();
	}

	delete[]ptr;
	ptr = NULL;

	
	return 0;
}
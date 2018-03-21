#include<iostream>
using namespace std;
int main()
{
	int y;
	cin >> y;
	if (y% 4!= 0)  cout << y << "  is not a leap year" << endl;
	else {
		if (y % 100 != 0)  cout << y << "  is a leap year" << endl;
		else {
			if (y % 400 != 0) cout << y << "  is not a leap year" << endl;
			else cout << y << "  is a leap year" << endl;
			system("pause");
			return 0;
		}
	}
}

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	float x, y;
	cin >> x;
	if (x < 0) y = 4 * x + 3;
	else {
		if (( x >=0&&x<=2)==true) y = x + 3;
		else if (x > 2) y = -x + 5;
	}
	cout << "x=" << setiosflags(ios::fixed) <<setprecision(2)<< x << "," << "y=" << setiosflags(ios::fixed)<<setprecision(2)<< y << endl;
	system("pause");
	return 0;
}

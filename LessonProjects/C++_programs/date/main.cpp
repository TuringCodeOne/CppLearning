#include<iostream>
#include"Date.h"
using namespace std;
namespace AIDEN {
	const int Date::days_in_mouths[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	void Date::check() {
		if (year < 1 || mouth < 1 || day < 1) {
			cout << "\nwrong date,set to 2009.1.1";
			year = 2009; mouth = 1; day = 1;
		}
		while (day > days_in_mouths[(mouth  - 1)%12]) {
			day -= days_in_mouths[(mouth - 1) % 12 ];
			mouth++;
		}
		while (mouth > 12) {
			mouth -= 12;
			year++;
		}
	}
	void Date::set_date() {
		cout << "\nplease select:\n1.year\n2.mouth\n3.day\n4.all\nelse. quit";
		int mode, y, m, d;
		cin >> mode;
		switch (mode)
		{
		case 1:
			cin >> y;
			year = y;
			break;
		case 2:
			cin >> m;
			mouth = m;
			break;
		case 3:
			cin >> d;
			day = d;
			break;
		case 4:
			cin >> y >> m >> d;
			break;
		default:
			cout << "\nbye";
			return;
		}
		check();
	}
}
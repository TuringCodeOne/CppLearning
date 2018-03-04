//Deduce_date.cpp -- output Gauss issues date
#include<iostream>
using namespace std;

void pri_date(int days,int year,bool boolean)                       //定义一个函数用于计算并输出日期
{
	int clan[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };         //一维数组表示12个月每个月的天数
	int  b, i;
	if (boolean) {                                                  //用于计算闰年的二月
		clan[2] = 29;
		b = days - 730;
	}
	else {
		if (days <= 730) {
			 b=days%365;
			year = days/365+1+year;
		}
		else {
			year += 4;
			b = days - 1096;
		}
	}
	for (i = 0; i < 12; i++)                                      //确定月和日
	{
		if (b > clan[i]) b -= clan[i];
		else
		{
			cout << "Date is: ";
			cout << year << "-" << ++i << "-" << b << endl;
			break;
		}
	}
}

int main()
{
	int day_num;
	int year_num=1777;
	int left_day;
	
	cout << "Please input day number: ";
	cin >> day_num;
	
	if (day_num <= 245) {
		day_num += 120;
		pri_date(year_num, day_num, false);
	}
	else day_num -= 245;
	
	year_num += 4*(day_num / 1456);                   //包括闰年，四年算作一个周期
	left_day = day_num % 1456;                        //得出剩余一个周期的天数
	
	if (left_day > 730 && left_day<=1096)              //由原始时间周期确定每个四年中，第三年为闰年，此为判断剩余天数是否处于闰年
	{
		year_num += 3;
		pri_date(left_day, year_num,true);
	}
	else
	{
		pri_date(left_day, year_num, false);
	}
	return 0;
}

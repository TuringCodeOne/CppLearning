#include<stdio.h>
#include<stdbool.h>
bool symm(long n)   //求回文数
{
	long i = n, m = 0;
	while (i)
	{
		m = m * 10 + i % 10;
		i = i / 10;
	}
	return(m == n);
}
void main()
{
	bool symm(long n);
	long m;
	for (m = 11; m < 1000; m++)
		if (symm(m) && symm(m*m) &&symm(m*m*m))
			printf("m=%d  ", m);
}

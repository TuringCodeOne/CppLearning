#include<stdio.h>
long fac(int n)
{
	long f;
	if (n == 0 || n == 1)
		f = 1;
	else
		f = fac(n - 1)*n;
	return(f);
}
void main()
{
	int n;
	long y;
	printf("input a integer number:");
	scanf_s("%d", &n);
	y = fac(n);
	printf("n!=%ld \n", y);
}

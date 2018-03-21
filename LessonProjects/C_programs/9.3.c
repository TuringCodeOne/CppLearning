#include<stdio.h>
int Fib(int n)
{
	int f;
	if (n == 0)
		f = 0;
	else if (n == 1)
		f = 1;
	else f = Fib(n - 1) + Fib(n - 2);
	return f;
}

void main()
{
	int n, s,i=0;
	scanf_s("%d", &n);
	do {
		s = Fib(i);
		i++;
	} while (n > s);
	printf("%d", s);
}
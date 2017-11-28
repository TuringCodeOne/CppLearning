#include<stdio.h>
int A(int n)
{
	int a;
	if (n == 1)
		a = 1;
	else if (n == 2)
		a = 2;
	else a = n* A(n - 1) + (n - 1)* A(n - 2);
	return (a);
}

void main()
{
	int n, s, i, sum=0;
	printf("请输入打印项数");
		scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		s = A(i);
		printf("%d\n", s);
		sum = sum + s;
	}
	printf("%d", sum);
}
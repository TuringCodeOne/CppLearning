#include<stdio.h>
#include<math.h>
double addsum(int n)
{
	int i, j;
	double sum = 0;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= i; j++)
			sum = sum + sqrt(j);
	return(sum);
}
void main()
{
	int n;
	double sum;
	printf("请输入一个整数 ");
	scanf_s("%d", &n);
	sum = addsum(n);
	printf("%lf", sum);
}

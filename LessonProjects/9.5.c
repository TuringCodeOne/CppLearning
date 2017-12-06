#include<stdio.h>
int CoutPrime(int xx[], int m)
{
	int i, j = 0, n;
	for (n = 2; n < m; n++)
	{
		for (i = 2; i <= n; i++)
		if (n%i == 0) break;
		if (i!=n)  xx[j++] = n;
	}
	return(j);
}

void main()
{
	int xx[99], m, i;
	printf("请输入大一1的整数 ");
	scanf_s("%d", &m);
	for (i = 0; i < CoutPrime(xx, m); i++)
		printf("%d ", xx[i]);
}

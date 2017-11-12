#include<stdio.h>
void main()
{
	int a[10], i;
	for (i = 0; i <= 9; i++)
		a[i] = i;
	for (i = 9; i >= 0; i--)
		printf("%d", a[i]);
	printf("\n");
}




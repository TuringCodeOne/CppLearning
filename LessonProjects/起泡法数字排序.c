#include<stdio.h>
void main()
{
	int a[10];
	int i, j, k;
	printf("请输入10个整数\n");
	for (i = 0; i < 10; i++)
		scanf_s("%d", &a[i]);
	printf("\n");
	for (j = 0; j < 9; j++)
		for (i = 0; i < 9 - j; i++)
			if (a[i] > a[i + 1])
			{
				k = a[i];
				a[i] = a[i + 1];
				a[i + 1] = k;
			}
	printf("从小到大的排列顺序是  ");
		for(i = 0; i < 10; i++)
		printf("%5d", a[i]);
	printf("\n");
	printf("从大到小的排列顺序是  ");
	for (i = 9; i >= 0; i--)
		printf("%5d", a[i]);
	printf("\n");
}




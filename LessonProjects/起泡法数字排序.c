#include<stdio.h>
void main()
{
	int a[10];
	int i, j, k;
	printf("������10������\n");
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
	printf("��С���������˳����  ");
		for(i = 0; i < 10; i++)
		printf("%5d", a[i]);
	printf("\n");
	printf("�Ӵ�С������˳����  ");
	for (i = 9; i >= 0; i--)
		printf("%5d", a[i]);
	printf("\n");
}




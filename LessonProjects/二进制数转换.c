#include<stdio.h>
#include<math.h>
int a[32];
void main()
{

	int n,x, i = 0;
	printf("请输入一个整数  ");
		scanf_s("%d", &n);
	x = abs(n);
	do
	{
		a[i] = x % 2;
		x = x / 2;
		i++;
	} while (x != 0);
	i--;
	printf("它的二进制数为  ");
	if (n < 0) printf("-");
	for (; i >= 0; i--)
     printf("%d", a[i]);
	printf("\n");
}

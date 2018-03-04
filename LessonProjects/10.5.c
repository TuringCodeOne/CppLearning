#include<iostream
int fun(int x, int *pp)
{
	int t;
	for (int i = 1; i <= x; i += 2)
		if (x%i == 0)
		{
			*pp = i;
			pp++;
			t++;
		}
	return(t);
}
int main()
{
	int a, array[99] = { 0 };
	printf("Please input a integer: ");
	scanf("%d", a);
	for (int i = 0; i < fun(a, array); i++)
		printf("%d", array[i]);
	return 0;
}

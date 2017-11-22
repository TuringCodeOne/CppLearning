#include<stdio.h>
void move(int n, char x, char y)
{
	printf("%d:%c-->%c\n", n, x, y);
}
void hanoi(int n, char A, char B, char C)
{
	if (n == 1)
		move(1, A, C);
	else {
		hanoi(n - 1, A, C, B);
		move(n, A, C);
		hanoi(n - 1, B, A, C);
	}
}

void main()
{
	int num;
	printf("input the number of diskes \n");
	scanf_s("%d", &num);
	hanoi(num, 'A', 'B', 'C');            //A,B,C分别代表三根柱子
}

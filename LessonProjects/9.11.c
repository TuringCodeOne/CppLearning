#include<stdio.h>
double person_average
double lesson_average
int Highest_Greade


int main()
{
	
	
	char StudentName[5][20], lesson[3][20];
	int Grades[5][3],i,j,a,b,c,n;
		printf("请先输入5个学生的姓名，再一次输入没人的三门课成绩\n");
		get_s(StudentName);
		get_s(lesson);
		for (i = 0; i < 5; i++)
			for (j = 0; j < 3; j++)
				scanf_s("%d", &Grades[i][j]);
		for (i = 0; i < 5; i++)
		{
			a = person_average(Grades, i);
			printf("%s",StudentName[i] );
			printf("%d", a);
	     }
		for (i = 0; i < 3; i++)
		{
			b =lesson_average(Grades, i);
			printf("%s", lesson[i]);
			printf("%d", b);
		}


double person_average(int Grades[][3],int x)
{
	int i,sum=0;
	for (i = 0; i < 3; i++)
		sum = sum + Grades[x][i];
	return(sum / 3.0);
}

double lesson_average(int Grades[][3], int x)
{
	int i, sum = 0;
	for (i = 0; i < 5; i++)
		sum = sum + Grades[i][x];
	return(sum / 3.0);
}

int Highest_Greade(int Grades[][3])
{
	int i, j, a = 0;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 3; j++)
			if (a < Grades[i][j]) a = Grades[i][j];
	return(a);
}




double variance(double x)
{
	int y;
	y=
}
#include<stdio.h>
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

int main()
{
	   int Grades[5][3],i,j,max=0,student[5],lesson[5],m=0;
	   double average[5],a,b,variance;
	   printf("请依次输入5名学生的3门课程分数\n");
		for (i = 0; i < 5; i++)
			for (j = 0; j < 3; j++)
				scanf_s("%d", &Grades[i][j]);
		printf("\n");
		
		for (i = 0; i < 5; i++)                     //计算每个学生平均分
		{
			average[i]=person_average(Grades, i);
			printf("学生%d平均分 %0.2lf\n", i+1,average[i]);
	     }
         printf("\n");
		
		 for (i = 0; i < 3; i++)                     //计算每门课的平均分
		{
			b =lesson_average(Grades, i);
			printf("课程%d平均分 %0.2lf\n",i+1, b);
		}
        printf("\n");
		
		for(i=0;i<5;i++)                      //找出所有50个分数中的最高分数对应的学生和课程
			for(j=0;j<3;j++)
				if(max<=Grades[i][j])  max=Grades[i][j];
         for(i=0;i<5;i++)                      
			for(j=0;j<3;j++)
			{
			     if(Grades[i][j]==max)
				 { 
					 student[m]=i+1;
				    lesson[m]=j+1;
					m++;
				 }
			
			}
				printf("所有15个分数中最高分数是\n");
				for(i=0;i<m;i++)
					printf("    学生 %d 的课程 %d，分数为 %d\n",student[i],lesson[i],max);
          printf("\n");
         
		  for(i=0,b=0,a=0;i<5;i++)                            //求5个学生的平均分方差
		 {
			 b=b+average[i]* average[i]; 
		      a=a+average[i];
			 variance=b/5+(a/5)*(a/5);
		 }
			 printf("平均分方差为 %0.2lf\n",variance);
			 return 0;
}

/************************************************/
/**		双向冒泡排序         **/
/************************************************/

#include<stdio.h>

#define MAX  5

/*    输出函数     */
void show(int arr[],int n)
{
	for(int i=0;i<n;i++){
		printf("%d",arr[i]);
	}
	printf("\n");
}


/*     交换函数      */
void temp(int *backup1,int *backup2)
{
	int i;
	i=*backup1;
	*backup1=*backup2;
	*backup2=i;
}


/**    排序函数     **/
void sort(int arr[],int n)
{
	int low,high,flag,i;
	low=0;
	high=n-1;

	while(low<high){
		flag=0;
		
		for(i=low;i<high;i++){
			if(arr[i]>arr[i+1])
				temp(&arr[i],&arr[i+1]);
			flag++;
		}
	
	high--;
	
	if(!flag)
		break;
	}

	for(i=high;i>low;i--){
		if(arr[i]<arr[i-1])
			temp(&arr[i],&arr[i-1]);
	}

	low++;
}


	
int main()
{
	int arr_test[MAX]={4,3,2,1,6};

	show(arr_test,MAX);

	sort(arr_test,MAX);

	show(arr_test,MAX);
	
	return 0;
}

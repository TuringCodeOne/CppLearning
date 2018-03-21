#include<stdio.h>
#include<string.h>
void main()
{
	char str[100],b[50];
	int n,j=0,i,s=0;
	gets(str);
    n=strlen(str);
    for(i=0;i<n-1;i++)
	{
	     if(str[i]!=str[i+1]) 
         {
		     b[j]=str[i];
		     j++;
	     }
		 else {
			 s++;
			 continue;
	    }
	}
	b[j]='\0';
	puts(b);
	printf("Delete the number of characters:");
	printf("%d",s);
}

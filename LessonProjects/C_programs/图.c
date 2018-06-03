#include<stdio.h>
#define Maxsize 10
struct Mgraph{
	int vertex[Maxsize];
	int arc[Maxsize][Maxsize];
	int vertexNum,arcNum;
	int visited[Maxsize];
};
void Creadjm(Mgraph *G)
{
	int i,j,k;
	printf("Input vertexNum and arcNum:\n");
	scanf_s("%d%d",&G->vertexNum,&G->arcNum);
	for(k=0;k<G->vertexNum;k++)
	{	
		G->vertex[k]=k+1;
		G->visited[k]=0;
	}
	for(i=0;i<G->vertexNum;i++)
		for(j=0;j<G->vertexNum;j++)
			G->arc[i][j]=0;
	printf("Input %d edges:\n",G->arcNum);
	for(k=0;k<G->arcNum;k++)
	{
		scanf_s("%d%d",&i,&j);
		G->arc[i-1][j-1]=1;
		G->arc[j-1][i-1]=1;
	}
}
void dfs(Mgraph *G,int v)
{
	int j,count=0;
	printf("%d",G->vertex[v]);
	G->visited[v]=1;
	for(j=0;j<G->vertexNum;j++)
	{
		if(G->arc[v][j]==1&&G->visited[j]==0)
			dfs(G,j);
	}
}
void bfs(Mgraph *G,int v)
{
	int Q[Maxsize]={0};
	int front=-1,rear=-1,j;
	printf("%d",G->vertex[v]);
	G->visited[v]=1;
	Q[++rear]=v;
	while(front!=rear)
	{
		v=Q[++front];
		for(j=0;j<vertexNum;j++)
		{	
			if(arc[v][j]==1&&visited[j]==0)
			{
				printf("%d",G->vertex[j]);
				G->visited[j]=1;
				Q[++rear]==j;
			}
		}
	}
}
void count(Mgraph *G)
{
	int i,count=0;
	for(i=0;i<G->vertexNum;i++)
	{
		if(G->visited[i]==0)
		{	
			count++;
			bfs(G,i);
		}
	}
	if(count==1)
		printf("连通\n");
	else
		printf("有%d个连通分量\n",count);
}
int main()
{
	Mgraph M;
	Creadjm(&M);
	count(&M);
	return 0;
}

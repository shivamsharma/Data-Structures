#include <stdio.h>
void dfs_visit(int E[][100],int time,int in[],int out[],char color[],int parent[],int n,int index)
{
	int i,temp;
	time++;
	in[index]=time;
	color[index]='y';
	for(i=0;i<n;i++)
	{
		if(color[i]=='w'&&E[index][i]!=0)
		{
			parent[i]=index;
			temp=index;
			index=i;
			dfs_visit(E,time,in,out,color,parent,n,index);
		}
		color[temp]='r';
		time++;
		out[temp]=time;
	}
}

void dfs(int E[][100],int time,int in[],int out[],char color[],int parent[],int n)
{
	int i,j;
	for(i=0;i<n;i++)	//for each vertex u belongs to V[G]
	{
		color[i]='w';	//color[u]<---White
		parent[i]=0;	//Parent[u]<---NIL
	}
	time=0;			//time<---0
	for(i=0;i<n;i++)	//for each vertex u belongs to V[G]
	{
		if(color[i]=='w')	//if color[u]==White then
		dfs_visit(E,time,in,out,color,parent,n,i);
	}
}

int main()
{
	int i,j;
	printf("Enter the no. of nodes of graphs:");
	int n;
	scanf("%d",&n);
	char color[n];
	int parent[n],in[n],out[n],time;
	int x;
	int E[n][n];
	printf("Enter the weight of edges in n*n matrice:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		scanf("%d",&E[n][n]);
	}
	printf("Enter the element to be search:\n");
	scanf("%d",&x);
	dfs(E,time,in,out,color,parent,n);
}

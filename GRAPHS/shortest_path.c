#include <stdio.h>
//Weight sum should not exceed 99998
void intialize(int *V,int n)
{
	int i;
	V[0]=0;		//d[s]=0
	for(i=1;i<n;i++)
	V[i]=99998;
}
void sort(int *V,int n)		//EXTRACT-MIN(Q)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(V[i]<V[j])
			{
				int temp;
				temp=V[i];
				V[i]=V[j];
				V[j]=V[i];
			}
		}
	}
}
void relax(int u,int v,int w)
{
	if(v>(u+w))
	{
		v=u+w;
	}
}
int adjacent(int 
void dijkstra(int *V,int E[][],int n)
{
	initialize(V,n);
	while(n!=0)
	{
		
}
int main()
{
	int i,j;
	printf("Enter the no. of nodes of graphs:");
	int n;
	scanf("%d",&n);
	int E[n][n];
	printf("Enter the weight of edges in n*n matrice:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		scanf("%d",E[n][n]);
	}
	int V[n];
}	

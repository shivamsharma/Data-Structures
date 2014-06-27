#include<stdio.h>
#include<stdlib.h>
#define max 100000
int r;
//void printArray(int a[][max],int n);
 
void AdjacencyMatrix(int rel[][2], int a[][max])
{
	a[][max]={0};
    int i,j;
    for(i = 0;i < n; i++)
    {
        for(j = 0;j < i; j++)
        {
        }
    a[i][i] = 0;
    }
}
 
/*void printArray(int a[][max],int n){
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}*/
 
void dfs(int a[][max],int n,int *s,int u,int *q){
 
    int v;
    s[u]=1;
    for(v = 0;v < n; v++)
    {
        if(a[u][v] == 1&&s[v] == 0)
        {
            q[++r] = v;
            dfs(a,n,s,v,q);
        }
    }
}
/*void printdfs(int a[][max],int n,int *q){
    int i,sor,s[max];
    printf("Enter source less than %d: ",n);
    scanf("%d",&sor);
     
    for(i=0;i<n;i++)
    s[i]=0;
     
    q[0]=sor;
    dfs(a,n,s,sor,q);
     
    for(i=0;i<n;i++)
    {
        if(s[i]!=0)
        {
        printf(" -> %d ",q[i]);
        }
    }
}*/
 
int main()
{
    int n,*q;
    q = (int *)malloc(sizeof(int)*n);
    int t,i,j;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int a[n][n];
		int rel[m][2];
		for(j=0;j<m;j++)
		{
			scanf("%d%d",&rel[j][0],&rel[j][1]);
		}
		AdjacencyMatrix(rel,a);
	}
	return 0;
}

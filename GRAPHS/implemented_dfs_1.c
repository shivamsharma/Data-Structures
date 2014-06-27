#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>
#define max 100000

struct edge
{
	int vertexIndex;
	struct edge *edgePtr;
}edge;

struct vertex
{
	int vertexKey;
	int visited;
	struct edge *edgePtr;
}vertex;

void insertVertex(struct vertex *g, int vertexKey, int *vertexCount)
{
	g[*vertexCount].vertexKey=vertexKey;
	g[*vertexCount].edgePtr=NULL;
	g[*vertexCount].visited=0;
	(*vertexCount)++;
}

void insertEdge(struct vertex *g,int vertex1, int vertex2)
{
	struct edge *e,*e1,*e2;
	e=g[vertex1].edgePtr;
	while(e&& e->edgePtr)
	{
		e=e->edgePtr;
	}
	e1=(struct edge *)malloc(sizeof(*e1));
	e1->vertexIndex=vertex2;
	e1->edgePtr=NULL;
	if(e)
	e->edgePtr=e1;
	else
	g[vertex1].edgePtr=e1;
	e=g[vertex2].edgePtr;
	while(e&& e->edgePtr)
	{
		e=e->edgePtr;
	}	
	e2=(struct edge *)malloc(sizeof(*e2));
	e2->vertexIndex=vertex1;
	e2->edgePtr=NULL;
	if(e)
	e->edgePtr=e2;
	else
	g[vertex2].edgePtr=e2;
}

/*void printGraph(struct vertex *g, int *vertexCount)
{
	int i;
	struct edge *e;
	for(i=0;i<*vertexCount;i++)
	{
		printf("%d(%d)",i,g[i].vertexKey);
		e=g[i].edgePtr;
		while(e)
		{
			printf("->%d",e->vertexIndex);
			e=e->edgePtr;
		}
		printf("\n");
	}
}*/

void dfs(struct vertex *g,int vertex1,int count)
{
	g[vertex1].visited=1;
	struct edge *e;
	e=g[vertex1].edgePtr;
	while(e)
	{
		if(!(g[e->vertexIndex].visited))
		dfs(g,e->vertexIndex);
	    e=e->edgePtr;
	}
}

int main()
{
	struct vertex g1[max];
	int vc1=0,count;
	int t;
	scanf("%d",&t);
	int i,j,k;
	for(i=0;i<t;i++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(j=0;j<n;j++)
		insertVertex(g1,j+1,vc1);
		int rel[m][2];
		for(j=0;j<m;j++)
		{
			scanf("%d%d",&rel[j][0],&rel[j][1]);
			insertEdge(g1,rel[j][0],rel[j][1]);
		}
		count=0;
		dfs(g1,1,count);
			
	return 0;
}

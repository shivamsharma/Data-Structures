/*Finding Duplicates Through Trees By Array Implementation*/
#include <stdio.h>
#define SIZE 100
struct nodetype{
	int info;
	int used;
}node[SIZE];

void makeTree(int item)
{
	node[0].info=item;
	node[0].used=1;
	int i;
	for(i=1;i<SIZE;i++)
	node[i].used=0;
}

void setLeft(int p,int item)		//pth element
{
	int q;
	q=2*p+1;			//Position of left son
	if(q>=SIZE)
	printf("\n******Array Overflow******\n");
	else if(node[q].used)
	printf("\n******Invalid Insertion******\n");
	else
	{
		node[q].info=item;
		node[q].used=1;
	}
}

void setRight(int p,int item)
{
	int q;
	q=2*p+2;			//Position of right son
	if(q>=SIZE)
	printf("\n******Array Overflow******\n");
	else if(node[q].used)
	printf("\n******Invalid Insertion******\n");
	else
	{
		node[q].info=item;
		node[q].used=1;
	}
}

int main()
{
	int p,q,n,i;
	printf("This is the program of FINDING DUPLICATES...\n");
	printf("Enter the size of an array having duplicates:");
	scanf("%d",&n);
	int array[n];
	printf("Enter the array...\n");
	for(i=0;i<n;i++)
	scanf("%d",&array[i]);
	makeTree(array[0]);
	i=1;
	while(i<n)
	{
		p=q=0;
		while(q<SIZE && node[q].used && array[i]!=node[p].info)
		{
			p=q;
			if(array[i]<node[p].info)
				q=2*p+1;
			else
				q=2*p+2;
		}
		if(array[i]==node[p].info)
			printf("%d is a duplicate\n",array[i]);
		else if(array[i]<node[p].info)
			setLeft(p,array[i]);
		else
			setRight(p,array[i]);
		i++;
	}
}

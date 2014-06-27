/*DYNAMIC QUEUE PROGRAM*/
/*Here basic condition of queue is that
*the front an rear first start from null
*and front always be with first element
*and rear with last element entered*/
#include <stdio.h>
#include <malloc.h>
#define null 0
typedef struct node{
	int info;
	struct node *next;
}NODE;
typedef struct {
		NODE *front,*rear;
}queue;
/* Getnode will create a new node  */
NODE *getnode()
{
	NODE *p;
	p=(NODE *)malloc(sizeof(NODE));
	return p;
}
/*Can free the node means deallocation */
void freenode(NODE *p)
{
	free((char *)p);	//Typecasting is not necessary
	return;
}
/*It will insert new node after the rear node
*and points the rear to its*
*Position starts from 1st*/
void insert(queue *pq,int item)
{
	NODE *q;
	q=getnode();
	q->info=item;
	q->next=null;
	if(pq->rear==null)
	pq->front=q;
	else
	pq->rear->next=q;
	pq->rear=q;
	return;
}
/*It will delete the front node*/
int delete(queue *pq)
{
	NODE *q;
	int x;
	if(empty_queue(pq))
	{
		printf("\n******Queue Underflow******\n");
		return -1;
	}
	q=pq->front;
	x=q->info;
	pq->front=pq->front->next;
	if(pq->front==null)
	pq->rear=null;
	freenode(q);
	return x;
}
/*Check if queue is empty or not*/
int empty_queue(queue *q)
{
	return (q->front==null?1:0);
}

void display_queue(queue *pq)
{
	NODE *q;
	q=pq->front;
	if(q==null)
	printf("\nEMPTY....\n");
	else
	while(q!=pq->rear->next)
	{
		printf("\t%d\n",q->info);
		q=q->next;
	}
	return;
}

int main(void)
{
	queue Q;
	Q.front=Q.rear=null;
	printf("******This is a Dynamic Queue program of insert and delete******\n");
	int j,e,x;
	while(1)
	{
		printf("\nEnter \'1\' for insert, \'2\' for delete, \'3\' for show queue, \'0\' for exit:");
		scanf("%d",&j);
		switch(j){
			case 0:exit(0);
					break;
			case 1:printf("\nEnter the element to insert in the queue:");
					scanf("%d",&e);
					insert(&Q,e);
					break;
			case 2:x=delete(&Q);
					if(x!=-1)
					printf("\nElement \'%d\' has been deleted from queue\n",x);
					break;
			case 3:printf("\nQueue is :\n");
					display_queue(&Q);
					break;
			default:printf("\nWrong action is taken!!!\n");
					break;
		}
	}
	return 0;
}

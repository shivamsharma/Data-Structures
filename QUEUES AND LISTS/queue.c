//Simple Queue Implementation
/*Here front is one index before front element
*and rear is the index of last element*/
#include <stdio.h>
#define SIZE 6
struct queue{
	int item[SIZE];
	int front,rear;
};

void insert(struct queue *q,int item)
{
	if(q->rear==SIZE-1)
	q->rear=0;
	else q->rear++;
	if(q->rear==q->front)
	{
		/*Making Queue processing smooth means
		*if element not inserted than it go 
		*back rear to it's previous position*/
		if(q->rear==0)				
		q->rear=SIZE-1;
		else
		q->rear--;
		printf("\n******Queue Overflow******");
	}
	else
	q->item[q->rear]=item;
}
int delete(struct queue *q)
{
	if(empty_queue(q))
	{
		printf("\n******Queue Underflow******");
		return -1;
	}
	else if(q->front==SIZE-1)
	q->front=0;
	else q->front++;
	return q->item[q->front];
}

int empty_queue(struct queue *q)
{
	if(q->front==q->rear)
	return 1;
	else
	return 0;
}

void display_queue(struct queue *q)
{
	int i=q->front+1;
	if(q->front==SIZE-1)
	i=0;
	if(empty_queue(q))
	printf("EMPTY...");
	else
	{
		while(i!=q->rear)
		{
			printf("\t%d\n",q->item[i]);
			if(i==SIZE-1)
			i=0;
			else
			i++;
		}
		printf("\t%d\n",q->item[i]);
	}
}

int main()
{
	struct queue q;
	q.front=q.rear=SIZE-1;		//Starting Condition
	printf("******This is a queue program of insert and remove******\n");
	int j,e;
	while(1)
	{
		printf("\nEnter \'1\' for insert, \'2\' for delete, \'3\' for show queue, \'0\' for exit:");
		scanf("%d",&j);
		switch(j){
			case 0:exit(0);
					break;
			case 1:printf("\nEnter the element to insert in the queue:");
					scanf("%d",&e);
					insert(&q,e);
					break;
			case 2:delete(&q);
					if(x!=-1)
					printf("\nElement has been deleted from queue\n");
					break;
			case 3:printf("\nQueue is :\n");
					display_queue(&q);
					break;
			default:printf("\nWrong action is taken!!!\n");
					break;
		}
	}
	return 0;
}

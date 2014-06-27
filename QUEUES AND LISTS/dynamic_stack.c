/*DYNAMIC STACK PROGRAM*/
/*Here basic condition of stack is that
*the top is started at null and always be
*with the last entered element */
#include <stdio.h>
#include <malloc.h>
#define null 0
typedef struct node{
	int info;
	struct node *next;
}NODE;
typedef struct {
	NODE *top;
}stack;
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
	free((char *)p);		//Typecasting is not necessary
}
/*It will push new node at the top of stack*/
void push(stack *s,int item)
{
	NODE *q;
	q=getnode();
	q->info=item;
	if(s->top==null)
	q->next=null;
	else
	q->next=s->top;
	s->top=q;
}
/*It will delete the node at the top*/
int delete(stack *s)
{
	NODE *q;
	int x;
	if(empty_stack(s))
	{
		printf("\n******Stack Underflow******\n");
		return -1;
	}
	q=s->top;
	x=q->info;
	s->top=s->top->next;
	freenode(q);
	return x;
}
/*Check is empty or not when top=null*/
int empty_stack(stack *s)
{
	return (s->top==null?1:0);
}

void display_stack(stack *s)
{
	NODE *q;
	q=s->top;
	if(q==null)
	printf("\nEMPTY....\n");
	else
	while(q!=null)
	{
		printf("\t%d\n",q->info);
		q=q->next;
	}
	return ;
}

int main()
{
	stack s;
	s.top=null;
	printf("******This is a Stack program of push and pop******\n");
	int j,e,x;
	while(1)
	{
		printf("\nEnter \'1\' for push, \'2\' for pop, \'3\' for show stack, \'0\' for exit:");
		scanf("%d",&j);
		switch(j){
			case 0:exit(0);
					break;
			case 1:printf("\nEnter the element to push in the stack:");
					scanf("%d",&e);
					push(&s,e);
					break;
			case 2:x=delete(&s);
					if(x!=-1)
					printf("\nElement \'%d\' has been poped from stack\n",x);
					break;
			case 3:printf("\nStack is :\n");
					display_stack(&s);
					break;
			default:printf("\nWrong action is taken!!!\n");
					break;
		}
	}
	return 0;
}

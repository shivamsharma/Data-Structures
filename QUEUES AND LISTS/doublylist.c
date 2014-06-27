/*DOUBLY LINKED LIST*/
#include <stdio.h>
#define null 0
typedef struct node{
	int info;
	struct node *next;
	struct node *prev;
}NODE;
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
	return ;
}
/* Insert at the front of list */
void insert(NODE *p,int item)
{
	if(p==null)
	{
		printf("\n******Void Insertion******\n");
		return ;
	}
	NODE *q;
	q=getnode();
	q->info=item;
	q->next=p->next;
	p->next=q;
	q->prev=p;
}
/*Delete the front element if there is only
* 1 element then it will not deleted bcoz
* of line q->next->prev which is not any
*allocated space */
int delete(NODE *p)
{
	if(p==null||p->prev==null)
	{
		printf("\n******Void Deletion******\n");
		return -1;
	}
	int item=p->info;
	NODE *q;
	q=p;
	q->prev->next=q->next;
	q->next->prev=q->prev;
	freenode(p);
	return item;
}

void display_list(NODE *head)
{
	NODE *q;
	q=head->next;
	if(q==null)
	printf("\nEMPTY...");
	while(q!=null)
	{
		printf("%d->",q->info);
		q=q->next;
	}
}

int main()
{
	NODE *head,*p;
	head=(NODE *)malloc(sizeof(NODE));
	head->info=0;
	head->next=head->prev=null;
	p=head;
	printf("******This is a Doubly Linked List program of insert and delete******\n");
	int j,e,pos,x;
	while(1)
	{
		printf("\nEnter \'1\' for insert, \'2\' for delete, \'3\' for show list, \'0\' for exit:");
		scanf("%d",&j);
		switch(j){
			case 0:exit(0);
					break;
			case 1:printf("\nEnter the element to insert in the list:");
					scanf("%d",&e);
					insert(p,e);
					break;
			case 2:x=delete(p->next);
					if(x!=-1)
					printf("\nElement has been deleted from list\n");
					break;
			case 3:printf("\nList is :\n");
					display_list(p);
					break;
			default:printf("\nWrong action is taken!!!\n");
					break;
		}
	}
	return 0;
}
/*Tenenbaum Question 4.3.6*/
#include <stdio.h>
#include <malloc.h>
#define null 0
typedef struct node{
	int info;
	struct node *next;
}NODE;
NODE *head,*tail,*p;
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
/* Locate the postion in the linked list */
void locate(int pos)
{
	int i;
	for(i=0;i<=pos;i++)
	{
		if(i==0)
		p=head;
		else
		{
			p=p->next;
		}
	}
	return ;
}
/*It will insert new node after the node at pos
*Position starts from 1st*/
void insert(int item,int pos)
{
	NODE *q;
	if(pos>head->info)
	{
		printf("******Void Insertion******\n");
		return;
	}
	locate(pos);			//Here p is reaching at pos
	q=getnode();
	q->info=item;
	q->next=p->next;
	p->next=q;
	head->info++;
	return ;
}
/*It will delete the node p at position pos*/
int delete(int pos)
{
	NODE *q;
	int x;
	if(pos>=head->info)
	{
		printf("\n******Void Deletion******\n");
		return -1;
	}
	locate(pos-1);		//Here p is reaching at pos
	q=p->next;
	x=q->info;
	p->next=p->next->next;
	freenode(q);
	head->info--;
	return x;
}

void display_list(int from ,int to)
{
	NODE *q;
	locate(from);
	q=p;
	locate(to);
	if(p==head)
	printf("\nEMPTY....\n");
	else
	while(q!=p->next)
	{
		printf("%d->",q->info);
		q=q->next;
	}
	return ;
}

int inssub(NODE *head1,int pos1,NODE *head2,int pos2,int len)
{
	if(pos1>head1->info)
	return 0;
	if(pos2+len-1>head2->info)
	return 0;
	if(pos1<1||pos2<1)
	return 0;
	NODE *q,*temp,*temp1,*l;
	head=head2;		//Working with list l2
	locate(pos2);		/*locate1*/
	temp=p;			//List 2 pos2 element
	head=head1;		//Working with list l1
	locate(pos1);		/*locate2*/
	temp1=p->next;
	p->next=temp;
	head=head2;			//Working with list l2
	locate(pos2+len-1);		/*locate3*/
	temp=p;
	p->next=temp1;
	head=head1;
	head->info+=len;
	display_list(1,head->info);
}

int main()
{
	NODE *head1,*tail1,*head2,*tail2;
	/*These are the primary conditions of list*/
	/*Started*/
	head=(NODE *)malloc(sizeof(NODE));
	tail=(NODE *)malloc(sizeof(NODE));
	head->next=tail;
	head->info=0;
	tail->next=null;
	head1=head;
	tail1=tail;
	/*End*/
	printf("\n******Enter list 1st******\n");
	int j,e,pos,x,flag=0;
	while(1)
	{
		if(flag==1)
		break;
		printf("\nEnter \'1\' for insert, \'2\' for delete, \'3\' for show list, \'0\' for break:");
		scanf("%d",&j);
		switch(j){
			case 0:flag=1;
					break;
			case 1:printf("\nEnter the element to insert in the list:");
					scanf("%d",&e);
					printf("\nEnter the position of element after which insertion is to be done:");
					scanf("%d",&pos);
					insert(e,pos);
					break;
			case 2:printf("\nEnter the position of elemented to be deleted:");
					scanf("%d",&pos);
					x=delete(pos);
					if(x!=-1)
					printf("\nElement has been deleted from list\n");
					break;
			case 3:printf("\nList is :\n");
					display_list(1,head->info);
					break;
			default:printf("\nWrong action is taken!!!\n");
					break;
		}
	}
	/*These are the primary conditions of list*/
	/*Started*/
	head=(NODE *)malloc(sizeof(NODE));
	tail=(NODE *)malloc(sizeof(NODE));
	head->next=tail;
	head->info=0;
	tail->next=null;
	head2=head;
	tail2=tail;
	/*End*/
	flag=0;
	printf("\n******Enter list 2nd******\n");
	while(1)
	{
		if(flag==1)
		break;
		printf("\nEnter \'1\' for insert, \'2\' for delete, \'3\' for show list, \'0\' for break:");
		scanf("%d",&j);
		switch(j){
			case 0:flag=1;
					break;
			case 1:printf("\nEnter the element to insert in the list:");
					scanf("%d",&e);
					printf("\nEnter the position of element after which insertion is to be done:");
					scanf("%d",&pos);
					insert(e,pos);
					break;
			case 2:printf("\nEnter the position of elemented to be deleted:");
					scanf("%d",&pos);
					x=delete(pos);
					if(x!=-1)
					printf("\nElement has been deleted from list\n");
					break;
			case 3:printf("\nList is :\n");
					display_list(1,head->info);
					break;
			default:printf("\nWrong action is taken!!!\n");
					break;
		}
	}
	int i1,i2,len;
	printf("\nEnter i1:");
	scanf("%d",&i1);
	printf("\nEnter i2:");
	scanf("%d",&i2);
	printf("\nEnter len:");
	scanf("%d",&len);
	if(inssub(head1,i1,head2,i2,len)==0)
	printf("\n******ERROR******\n");
	return 0;
}

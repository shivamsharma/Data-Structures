/*THIS PROGRAM IS ABOUT ADDING ,SUBTRACTING,
*MULTIPLYING AND DIVIDING LARGE NUMBERS*/
#include <stdio.h>
#include <malloc.h>
#define null 0
#define SIZE 100
typedef struct node{
	int info;
	struct node *next;
}NODE;
NODE *head,*p;
char str[2*SIZE];
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
void chartolist(char *str)
{
	int i,a,b,c,d,e,num,pos=0;
	for(i=strlen(str)-1;i>=0;)
	{
		a=b=c=d=e=0;
		if(i>=0)
		a=str[i--]-'0';
		if(i>=0)
		b=str[i--]-'0';
		if(i>=0)
		c=str[i--]-'0';
		if(i>=0)
		d=str[i--]-'0';
		if(i>=0)
		e=str[i--]-'0';
		num=a+b*10+c*100+d*1000+e*10000;
		insert(num,pos++);
	}
}

void listtochar(char *str)
{
	int n,i=0,num,pos=head->info;
	char a,b,c,d,e;
	locate(pos);
	a=b=c=d=e='0';
	num=p->info;
	a+=num/10000;
	num=num%10000;
	b+=num/1000;
	num=num%1000;
	c+=num/100;
	num=num%100;
	d+=num/10;
	num=num%10;
	e+=num;
	if(a!='0')
	str[i++]=a;
	if(b!='0'||i>0)
	str[i++]=b;
	if(c!='0'||i>0)
	str[i++]=c;
	if(d!='0'||i>0)
	str[i++]=d;
	str[i++]=e;
	pos--;
	while(pos)
	{
		locate(pos);
		a=b=c=d=e='0';
		num=p->info;
		a+=num/10000;
		num=num%10000;
		b+=num/1000;
		num=num%1000;
		c+=num/100;
		num=num%100;
		d+=num/10;
		num=num%10;
		e+=num;
		str[i++]=a;
		str[i++]=b;
		str[i++]=c;
		str[i++]=d;
		str[i++]=e;
		pos--;
	}
	str[i++]='\0';
}

char *add(NODE *head1,NODE *head2)
{
	NODE *p,*q,*r;
	int carry=0,total,sum,pos=0;
	p=head1->next;
	q=head2->next;
	while(p!=null&&q!=null)
	{
		sum=q->info+p->info+carry;
		total=sum%100000;
		carry=sum/100000;
		insert(total,pos++);
		p=p->next;
		q=q->next;
	}
	if(p!=null)
	r=p;
	else r=q;
	while(r!=null)
	{
		sum=r->info+carry;
		total=sum%100000;
		carry=sum/100000;
		insert(total,pos++);
		r=r->next;
	}
	if(carry!=0)
	{
		insert(carry,pos++);
	}
	listtochar(str);
	return str;
}

char *subtract(NODE *head1,NODE *head2)
{
	NODE *p,*q,*r;
	int carry=0,total,sum,pos=0;
	p=head1->next;
	q=head2->next;
	while(p!=null&&q!=null)
	{
		sum=p->info-q->info+carry;
		total=sum;
		carry=0;
		if(sum<0)
		{
			total=100000+sum;
			carry=-1;
		}
		insert(total,pos++);
		p=p->next;
		q=q->next;
	}
	if(p!=null)
	r=p;
	else r=q;
	while(r!=null)
	{
		sum=r->info+carry;
		total=sum;
		carry=0;
		if(sum<0)
		{
			total=100000+sum;
			carry=-1;
		}
		insert(total,pos++);
		r=r->next;
	}
	if(carry!=0)
	{
		insert(carry,pos++);
	}
	listtochar(str);
	return str;
}

char *multiply(NODE *head1,NODE *head2)
{
	NODE *p,*q,*tic,*toc,*temp;
	int carry,total,sum,pos,no=0,i;
	q=head2->next;
	NODE *lhead[head2->info];
	while(q!=null)
	{
		p=head1->next;
		pos=0;
		carry=0;
		head=(NODE *)malloc(sizeof(NODE));
		head->next=null;
		head->info=0;
		lhead[no]=head;
		for(i=0;i<no;i++)
		insert(00000,pos++);
		while(p!=null)
		{
			sum=p->info*q->info+carry;
			total=sum%100000;
			carry=sum/100000;
			insert(total,pos++);
			p=p->next;
		}
		if(carry!=0)
		insert(carry,pos++);
		no++;
		q=q->next;
	}
	/*TECHNIQUE USED FOR OPERATING N LIST
	KNOWN AS TIC TOC TECHNIQUE NAMED BY ME*/
	tic=lhead[0];
	for(i=1;i<no;i++)
	{
		head=(NODE *)malloc(sizeof(NODE));
		head->info=0;
		head->next=null;
		if(i%2==0)
		{
			tic=head;
			temp=toc;
		}
		else
		{
			toc=head;
			temp=tic;
		}
		add(temp,lhead[i]);
	}
	/*TECHNIQUE ENDS HERE*/
	listtochar(str);
	return str;
}

NODE *division(NODE *head1,NODE *head2)
{
}

int main()
{
	NODE *head1,*head2,*head3;
	char str1[SIZE],str2[SIZE],str[2*SIZE];
	printf("Enter the 1st no:");
	scanf("%s",str1);
	printf("Enter the 2nd no:");
	scanf("%s",str2);
	/*These are the primary conditions of list*/
	/*Started*/
	head=(NODE *)malloc(sizeof(NODE));
	head->next=null;
	head->info=0;
	head1=head;
	/*End*/
	chartolist(str1);
	/*These are the primary conditions of list*/
	/*Started*/
	head=(NODE *)malloc(sizeof(NODE));
	head->next=null;
	head->info=0;
	head2=head;
	/*End*/
	chartolist(str2);
	/*MAIN PROGRAM*/
	/*These are the primary conditions of list*/
	/*Started*/
	head=(NODE *)malloc(sizeof(NODE));
	head->next=null;
	head->info=0;
	head3=head;
	/*End*/
	printf("%s\n",subtract(head1,head2));
	return 0;
}

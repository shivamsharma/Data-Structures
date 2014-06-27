//Bashemin Parking Garage Tenenbaum 2.2.8
#include <stdio.h>
#include <string.h>
#define SIZE 10
static int top1=-1;
struct car{
	int license;
	int moved;
};

typedef struct {
	int top;
	struct car c[SIZE];	
}stack;

void in(stack *s,struct car c)
{
    if(full_garage(s))
    printf("\n*****1*Garage is full******\n");
    else
	{
		s->top++;
		s->c[s->top]=c;
	}
}

struct car out(stack *s)
{
    if(empty_garage(s))         
    printf("\n******1Garage is empty******\n");
    else
	return s->c[s->top--];
}

void garage_status(stack *s)			//Displaying current structure of stack
{
	int m;
	if(empty_garage(s))
	{
		printf("\n******EMPTY******\n");
	}
	else
	{
		for(m=s->top;m>=0;m--)
		{
			printf("\t|%d|\n",s->c[m]);
		}
	}
}

int empty_garage(stack *s)
{
	if(s->top==-1)
	return 1;
	else return 0;
}

int full_garage(stack *s)
{
	if(s->top==SIZE-1)
	return 1;
	else return 0;
}

int main()
{
	stack s,s1;
	s.top=-1;
	s1.top=-1;
	struct car temp;
	char ch;
	int l,flag;
	while(1)
	{
		printf("\nEnter \'A\' for Arrival and \'D\' for Departing a car:");
		fflush(stdin);
		scanf("%c",&ch);
		switch(ch){
			case 'A':if(full_garage(&s))
					printf("\n******Garage is full******\n");
					else
					{
						printf("\nThere is a room for car.");
						printf("\nEnter the License No. of car:");
						scanf("%d",&l);
						temp.license=l;
						temp.moved=0;
						printf("hello");
						in(&s,temp);
						garage_status(&s);
						printf("\nYour car has been parked.");
					}
					break;
			case 'D':if(empty_garage(&s))
					printf("\n******Garage is empty******\n");
					else
					{
						printf("\nEnter the license No. of car:");
						scanf("%d",&l);
						while(!empty_garage(&s))
						{
							flag=0;
							temp=out(&s);
							if(l==temp.license)
							{
								flag=1;
								printf("\nYour car is now out of garage");
								printf("\nNo. of Times it moved:%d",temp.moved);
								break;
							}
							temp.moved++;
							in(&s1,temp);
						}
						if(flag==0)
						printf("\nThere is no car of entered License no.");
						while(!empty_garage(&s1))
						{
							in(&s,out(&s1));
						}
					}
					break;
		}
	}
	return 0;
}

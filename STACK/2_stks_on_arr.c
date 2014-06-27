//Exercise 2.2.7 Tenenbaum
#include <stdio.h>
#define SIZE 10
typedef struct{
	int top1;
	int top2;
	int item[SIZE];
}stack;

void push1(stack *s,int item)		//Push a char element in stack
{
	if(s->top1==s->top2-1)
	{
		printf("\n******Stack Overflow******\n");		//If index to of top is greater than array size
	}
	else
	{
		s->top1++;
		s->item[s->top1]=item;
	}
}

int pop1(stack *s)
{
	if(s->top1==-1)
	{
		printf("\n******Stack Underflow******\n");		//If index is at -1 means stack is empty
		return -1;
	}
	else
	{
		s->top1--;
	}
	return s->item[s->top1+1];
}

void push2(stack *s,int item)		//Push a char element in stack
{
	if(s->top2==s->top1+1)
	{
		printf("\n******Stack Overflow******\n");		//If index to of top is greater than array size
	}
	else
	{
		s->top2--;
		s->item[s->top2]=item;
	}
}

int pop2(stack *s)	
{
	if(s->top2==SIZE)
	{
		printf("\n******Stack Underflow******\n");		//If index is at -1 means stack is empty
		return -1;
	}
	else
	{
		s->top2++;
	}
	return s->item[s->top2-1];
}
void display_stack(stack *s)			//Displaying current structure of stack
{
	int m;
	if(s->top1==-1)
	{
		printf("1st Stack Empty");
	}
	else
	{
		for(m=0;m<=s->top1;m++)
		{
			printf("%d->",s->item[m]);
		}
	}
	printf("...");
	if(s->top2==SIZE)
	{
		printf("2nd Stack Empty");
	}
	else
	{
		for(m=s->top2;m<=SIZE-1;m++)
		{
			printf("<-%d",s->item[m]);
		}
	}
}

int main()
{
	stack s;
	s.top1=-1;
	s.top2=SIZE;
	int j,e;
	printf("This is a two stack program on a linear array...\n");
	while(1)
	{
		printf("\nEnter \'1\' for 1st Stack, \'2\' for 2nd Stack and \'3\' for Display Stack:");
		scanf("%d",&j);
		switch(j){
			case 1:printf("\nEnter \'1\' for push, \'2\' for pop:");
					scanf("%d",&j);
					switch(j){
						case 1:printf("\nEnter the element to push in the 1st stack:");
								scanf("%d",&e);
								push1(&s,e);
								break;
						case 2:pop1(&s);
								printf("\nElement has been poped out from 1st stack\n");
								break;
					}
					break;
			case 2:printf("\nEnter \'1\' for push, \'2\' for pop:");
					scanf("%d",&j);
					switch(j){
						case 1:printf("\nEnter the element to push in the 2nd stack:");
								scanf("%d",&e);
								push2(&s,e);
								break;
						case 2:pop2(&s);
								printf("\nElement has been poped out from 2nd stack\n");
								break;
					}
					break;
			case 3:display_stack(&s);
					break;
		}
	}
	return 0;
}

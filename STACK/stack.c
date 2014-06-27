#include <stdio.h>
#define MAX 100
static int top=-1;

struct stack{
	int e;
};

void push(struct stack *s,int e)		//Push a char element in stack
{
	if(top==MAX-1)
	{
		printf("\n******Stack Overflow******\n");		//If index to of top is greater than array size
	}
	else
	{
		top++;
		s[top].e=e;
	}
}

int pop(struct stack *s)					
{
	if(stack_empty(s))
	{
		printf("\n******Stack Underflow******\n");		//If index is at -1 means stack is empty
		return -1;
	}
	else
	{
		top--;
	}
	return s[top+1].e;
}

void display_stack(struct stack *s)			//Displaying current structure of stack
{
	int m;
	if(stack_empty(s))
	{
		printf("******EMPTY******\n");
	}
	else
	{
		for(m=top;m>=0;m--)
		{
			printf("\t|%d|\n",s[m].e);
		}
	}
}

int stack_empty(struct stack *s)				//To check stack is empty or not
{
	if(top==-1)
	return 1;
	else return 0;
}

int main()
{
	struct stack s[MAX];
	int j,e;
	printf("This is a stack program of push and pop\n");
	while(1)
	{
		printf("\nEnter \'1\' for push, \'2\' for pop, \'3\' for show stack, \'0\' for exit:");
		scanf("%d",&j);
		switch(j){
			case 0:exit(0);
					break;
			case 1:printf("\nEnter the element to push in the stack:");
					scanf("%d",&e);
					push(s,e);
					break;
			case 2:pop(s);
					printf("\nElement has been poped out from stack\n");
					break;
			case 3:printf("\nStack is :\n");
					display_stack(s);
					break;
		}
	}
	return 0;
}

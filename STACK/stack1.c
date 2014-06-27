#include <stdio.h>
typedef struct {
                int top;
                int data[100];
                }stack;

void push (stack *s,int item)
{
     if(s->top==99)
     printf("******STACK IS FULL******\n");
     else
	 {
		 s->top++;
		 s->data[s->top]=item;
	 }
}

int pop (stack *s)
{
    if(stack_empty(s))         
    printf("******STACK IS EMPTY******\n");
    else
	return s->top--;
}

void display_stack(stack *s)
{
	int i;
	for(i=0;i<s->top;i++)
	{
		printf("%d", s->data[i]);
		printf("\n\\___/\n");
	}
}

int stack_empty(stack *s)
{
	if(s->top==-1)
	return 1;
	else return 0;
}

int main()
{
    int i,item;
    stack STACK;
    STACK.top=-1;
    printf("Enter the ten numbers randomly in the stack one by one:\n");
    for(i=0;i<5;i++)
    {
              scanf("%d",&item);
              push(&STACK,item);
              printf("Status of stack after adding integer:\n");
              display_stack(&STACK);
    }getch();
}

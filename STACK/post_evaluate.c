//POSTFIX EVALUTION
#include <stdio.h>
#include <math.h>
#define SIZE 100
typedef struct {
		int top;
		double data[SIZE];
}stack;

void push(stack *s,double item)
{
     if(s->top==SIZE-1)
     printf("STACK IS FULL\n");
     else
	 {
		s->top++;
		s->data[s->top]=item;
	 }
}

double pop(stack *s)
{
    if(empty_stack(s))         
    printf("STACK IS EMPTY\n");
    else
	return s->data[s->top--];
}

void display_stack(stack *s)			//Displaying current structure of stack
{
	int m;
	if(empty_stack(s))
	{
		printf("******EMPTY******\n");
	}
	else
	{
		for(m=s->top;m>=0;m--)
		{
			printf("\t|%f|\n",s->data[m]);
		}
	}
}

int empty_stack(stack *s)
{
	if(s->top==-1)
	return 1;
	else return 0;
}

int check_operand(char ch)		//Check weather a character is oprand or not 
{
	if(ch>='0'&&ch<='9')
	return 1;
	else return 0;
}

double operate(double c1,double c2,char op)
{
	switch(op){
	case '+':return (c1+c2);
	case '-':return (c1-c2);
	case '*':return (c1*c2);
	case '/':return (c1/c2);
	case '$':return (pow(c1,c2));
	default:printf("\nundefined");
		exit(1);
	}
}

/***************************************/
/*Postfix Evaluation Algorithm*/
double postfix(stack *s,char *ch)
{
	int i=0;
	while(ch[i]!='\0')
	{
		if(check_operand(ch[i])==0)
		{
			double c2=pop(s);
			double c1=pop(s);
			double temp=operate(c1,c2,ch[i]);
			push(s,temp);
		}
		else
		push(s,ch[i]-'0');
		i++;
	}
	return pop(s);
}
int main()
{
	char str[SIZE];
	stack s;
	s.top=-1;
	printf("\nEnter the string in exact postfix form:");
	scanf("%s",str);
	printf("\n******Evaluation has been Done!!!******");
	printf("\nAnswer is :%f\n",postfix(&s,str));
	return 0;
}

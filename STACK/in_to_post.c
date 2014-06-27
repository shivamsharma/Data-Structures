//INFIX TO POSTFIX
#include <stdio.h>
#define SIZE 100
typedef struct {
		int top;
		char item[SIZE];
}stack;

void push(stack *s,char item)
{
     if(s->top==SIZE-1)
     printf("STACK IS FULL\n");
     else
	 {
		s->top++;
		s->item[s->top]=item;
	 }
}

char pop(stack *s)
{
    if(empty_stack(s))         
    printf("STACK IS EMPTY\n");
    else
	return s->item[s->top--];
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
			printf("\t|%c|\n",s->item[m]);
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
	if((ch>='0'&&ch<='9')||(ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
	return 1;
	else return 0;
}

int precedence(char c1,char c2)
{
	int flag1,flag2;
	int a,s,m,d,e,l,r;			//a-add ,s-sub ,m-multi ,d-div ,e-expo
	s=1,a=2,m=3,d=4,e=5,l=-1,r=0;
	switch(c1){
	case '+':flag1=a;break;
	case '-':flag1=s;break;
	case '*':flag1=m;break;
	case '/':flag1=d;break;
	case '$':flag1=e;break;
	case '(':flag1=l;break;
	case ')':flag1=r;break;
	default:printf("\nundefined");
		exit(1);
	}
	switch(c2){
	case '+':flag2=a;break;
	case '-':flag2=s;break;
	case '*':flag2=m;break;
	case '/':flag2=d;break;
	case '$':flag2=e;break;
	case '(':flag2=l;break;
	case ')':flag2=r;break;
	default:printf("\nundefined");
		exit(1);
	}
	if((flag1==l)||(flag2==l&&flag1!=r))
	return 0;
	if(flag2==r&&flag1!=l)
	return 1;
	if(flag1==e&&flag2==e)
	return 0;
	if(flag1>=flag2)				//Operator 1(ch1) is high precedece over Operator 2(ch2) then true
	{
		return 1;
	}
	return 0;
}

/***************************************/
/*INFIX TO POSTFIX CONVERSION ALGO*/
void conversion(stack *s, char *ch,char *postfix)
{
	int i=0,k=0;
	while(ch[i]!='\0')
	{
		if(check_operand(ch[i]))
		{
			postfix[k]=ch[i];
			k++;
		}
		else
		{
			while(!empty_stack(s)&&precedence(s->item[s->top],ch[i]))
			{
				char c=pop(s);
				postfix[k]=c;
				k++;
			}
			push(s,ch[i]);
		}
		i++;
	}
	while(!empty_stack(s))
	{
		char c=pop(s);
		postfix[k]=c;
		k++;
	}
	postfix[k]='\0';
}

int main()
{
	stack s;
	s.top=-1;
	int i;
	char str[SIZE],postfix[SIZE];
	printf("\nEnter the string in INFIX form:");
	scanf("%s",str);
	conversion(&s,str,postfix);
	printf("\nString has been converted to POSTFIX\nPOSTFIX form is:%s",postfix);
	return 0;
}

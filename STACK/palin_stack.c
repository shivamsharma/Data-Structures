//Exercise 2.1.3 Tenenbaum
#include <stdio.h>
#define MAX 100
static int top=-1;
struct stack{
	char e;
};
void push(struct stack *s,char e)		//Push a char element in stack
{
	if(top==MAX-1)
	{
		printf("\nStack Overflow\n");		//If index to of top is greater than array size
	}
	else
	{
		top++;
		s[top].e=e;
	}
}
int pop(struct stack *s)
{
	if(top==-1)
	{
		printf("\nStack Underflow\n");			//If index is at -1 means stack is empty
		return -1;
	}
	else
	{
		top--;
	}
	return s[top+1].e;
}
void display_stack(struct stack *s)				//Displaying current structure of stack
{
	int m;
	if(top==-1)
	{
		printf("EMPTY....\n");
	}
	else
	{
		for(m=top;m>=0;m--)
		{
			printf("\t|%c|\n",s[m].e);
		}
	}
}

int main()
{
	struct stack s[MAX];
	char str[MAX];
	int m,flag=0;
	printf("\nEnter the String you want to check:");
	scanf("%s",str);
	/*First pushing half elements of string in stack.
	*Means if string is aabbaa(even length) than push aab
	*if string is aabbcbbaa(odd) than push aabb
	*in leave c and than pop and compare each poped
	*element with element left in string after 'c'.*/
	for(m=0;m<strlen(str)/2;m++)
	{
		push(s,str[m]);
	}
	if(strlen(str)%2!=0)
	m++;
	while(m<strlen(str))
	{
		char ch=pop(s);
		if(ch!=str[m])
		{
			flag=1;
			printf("\nIt is not of form x C y.\n");
			break;
		}
		m++;
	}
	if(flag!=1)
	printf("\nIt is of form x C y\n");
	return 0;
}

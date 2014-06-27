#include <stdio.h>
int func()
{
	static int var=0;	//var is local to function
	var++;
	return var;
}
int func1()
{
	int var=0;	//var is local to function
	var++;
	return var
}
int main()
{
	int i;
	for(i=0;i<3;i++)
	{
		printf("%d\n",func());	//here var will changed its value
	}
	printf("Function 2nd\n");
	for(i=0;i<3;i++)
	{
		printf("%d\n",func1());	//here var will not changed its value
	}
	return 0;
}

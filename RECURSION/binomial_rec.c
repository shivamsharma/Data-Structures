//Recursion Tenenbaum Question 3.2.3
/*It is function calculating NcR*/
#include <stdio.h>
int comm(int n ,int k)
{
	if(n<k)
	{
		return 0;
	}
	if(k==1)
	{
		return n;
	}
	if(k==0)
	{
		return 1;
	}
	return comm(n-1,k)+comm(n-1,k-1);
}
int main()
{
	int n,k;
	printf("\nEnter the no. of people n=");
	scanf("%d",&n);
	printf("\nEnter the no. of people you want to choose from n to form committee is k:");
	scanf("%d",&k);
	printf("\nPossible no. of ways to form committee are %d.\n",comm(n,k));
	return 0;
}

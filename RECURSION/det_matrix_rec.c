//Tenenbaum 3.2.6
#include <stdio.h>
#define SIZE 10
void minor(int a[SIZE][SIZE],int i,int j,int b[SIZE][SIZE],int n)
{
	int p,q,r=0,s;
	for(p=0;p<n-1;p++)
	{
		s=0;
		if(r==i)
		r++;
		for(q=0;q<n-1;q++)
		{
			if(s==j)
			s++;
			/*printf("\nr--%d s--%d a[][]---%d",r,s,a[r][s]);*/
			b[p][q]=a[r][s];
			s++;			
		}
		r++;
	}
}
int det(int a[SIZE][SIZE],int n)
{
	int i,j=0,sum=0,p,q;
	int b[SIZE][SIZE];
	if(n==1)
	return a[0][0];
	for(i=0;i<n;i++)
	{
		minor(a,i,0,b,n);
		/*for(p=0;p<n-1;p++)
		{
			for(q=0;q<n-1;q++)
			printf("%d ",b[p][q]);
			printf("\n");
		}
		printf("\n");*/
		sum+=pow(-1,i)*a[i][0]*det(b,n-1);
	}
	return sum;
}
int main()
{
	int i,j,n,p,q;
	int a[SIZE][SIZE];
	int b[SIZE][SIZE];
	printf("\nEnter the Size of Matrix n*n then n:");
	scanf("%d",&n);
	for(i=0;i<n;i++)	
	{
		for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	}
	printf("\nDeterminant of entered Matrix is :%d",det(a,n));
	return 0;
}

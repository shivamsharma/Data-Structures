//Tower of Hanoi
#include <stdio.h>
void toh(int disk,char start ,char end,char mid)
{
	if(disk==1)
	{
		printf("\nDisk 1 has been moved from pole %c to pole %c.",start,end);
		return;
	}
	/*Move top n-1 disks from A to B using C*/
	toh(disk-1,start,mid,end);
	printf("\nDisk %d has been moved from pole %c to pole %c.",disk,start,end);
	/*Move top n-1 disks from B to C using A*/
	toh(disk-1,mid,end,start);
}
int main()
{
	int disk;
	printf("\nThis is program of tower of honoi...");
	printf("\nEnter the no. of disk:");
	scanf("%d",&disk);
	toh(disk,'A','C','B');
	return 0;
}

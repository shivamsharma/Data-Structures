/*Simple Binary Tree program creating
*Almost Complete Binary Tree and 
*traversing through inorder form*/
#include <stdio.h>
#include <malloc.h>
#define null 0
typedef struct node {
			int info;
			struct node *left,*right;
}NODE;
//It will create a node
NODE *getnode()
{
	NODE *p;
	p=(NODE *)malloc(sizeof(NODE));
	return p;
}
//It will free the allocated memory
void freenode(NODE *p)
{
	free((char *)p);
	return ;
}

NODE *maketree(int item)
{
	NODE *p;
	p=getnode();
	p->info=item;
	p->left=null;
	p->right=null;
	return p;
}

void setleft(NODE *p,int item)
{
	NODE *q;
	if(p==null)
	{
		printf("\n******Void Insertion*******\n");
		return ;
	}
	else if(p->left!=null)
	{
		p=p->left;
	}
	q=maketree(item);
	p->left=q;
}

void setright(NODE *p,int item)
{
	NODE *q;
	if(p==null)
	printf("\n******Void Insertion*******\n");
	else if(p->right!=null)
	{
		p=p->right;
	}
	q=maketree(item);
	p->right=q;
}
//Node p should always be root
void intrav(NODE *p)
{
	if(p!=null)
	{
		intrav(p->left);
		printf("%d->",p->info);
		intrav(p->right);
	}
}

int main()
{
	printf("This is the Binary Tree making program...\n");
	int i,j,e;
	printf("\nEnter the root element of tree(int):");
	scanf("%d",&e);
	NODE *p,*root;
	p=maketree(e);
	root=p;
	while(1)
	{
		printf("\nEnter \'1\' for setleft ,\'2\' for setright ,\'3\' for inorder traverse and \'0\' for exit:");
		scanf("%d",&j);
		switch(j){
			case 0: exit(0);
			case 1:printf("Enter the element to setleft:");
				scanf("%d",&e);
				setleft(p,e);
				break;
			case 2:printf("Enter the element to setright:");
				scanf("%d",&e);
				setright(p,e);
				break;
			case 3:printf("Tree in inorder:");
				intrav(root);
				printf("\n");
				break;
			default:printf("Wrong action taken!!!\n");
		}
	}
	return 0;
}

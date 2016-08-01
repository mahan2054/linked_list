#include<stdio.h>
#include<stdlib.h>


struct node{
    int info;
    struct node *next;
};

typedef struct node *nodeptr;

nodeptr getnode();
void insertatfront(nodeptr*,int);
int removefromfront(nodeptr*);
void freenode(nodeptr);
void displaylist(nodeptr);
int removefromfront(nodeptr*);

int main()
{
    nodeptr p;
    p=NULL;
    insertatfront(&p,5);
    insertatfront(&p,6);
    insertatfront(&p,7);  
    displaylist(p);
	printf("%d\n",removefromfront(&p));
	printf("%d\n",removefromfront(&p));
	printf("%d\n",removefromfront(&p));
 	printf("%d\n",removefromfront(&p));	  
    displaylist(p); 
     
}
nodeptr getnode()
{
    return (nodeptr)malloc(sizeof(nodeptr));
}
void freenode(nodeptr p)
{
    free(p);
}

void insertatfront(nodeptr* p,int x)
{
    nodeptr q;
    q= getnode();
    q->info =x;
    q->next = *p;
    *p=q;
    
}

void displaylist(nodeptr p)
{
    nodeptr ptr= p;
    while(ptr!=NULL)
  {
      printf("List:%d\n",ptr->info);
      ptr = ptr->next;
  }
    
}

int removefromfront(nodeptr *p)
{    
	int x;
	if (*p==NULL)
	{
		printf("List Underflow\n");
		exit(0);
	}else
	{
		nodeptr q;
	    q=*p;
	    *p=q->next;
	    x=q->info;
	    freenode(q);
		return x;    
	}	
}


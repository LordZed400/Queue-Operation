#include<stdio.h>
#include<conio.h>
#include<process.h>
#define MAX 20

struct cqueue
{
  int item[MAX];
  int r;
  int f;
  };

 typedef struct cqueue qu;

  void ins(qu*);
  void del(qu*);
  void dis(qu*);

  void main()
  {
   int ch;
   qu *q;
   q->r=MAX-1;
   q->f=MAX-1;
   UP:
   clrscr();
   printf("\n\n\tProgram to implement circular queue\n");
   printf("     =========================================\n");
	printf("\t1.\tEnqueue\n");
	printf("\t2.\tDequeue\n");
	printf("\t3.\tDisplay\n");
	printf("\t4.\tExit\n");
   printf("\n\t Enter your choice: ");
   scanf("%d", &ch);
    switch(ch)
    {
      case 1:
	{
	    ins(q);
	    break;
	}
      case 2:
	{
	    del(q);
	    break;
	}
      case 3:
	{
	   dis(q);
	   break;
	}
      case 4:
	{
	   exit(1);
	   break;
	}
      default:
	{
	     printf("\n\tEntered the wrong choice\n");
	     getch();
	}
      }

      goto UP;
      }

 void ins(qu *q)
 {
	int d;
	if ((q->r+1)%MAX==q->f)
	{
	printf("\nQueue is full\n");
	getch();
	}
	else
	{
	q->r=(q->r+1)%MAX;
	printf("\nEnter data to be inserted : ");
	scanf("%d",&d);
	q->item[q->r]=d;
	}
   }

 void del(qu *q)
  {
	    int d;
	    if(q->r==q->f)
	    {
	    printf("\nQueue is empty\n");
	    getch();
	    }
	      else
	    {
	       q->f=(q->f+1)%MAX;
	       printf("\nDeleted item is: ");
	       printf("%d\n",q->item[q->f]);
	    getch();
	    }
  }


 void dis(qu *q)
  {
	       int i;
	       if(q->r==q->f)
	       {
		printf("\nQueue is empty\n");
	       getch();
	       }
		 else
	       {
		printf("\nDisplaying items on queue:\n");
		for(i=(q->f+1)%MAX;i!=q->r;i=(i+1)%MAX)
	       {
		printf(" %d\t", q->item[i]);
	       }
		printf("%d\t",q->item[q->r]);
	       getch();
	       }
  }

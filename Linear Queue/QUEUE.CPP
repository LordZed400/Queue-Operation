#include<stdio.h>
#include<conio.h>
#include<process.h>
#define MAX 50

int q_item[MAX];
int r = - 1;
int f = - 1;

void ins(void);
void del(void);
void dis(void);

void main()
{
int c;
up:
clrscr();
printf("Queue Operations\n");
printf("----------------\n\n");
printf("1.Insert element\n");
printf("2.Delete element\n");
printf("3.Display all elements\n");
printf("4.Quit \n");

printf("\n\tPlease enter your choice: ");
scanf("%d", &c);
switch (c)
	{
	    case 1:
	    {
	    ins();
	    break;
	    }
	    case 2:
	    {
	    del();
	    break;
	    }
	    case 3:
	    {
	    dis();
	    break;
	    }
	    case 4:
	    {
	    exit(1);
	    }
	    default:
	    {
		printf("Wrong choice\n");
		getch();
	    }
	}
goto up;
}

void ins()
{
    int add_item;
    if (r == MAX - 1)
    {
    printf("Queue Overflow \n");
    getch();
    }
    else
    {
	if (f == - 1)
	f = 0;
	printf("Inset the element in queue : ");
	scanf("%d", &add_item);
	r = r + 1;
	q_item[r] = add_item;
    }
}

void del()
{
    if (f == - 1 || f > r)
    {
	printf("Queue is Empty \n");
	getch();
	return ;
    }
    else
    {
	printf("Element deleted from queue is : %d\n", q_item[f]);
	f = f + 1;
     getch();
    }
}

void dis()
{
    int i;
    if (f == - 1)
    {
	printf("Queue is empty \n");
	getch();
    }
    else
    {
	printf("Queue is : \n");
	for (i = f; i <= r; i++)
	{
	printf("  %d ", q_item[i]);
	printf(" ");
	}
    getch();
    }
}

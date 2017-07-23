#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 10
int Qfull();
int Qempty();
void PQin( int );
int PQdelmin();
int PQdelmax();

void des();
void aes();
void dis();

int PQ[SIZE],f=0,r=-1;

   void main()
   {
   int c;
   UP:
   clrscr();
   printf("\t\tMain Menu\n");
   printf("\t\t---------------\n");
   printf("\n 1.Ascending Priority Queue \n 2.Descending Prority Queue\n 3.Exit\n");
   printf("Please Choose: \n");
   scanf("%d",&c);

   switch(c)
	{
	   case 1:
		{
		aes();
		break;
		}
	   case 2:
		{
		des();
		break;
		}
	   case 3:
		{
		exit(0);
		}
	   default:
		{
		   printf("Wrong choice");
		   break;
		}
	}
goto UP;
getch();
}

void des()
{
int c, e;
do
{
	clrscr();
	printf("\n Descending Priority Queue Operation\n\n");
	printf("\n 1.Insert \n 2.Delete Max\n 3.Display \n 4.Find Max \n 5.Exit\n");
	printf("\n Choose: ");
	scanf("%d",&c);
	switch(c)
	      {
	       case 1:
		{
		 printf("\n\nElement to be Inserted ? ");
		 scanf("%d",&e);
		 PQin(e);
		 break;
		}
	       case 2:
		{
		 e=PQdelmax();
		     if( e != -1)
			   printf("\n\nDeleted Element is %d \n",e);
		 break;
		}
	       case 3:
		{
		 printf("\n\nStatus of Queue\n\n");
		 dis();
		 break;
		}
		case 4:
		{
		 printf("\n\nMax Element: %d\n\n", PQ[r]);
		 break;
		}
		case 5:
		{
		 break;
		}
		default:
		{
		 printf("\n\nInvalid Option !!! Try Again !! \n\n");
		}
	}
      printf("\nPress any key to continue\n");
      getch();
      }while(c != 5);
   }

void aes()
{
int c,e;
do
{
	clrscr();
	printf("\n Ascending Priority Queue Operation\n\n");
	printf("\n 1.Insert \n 2.Delete Min\n 3.Display \n 4.Find Min \n 5.Exit\n");
	printf("\n Choose: ");
	scanf("%d",&c);
	switch(c)
	     {
	      case 1:
		{
		printf("\n\nElement to be Inserted ? ");
		scanf("%d",&e);
		PQin(e);
		break;
		}
	       case 2:
		{
		 e=PQdelmin();
		 if( e != -1)
		    printf("\n\nDeleted Element is %d \n",e);
		      break;
		}
	       case 3:
		{
		 printf("\n\nStatus of Queue\n\n");
		 dis();
		 break;
		}
		case 4:
		{
		 printf("\n\nMin Element: %d\n\n", PQ[f]);
		 break;
		}
		case 5:
		{
		break;
		 }
	       default:
		{
		printf("\n\nInvalid Option !!! Try Again !! \n\n");
		break;
		}
      }
      printf("\nPress any key to continue\n");
      getch();
      }while(c != 5);
   }

void PQin(int e)
{
int i;
if(Qfull())
  printf("\n\n Overflow!!!!\n\n");
else
   {
    i=r;
    ++r;

    while(PQ[i] >= e && i >= 0)
    {
     PQ[i+1]=PQ[i];
     i--;
     }
     PQ[i+1]=e;
     }
  }

int PQdelmax()
{
int e;
if(Qempty())
{
  printf("\n\nEmpty!!!!\n\n");
  return(-1);
}
else
{
   e=PQ[r];
   r=r-1;
   return(e);
}
}

int PQdelmin()
{
int e;
if(Qempty())
{
  printf("\n\nEmpty!!!!\n\n");
  return(-1);
}
else
{
   e=PQ[f];
   f=f+1;
   return(e);
}
}




int Qfull()
{
if(r==SIZE-1)
	 return 1;
return 0;
}

int Qempty()
{
if(f > r)
	return 1;
return 0;
}

void dis()
{
int i;
if(Qempty())
	 printf(" \n Empty Queue\n");
else
     {
      printf("Front->");
      for(i=f;i<=r;i++)
	{
	 printf("%d ",PQ[i]);
	}
	printf("<-Rear");
      }
}

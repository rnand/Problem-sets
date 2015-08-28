#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
	int qsize,*aliveq,i,deadcount=0,j,swordman,victim;
    int next_swordman(int,int*,int,int);
    int next_victim(int,int*,int,int);
	system("cls");
	printf("\nEnter the number of people:");
	scanf("%d",&qsize);
	aliveq=(int*)malloc(qsize*sizeof(int));
	for(i=0;i<qsize;i++)
	{
		*(aliveq+i)=1;  //set everyone as alive
		printf("\t%d",*(aliveq+i) ); //debug display
	}
	swordman=0;
	victim=1;
	while(deadcount<qsize-2)
	{

		*(aliveq+victim)=0;
		printf("\n======================================================\n");
		printf("\nPerson %d kills person %d.\n\n",swordman+1,victim+1 );
		deadcount++;
		printf("\nDeadcount=%d\n",deadcount );
		printf("\nqsize-1=%d\n",qsize-1);
		printf("\nAliveq:\n");

		for(j=0;j<qsize;j++)
		{

			printf("\t%d",*(aliveq+j) ); //debug display
		}

		swordman=next_swordman(qsize,aliveq,swordman,victim);
		victim=next_victim(qsize,aliveq,victim,swordman);
		//printf("\n\n===============\nswordman=%d\n\n==============\n",swordman);
		printf("\n======================================================\n");


	}
	printf("\nThe number of people dead:%d",deadcount);
	printf("\nThe position of the last person alive is:%d",swordman);
	getch();


}

int next_swordman(int qsize,int *aq,int cur,int victim)
{
	int i;
	while(1)
	{
		if(cur+1>=qsize)
		{
			for(i=0;i<qsize;i++)
			{
				if(*(aq+i)==1)
				{
					return i;
				}
			}

		}
		else
		{
			for(i=victim+1;i<qsize;i++)
			{
				if(*(aq+i)==1)
				{
					return i;
				}
			}

		}
	}

}

int next_victim(int qsize,int *aq,int cur,int swordman)
{
	int i;
	while(1)
	{
		if(swordman+1>=qsize)
		{
			for(i=0;i<qsize;i++)
			{
				if(*(aq+i)==1)
				{
					return i;
				}
			}
		}
		else
		{
			for(i=swordman+1;i<qsize;i++)
			{
				if(*(aq+i)==1)
				{
					return i;
				}
			}
		}
	}
}

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
	int qsize,*aliveq,i,deadcount=0,j,swordman,victim;

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
	while(deadcount<qsize-1)
	{
		
		*(aliveq+victim)=0;
		printf("\nPerson %d kills person %d.\n",swordman+1,victim+1 );
		deadcount++;
		printf("\nDeadcount=%d\n",deadcount );
		printf("\nAliveq:\n");
		
		for(j=0;j<qsize;j++)
		{
	
			printf("\t%d",*(aliveq+j) ); //debug display
		}

		swordman=next_swordman(qsize,aliveq,swordman);
		victim=next_victim(qsize,aliveq,victim,swordman);
		printf("\n\n===============\ni=%d\n\n==============\n",i);
	

	}
	getch();

	
}

int next_swordman(int qsize,int *aq,int cur)
{
	
	while(1)
	{
		if(cur+1>=qsize)
		{
			cur=0;
			return cur;
		}
		else
		{
			return cur+1;
		}
	}

}

int next_victim(int qsize,int *aq,int cur,int swordman)
{
	while(1)
	{
		if(swordman+1>=qsize)
		{
			for(int i=0;i<qsize;i++)
			{
				if(*(aq+i)==1)
				{
					return i;
				}
			}
		}
		else
		{
			for(int i=swordman;i<qsize;i++)
			{
				if(*(aq+i)==1)
				{
					return i;
				}
			}
		}
	}
}

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
	int qsize,*aliveq,i,deadcount=0,j;
	system("cls");
	printf("\nEnter the number of people:");
	scanf("%d",&qsize);
	aliveq=(int*)malloc(qsize*sizeof(int));
	for(i=0;i<qsize;i++)
	{
		*(aliveq+i)=1;  //set everyone as alive
		printf("\t%d",*(aliveq+i) ); //debug display
	}
	i=0;
	while(deadcount<qsize-1)
	{
		if(*(aliveq+i)==1)
		{
			*(aliveq+i+1)=0;
			printf("\nPerson %d kills person %d.\n",i+1,i+2 );
			deadcount++;
			printf("\nDeadcount=%d\n",deadcount );
			printf("\nAliveq:\n");
			for(j=0;j<qsize;j++)
			{
		
				printf("\t%d",*(aliveq+j) ); //debug display
			}
			
		}
		if(i<=qsize)
		{
			i++;
		}
		else
		{
			i=0;
		}
	}
	getch();
}
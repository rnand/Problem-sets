#include <stdio.h>
#include <stdlib.h>

void main()
{
	int n,**matptr,i,j;
	printf("Enter the order of the square matrix:\n");
	scanf("%d",&n);
	matptr=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
	{
		matptr[i]=(int*)malloc(n*sizeof(int));
	}
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&matptr[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			printf("%d\t",matptr[i][j]);
		}
	}
	//do stuff here
	for(i=0;i<n;i++)
	{
		free(matptr[i]);
	}
	free(matptr);

}
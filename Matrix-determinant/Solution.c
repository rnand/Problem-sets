#include <stdio.h>
#include <stdlib.h>

void main()
{
	int n,**matptr,i;
	printf("Enter the order of the square matrix:\n");
	scanf("%d",&n);
	matptr=(int**)calloc(n*sizeof(int*));
	for(i=0;i<n;i++)
	{
		matptr[i]=(int*)calloc(n*sizeof(int));
	}

	printf("Enter the elements:\n");
	
}
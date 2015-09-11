#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	int n,**matptr,i,j,det;
	//int find_det(int*,int);
	printf("Enter the order of the square matrix:\n");
	scanf("%d",&n);
	matptr=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
	{
		matptr[i]=(int*)malloc(n*sizeof(int)); //allocate memory for the 2d array
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
	printf("\nThe determinant:%d",find_det(matptr,n) );

	for(i=0;i<n;i++)
	{
		free(matptr[i]);
	}
	free(matptr);

}
int find_det(int **mat,int mat_size)
{
	int i,j,k,det=0;
	if(mat_size>2)
	{
		//make recursive call here, probably need another function
	}
	else
	{
		for(i=0;i<mat_size;i++)
		{		
			for(j=i+1;j<mat_size;j++)
			{			
				for(k=0;k<mat_size;k++)
				{
					det += mat[i][k] * mat[k][j]; //this is wrong. fix it
					det=-det;
					printf("\ni=%d j=%d k=%d\nmat[i][k]=%d * mat[k][j]=%d",i,j,k,mat[i][k],mat[k][j] );
				}
			
			}
		}
	}
	
	return abs(det);
}
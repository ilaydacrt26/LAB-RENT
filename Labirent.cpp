#include <stdio.h>
#include <stdlib.h>
#include <time.h>
main(){
	int n;
	printf("n degeri kac olsun: ");
	scanf("%d",&n);
	srand(time(NULL));
	int matris[n][n+1];
	bool devammi=true;
	while(devammi==true)
	{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if (j == n) {
				matris[i][j] = 0;
			}
			else {
				matris[i][j]=rand()%2;	
				if(i==0 && j==0)
				{
					matris[i][j]=1;
				}
				if(i==n-1 && j==n-1)
				{
					matris[i][j]=1;
				}
			} 
		}	
	}	
	printf("\n\n");
	printf("ILK DURUM: \n\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==0 && j==0)
			{
				printf("\tA\t");
			}
			else if(i==n-1 && j==n-1)
			{
				printf("\tB\t");
			}
			else
			{
				printf("\t%d\t",matris[i][j]);
			}
		}
		printf("\n\n");
	}
	int kontrol=0;
	int i=0,j=0,x=1;
	matris[i][j]=x;
	x++;
	while(kontrol==0)
	{
		if(matris[i][j+1]==1)
		{
			if(j==n-1)
			{
				i++;
			}	
			j++;
			matris[i][j]=x;
			x++;
		}
		else if(matris[i+1][j]==1)
		{
			i++;
			matris[i][j]=x;
			x++;
		}
		else if(j==n-1 && matris[i+1][j]==0)
		{
			kontrol=1;
			break;
		}
		else
		{
			devammi=true;
			x=1;
			printf("Dolambactan cikilamadi..");
			kontrol=1;	
			break;
		}
		if(matris[i][j]==matris[n-1][n-1])
		{
			printf("Basarili..");
			devammi=false;	
			kontrol=1;
		}
	}
	printf("\n\n");
	printf("SON DURUM: \n\n");
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("\t%d\t",matris[i][j]);
		}
		printf("\n\n");
	}
	}
	return 0;
}

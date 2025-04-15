#include<stdio.h>
void main()
{
int a[20],n,i;
void Quicksort(int a[], int lb, int ub);
printf("\nHow many element\n");
scanf("%d",&n);
printf("\nEnter the unsorted element\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);

Quicksort(a,0,n-1);

printf("\n Sorted Array is :\n");
for(i=0;i<n;i++)
printf("\n %d",a[i]);
}//main

void Quicksort(int a[], int lb, int ub)
{
 int partition(int a[],int lb,int ub);
		 int j=0;
		if(lb<ub)
			{
				j = partition(a,lb,ub);
				Quicksort(a,lb,j-1);
				Quicksort(a,j+1,ub);
			}
}


int partition(int a[],int lb,int ub)
{
			 int dn,pivot,up,temp;
			dn=lb;
			up=ub;
			pivot=a[lb];


	do
	{
		while((a[dn]<=pivot) && (dn<ub))
		dn++;

		while((a[up]>pivot) && (up>lb))
		up--;

		if(dn<up)
       		{
		temp=a[dn];
		a[dn]=a[up];
		a[up]=temp;
		}
	}while(dn<up);

	a[lb]=a[up];
	a[up]=pivot;
	return up; 
}




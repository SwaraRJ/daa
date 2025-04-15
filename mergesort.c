#include<stdio.h>
void mergesort(int a[],int,int);
void Merge(int a[],int,int,int);
void main()
{
	int n,i,a[20];
	printf("\n Enter the element you want :\n");
	scanf("%d",&n);
	printf("\n Enter the element:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	mergesort(a,0,n-1);
	printf("\n sorted array is:\n");
	for(i=0;i<n;i++)
	printf("\n%d",a[i]);
}
void mergesort(int a[],int low, int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		Merge(a,low,mid,high);
	}
}
void Merge(int a[20],int low,int mid,int high)
{
	int i,j,k,b[20];	
	i=low,j=mid+1,k=0;
 
	while((i<=mid) && (j<=high))
	{
		if(a[i]<a[j])
		b[k++]=a[i++];
               else
		b[k++]=a[j++];
         }

    
        while(i<=mid)
		b[k++]=a[i++];

	while(j<=high)
		b[k++]=a[j++];

	for(j=low,k=0;j<=high;j++,k++)
 		a[j]=b[k];
}





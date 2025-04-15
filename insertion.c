#include<stdio.h>
int comp_cnt;

void main()
{
	int a[20],i,n;
	void insertion(int a[], int n);
	printf("How many elements you want to enter? \n");
	scanf("%d",&n);
	printf("Enter %d elements: \t",n);
	for(i=0; i<n; i++)
		{
			scanf("%d",&a[i]);
		}
	insertion(a,n);
	printf("Sorted elements are: \t");
	for(i=0; i<n; i++)	
		{
			printf("%d\t",a[i]);
		}
	printf("\n Total number of comparisions: %d \n",comp_cnt);
}
void insertion(int a[20], int n)
{
	int i,k,new;
	for(k=1; k<n; k++)
		{
			new=a[k];
			for(i=k-1; i>=0; i--)
				{
					comp_cnt++;
					if(a[i]>new)
						{
							a[i+1]=a[i];
						}
					else
                                         break;
				}
			a[i+1]=new;	
		}
}


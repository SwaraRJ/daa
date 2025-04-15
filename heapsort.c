#include<stdio.h>
#include<stdlib.h>
void heapsort(int  a[],int n);
void Heapify(int a[],int i,int last);
void BuildHeap(int a[],int n);
void display(int a[],int n);

void heapsort(int a[10], int n)
{
   
  	        int i,temp;
   	        BuildHeap(a,n);
                printf("\n initila Heap\n");
		display(a,n);

	for(i=n-1;i>=1;i--)
	{
		temp=a[0];
		a[0]=a[i];
		a[i]=temp;

                printf("\n After Iteration %d :",n-i);
		display(a,n);
		Heapify(a,0,i-1);
       	}
}

void BuildHeap(int a[], int n)
{
         //convert a[0].. a[n-1] into heap
          int i;
    
         for(i=(n/2)-1; i>=0;i--)
          Heapify(a,i,n-1);
}

void Heapify(int a[],int i,int last)
{
	int j,temp,key;

	key=a[i];
	j=2*i+1;//j points to left child
	
	if((j<last)&&(a[j]<a[j+1]))
	j=j+1;//j points to left child

	if((j<=last)&& (key <a[j]))//compare left and right children
	{
		temp = a[i];
		a[i]=a[j];
		a[j]=temp;
		Heapify(a,j,last);
	}

   
}

void display(int a[],int n)
{
    for(int i=0;i<n;i++)
      printf("\n %d",a[i]); 
}



int main()
{
  int a[10],n,i;

  	printf("\n How many element in an array?");
	scanf("%d",&n);

        printf("\nEnter %d element in an array",n);

        for(i=0;i<n;i++)
	scanf("%d",&a[i]);	
	heapsort(a,n);
	printf("\n The sorted elements are");
        display(a,n);
   	return 0;
}

heap_sort.c
Displaying heap_sort.c.
Parctical Sem IV Program
Ashalata Bhandare Computer Science
•
2 May 2023 (Edited 2 May 2023)
Go through following prograaming
setc_1.c
C
Tree.c
C
Tree.h
C
heap_sort.c
C
level_order.c
C
level_order.h
C
Adj_Mat.c
C
adj_mat_in_out.c
C
assign_3.c
C
DFS.c
C
graph.c
C
adj_mat_in_out.c
C
Adj_Mat_List.c
C

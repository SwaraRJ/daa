#include<stdio.h>
void main()
{
  int a[20],i,n;
  void selection(int a[], int n);
  
  printf("\n How Many elements you want to enter?");
  scanf("%d",&n);
  
  printf("\n Enter %d elements : \t",n);
  
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  selection(a,n);
  
  printf("\n Sorted elements are :- \t");
  for(i=0;i<n;i++)
  {
    printf("%d\t",a[i]);
  }
}
void selection(int a[20], int n)
{
  int i,j,t,pos;
  
  for(i=0;i<(n-1);i++)
  {
   pos=i;
   for(j=i+1;j<n;j++)
   {
     if(a[pos]>a[j])
     pos=j;
   }
   if(pos!=i)
   {
     t=a[j];
     a[j]=a[pos];
     a[pos]=t;
   }
  }
}



#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int n,targetSum;
int set[MAX],subset[MAX];

void printSubset(int subset[], int subsetSize);
void sumOfSubset(int index, int subset, int subsetSize);

void printSubset(int subset[], int subsetSize)
{
  printf("{");
  for(int i=0; i<subsetSize; i++)
  { 
    printf("%d  ",subset[i]);
  }
  printf("}\n");
}
void sumOfSubset(int index, int currentSum, int subsetSize)
{
   if(currentSum == targetSum){
   printSubset(subset,subsetSize);
   return;
   }
   
   
   if(index >= n || currentSum > targetSum)
   return;
   
   subset[subsetSize]=set[index];
   sumOfSubset(index+1, currentSum+set[index], subsetSize+1);
   
   sumOfSubset(index+1, currentSum, subsetSize);
}
int main()
{
   printf("\n enter the no.of elements :");
   scanf("%d",&n);
   
   printf("\n enter the elements : ");
   for(int i=0; i<n; i++)
     scanf("%d",&set[i]);
     
   printf("\n enter the targetSum :");
   scanf("%d",&targetSum);
   
   printf("\n subsets of sum %d are ",targetSum);
   sumOfSubset(0,0,0);
   return 0;
   
}

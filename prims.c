#include<stdio.h>
#define MAX 10
#define INF 999
void inputGraph();
void prims();

int cost[MAX][MAX],visited[MAX];
int n;

void inputGraph()
{
 int i,j;
  printf("\n Enter the no. of vertices ");
  scanf("%d",&n);
  
  printf("\n enter the adjacency cost to vertices [use 999 to no edge]");
  for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   {
     scanf("%d",&cost[i][j]);
   }
  }
  for(i=0;i<n;i++)
  visited[i]=0;
}
void prims()
{
  int edges=0,u=0,v=0;
  int min,i,j;
  int totalcost=0;
  
  visited[0]=1;
  printf("\n edges in MST\n");
  
  while(edges<n-1)
  {
    min=INF;
    for(i=0;i<n;i++)
    {
    if(visited[i])
    { 
     for(j=0;j<n;j++)
      {
       if(!visited[j] && cost[i][j]<min)
       { 
        min=cost[i][j];
        u=i;
        v=j;
       }
     }  
    }
   }
   printf("%d - %d : %d\n",u,v,min);
   visited[v]=1;
   totalcost+=min;
   edges++;
  }
  printf("Total minimum cost = %d\t",totalcost);
}
void main()
{
  printf("\n Implementation of prims Algorithm");
  inputGraph();
  prims();
}

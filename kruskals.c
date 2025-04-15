#include<stdio.h>
#define MAX 30
#define INF 999

void kruskal();
void inputGraph();
int  find(int i);
int unionSet(int i, int j);

int parent[MAX],cost[MAX][MAX];
int n;

int  find(int i)
{
  while(parent[i])
  i=parent[i];
  return i;
}

int unionSet(int i, int j)
{
  if(i!=j)
  {
   parent[j]=i;
   return 1;
   
  }
  return 0;
}

void inputGraph()
{
  int i,j;
 
 printf("\n enter the no.of vertices ");
 scanf("%d",&n);
 
 printf("\n enter the adjacency matrix :\n");
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
   scanf("%d",&cost[i][j]);
   
   for(i=0;i<n;i++)
    parent[i]=0;
 }  
 void kruskal()
 {
   int i,j,u,v,min, totalcost=0,edges=0;
   printf("\n edges in MST :\n");
   while(edges< n-1)
   {
     min=INF;
     for(i=0;i<n;i++)
     {
      for(j=0;j<n;j++)
      {
        if(cost[i][j]<min)
        {
         min=cost[i][j];
         u=i;
         v=j;
        }
      }
     }
     int set_u=find(u);
     int set_v=find(v);
     
     if(unionSet(set_u,set_v))
     {
       printf("%d - %d : %d\n",u,v,min);
       totalcost+=min;
       edges++;
     }
     cost[u][v]=cost[v][u]=INF;
     
   }
   printf("Total minimum cost : \t%d",totalcost);
}
int main()
{
  printf("\n IMplementation of kruskals algorithm\n");
  inputGraph();
  kruskal();
  return 0;
}

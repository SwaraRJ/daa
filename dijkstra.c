#include<stdio.h>
#define MAX 10
#define INF 999

int cost[MAX][MAX], dist[MAX], visited[MAX];
int n;

void inputGraph();
void dijkstra(int start);
void inputGraph()
{
  int i,j;
  
  printf("\n enter the no of vertices ");
  scanf("%d",&n);
  
  printf("\n enter the adj cost matrix");
  for(i=0;i<n;i++)
   for(j=0;j<n;j++)
    scanf("%d",&cost[i][j]);
}

void dijkstra(int start)
{
  int i,j,u,min;
  
  for(i=0;i<n;i++)
  {
   dist[i]=cost[start][i];
   visited[i]=0;
  }
  dist[start]=0;
  visited[start]=1;
  
  for(i=1;i<n;i++)
   min=INF;
   u=-1;
   
   for(j=0;j<n;j++)
   {
     if(!visited[j]  && dist[j]<min)
     {
       min=dist[j];
       u=j;
     }
   }
   if(u==-1) continue;
   
   visited[u]=1;
   
   for(j=0;j<n;j++)
   {
     if(!visited[j]  && dist[u]+cost[u][j]<dist[j])
     {
     dist[j]=dist[u]+cost[u][j];
     }
   }
   
   printf("shortest distance fromsource %d:\n",start);
     for(i=0;i<n;i++)
     {
       if(dist[i]!=INF)
          printf("To %d: %d\n",i,dist[i]);
       else
           printf("To %d: Unreachable\n",i);
     }
   
}
void main()
{
  int start;
  printf("\n implementation of Dijkstra Algo\n");
  inputGraph();
  printf("\n enter start vertex : ");
  scanf("%d",&start);
  dijkstra(start);
}

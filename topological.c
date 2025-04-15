#include<stdio.h>
#include<stdlib.h>
#define ver 6

void topologicalSort(int graph[ver][ver]);
void dfs(int graph[ver][ver],int v, int visited[ver],int stack[ver], int *top);

void dfs(int graph[ver][ver],int v, int visited[ver],int stack[ver], int *top)
{
   visited[v]=1;
   for(int i=0;i<ver;i++)
   {
      if(graph[v][i]==1 && !visited[i]){
      dfs(graph,i,visited,stack,top);
   }
  }
     stack[(*top)++]=v;
}
void topologicalSort(int graph[ver][ver])
{
   int visited[ver]={0};
   int stack[ver];
   int top=0;
   
   for(int i=0;i<ver;i++)
   {
     if(!visited[i])
     {
       dfs(graph,i,visited,stack,&top); 
     }
   }
   printf("\n topological sorting is ");
   
   for(int i=top-1;i>=0;i--)
   {
     printf("%d\t",stack[i]);
   }
}

void main()
{
   int graph[ver][ver]={
    {0,1,1,0,0,0},
    {0,0,1,0,0,0},
    {0,0,0,1,0,0},
    {0,0,0,0,1,0},
    {0,0,0,0,0,1},
    {0,0,0,0,0,0}
   };
 topologicalSort(graph);

}



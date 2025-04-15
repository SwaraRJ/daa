#include<stdio.h>

int adj[10][10],visited[10],n;

void dfs(int node)
{
   int i;
   printf("%d",node);
   visited[node]=1;
   
   for(i=0;i<n;i++)
   {
    if(adj[node][i]== 1 && !visited[i])
    {
     dfs(i);
    }
  }
}
int main()
{
  int i,j,start;
  
  printf("\n enter no.of vertices : ");
  scanf("%d",&n);
  
  printf("\n enter adjacency matrix : ");
  for(i=0;i<n;i++)
   for(j=0;j<n;j++)
   scanf("%d",&adj[i][j]);
   
   for(i=0;i<n;i++)
   visited[i]=0;
   
   printf("\n enter starting vertex : ");
   scanf("%d",&start);
   
   printf("\n BFS Traversal is ");
   dfs(start);
 return 0;  
}

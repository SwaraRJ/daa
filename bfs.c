#include<stdio.h>

int n,adj[10][10], visited[10]={0};
int queue[10],front=0, rear=0;

void bfs(int start);
int main()
{
  int start,i,j;
  
  printf("\n enter the no.of vertices ");
  scanf("%d",&n);
  
  printf("\n Enter Adjacency matrix :");
  for(i=0;i<n;i++)
   for(j=0;j<n;j++)
    scanf("%d",&adj[i][j]);
    
   for(i=0;i<n;i++)
     visited[i]=0;
    
  printf("\n Enter starting vertex");
  scanf("%d",&start);
  
  bfs(start);
  return 0;
}

void bfs(int start)
{
   int i,node;
  visited[start]=1;
  queue[rear++]=start;
  
  printf("Bfs Traversal :");
  while(front<rear)
  {
    node=queue[front++];
    printf("%d",node);
    
    for(i=0;i<n;i++)
    {
     if(adj[node][i] ==1 && !visited[i])
     {
       queue[rear++]=i;
       visited[i]=1;
     }
    }
  }
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lcsLength( char *X, char *Y,int m,int n);

int lcsLength( char *X, char *Y,int m,int n)
{
   int dp[m+1][n+1];
   
   for(int i=0; i<=m; i++){
    for(int j=0; j<=n; j++){
    
      if(i==0 || j==0)
       dp[i][j]=0;
       
       else if(X[i-1] == Y[j-1])
          dp[i][j]=dp[i-1][j-1]+1;
        
        else{
          if(dp[i-1][j]>dp[i][j-1])
            dp[i][j]=dp[i-1][j];
            else 
              dp[i][j]=dp[i][j-1];
        }
      
   }
 }
 return dp[m][n];
}
void main()
{
  char X[100], Y[100];
  
  printf("enter first string ");
  scanf("%s",X);
  printf("enter second string ");
  scanf("%s",Y);

  int m= strlen(X);
  int n= strlen(Y);

  int result = lcsLength(X,Y,m,n);
  printf("The Longest common subsequence is %d ",result);
}

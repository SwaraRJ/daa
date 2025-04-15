#include<stdio.h>
#include<stdlib.h>

void main()
{
  int A[3][3],B[3][3],C[3][3];
  int i,j;
  int P,Q,R,S,T,U,V;
  
  printf("\n Enter values of first matrix");
  for(i=1;i<=2;i++){
  for(j=1;j<=2;j++){
    printf("\n Enter element [%d][%d]:",i,j);
    scanf("%d",&A[i][j]);
   }
  }
  
  printf("\n Enter values of second matrix");
  for(i=1;i<=2;i++){
  for(j=1;j<=2;j++){
    printf("\n Enter element [%d][%d]:",i,j);
    scanf("%d",&B[i][j]);
   }
  }
  for(i=1;i<=2;i++){
   for(j=1;j<=2;j++){
   C[i][j]=0;
   }
  }
  
  P= (A[1][1] + A[2][2]) * (B[1][1] +B[2][2]);
  Q= (A[2][1] + A[2][2]) * B[1][1];
  R= A[1][1] * (B[1][2] - B[2][2]);
  S= A[2][2] * (B[2][1] - B[1][1]);
  T= (A[1][1] + A[1][2]) * B[2][2];
  U= (A[2][1] - A[1][1]) * (B[1][1] + B[1][2]);
  V= (A[1][2]-  A[2][2]) * (B[2][1] + B[2][2]);
  
  C[1][1] = P + S - T + V;
  C[1][2] = R + T;
  C[2][1] = Q + S;
  C[2][2] = P + R - Q + U;
  
  printf("\n multiplied matrix : \n");
  for(i=1;i<=2;i++)
  {
    printf("\t");
    for(j=1;j<=2;j++)
    {
      printf("%d ",C[i][j]); 
    }
    printf("\n");
  }  
  
}

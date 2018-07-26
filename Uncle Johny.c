#include <stdio.h>
int main(void) {
  int t,i,j,n,temp,K;
  scanf("%d",&t);
  while(t--){
      scanf("%d",&n);
      int A[n],a;//B[n];
      for(i=0;i<n;i++){
          scanf("%d",&A[i]);
      }
      scanf("%d",&K);
      a=A[K-1];
      for(i=0;i<n;i++){
          for (j = i+1; j < n; j++) {
              
              if(A[j]<=A[i]){
                  temp = A[j];
                  A[j]=A[i];
                 A[i]=temp;
              }
              /* code */
          }
      }
      for (i = 0; i < n; i++) {
          /* code */
          if(a==A[i]){
              K=i+1;
              break;
          }
      }
      printf("%d\n",K);
  }
	
	return 0;
}

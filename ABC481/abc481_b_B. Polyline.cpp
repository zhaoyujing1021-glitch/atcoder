#include <stdio.h>

int main(void){
  int n,m;
  int a[105];
  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  int count=0;
  for(int i=0;i<n;i++){
    if(a[i]==m){
      count++;
    }else if(i<n-1){
      if ((a[i] > m && a[i+1] < m) 
        || (a[i] < m && a[i+1] > m)) {
                count++;
          
        }
    }
  }  

    printf("%d",count);
  return 0;
}
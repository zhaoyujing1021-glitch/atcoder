#include <stdio.h>

int main(void){
  int n;
  int a[105];
  
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  int sum=0;
  for(int i=0;i<=n;i++){
    int count=0;
      for(int j=0;j<n;j++){
        if(a[j]>=i){
          count++;
        }
      }
      if(count>=i){
        sum=i;
      }else{
        break;
      }
  }
  
    printf("%d\n",sum);

  return 0;
}
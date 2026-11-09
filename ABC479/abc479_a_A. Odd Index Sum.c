#include <stdio.h>

int main(void){
  int n;
  int a[105];
  int num=0;
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
    if(i%2!=0){
      num+=a[i];
    }
  }
  printf("%d\n",num);
  
  return 0;
}
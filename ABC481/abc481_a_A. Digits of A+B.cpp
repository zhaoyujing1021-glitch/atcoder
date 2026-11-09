#include <stdio.h>

int main(void){
  int a,b;
  scanf("%d %d",&a,&b);
  int sum=a+b;
  if(sum/10 != 0){
    printf("2\n");
  }else{
    printf("1\n");
  }
  return 0;
}
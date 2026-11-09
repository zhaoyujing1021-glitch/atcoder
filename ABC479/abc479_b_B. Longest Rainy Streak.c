#include <stdio.h>
int main(void){
  int n;
  char a;
  int max=0;
  int c=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf(" %c",&a);
    if(a=='R'){
      c++;
      if(c>max){
        max=c;
      }
    }else{
      c=0;
    }
  }
  printf("%d\n",max);
  return 0;
}
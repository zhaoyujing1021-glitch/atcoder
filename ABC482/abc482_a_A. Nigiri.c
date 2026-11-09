#include <stdio.h>
#include <string.h>
int main(void){
  char a[15];
  scanf("%s",a);
  int c=0;
  int len=strlen(a);
  for(int i=0;i<len;i++){
    if(a[i]=='o'){
      c++;
    }
  }
  if(c%2==0){
    printf("even");
  }else{
    printf("odd");
  }
  return 0;
}
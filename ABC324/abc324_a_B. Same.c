#include <stdio.h>
int main(void){
  int a,b=0,c=0;
  scanf("%d",&a);
  scanf("%d",&b);
  for(int i = 1;i<a;i++){
scanf("%d",&c);
 if(c != b){
    printf("No\n");
    return 0;
}
}
printf("Yes\n");
  return 0;
}
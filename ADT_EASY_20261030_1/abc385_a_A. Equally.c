#include <stdio.h>

int main(void){
  int x,y,z;
  
  scanf("%d %d %d",&x,&y,&z);
  if(x==y&&y==z){
    printf("Yes");
  }else if(z==(x+y)||x==(z+y)||y==(x+z)){
    printf("Yes");
  }else{
    printf("No");
  }
  return 0;
}
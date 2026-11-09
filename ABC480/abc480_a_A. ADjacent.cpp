#include <stdio.h>

int main(void){
  char a[2][2];
  scanf("%s ",a[0]);
  scanf("%s ",a[1]);
  for(int i=0;i<2;i++){
      if(a[i][0]=='A'&&a[i][1]=='D'||a[i][0]=='D'&&a[i][1]=='A'){
          printf(" Yes\n");
          return 0;
      }
  }
  for(int j=0;j<2;j++){
    if ((a[0][j] == 'A' && a[1][j] == 'D') || (a[0][j] == 'D' && a[1][j] == 'A')) {
            printf("Yes\n");
            return 0;
        }
  }
  printf(" No\n");
  return 0;
}
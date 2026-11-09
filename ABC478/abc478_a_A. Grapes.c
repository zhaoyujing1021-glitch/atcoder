#include <stdio.h>
int main(void){
    int a,b; 
    int c=0,d=0;
    scanf("%d %d",&a,&b);
    c=b/a;
    d=b%a;
    for(int i=1;i<=a;i++){
        if(i<=d){
            printf("%d\n",c+1);
        }else{
            printf("%d\n",c);
        }
    }
    return 0;
}
#include <stdio.h>
int main(void){
    int a,b; 
    scanf("%d %d",&a,&b);
    int n[105];
    for(int i=1;i<=a;i++){
        scanf("%d",&n[i]);
    }
    int c=0,max=0;
    for(int i=1;i<=a;i++){
        for(int j=i+1;j<=a;j++){
            for(int z=j+1;z<=a;z++){

                if(i+j+z<=b){
                    c=n[i]+n[j]+n[z];
                    if(c>max){
                        max=c;
                    }
                }
            }
        }
    }
    printf("%d\n",max);
    return 0;
}
#include <stdio.h>

int main(void){
    int n;
    int a;
    int c=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(i>=n/2){
            c+=a;
        }
    }
    printf("%d\n",c);
    return 0;
}
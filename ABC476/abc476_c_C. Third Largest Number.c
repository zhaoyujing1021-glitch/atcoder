#include <stdio.h>

int main(void){
    int n;
    int a[500005];//N <= 5 * 10^5
    scanf(" %d",&n);
    for(int i=0;i<n;i++){
        scanf(" %d",&a[i]);
    }
    int t1=0;
    int t2=0;
    int t3=0;
    for(int i =0;i<n;i++){
        int x=a[i];

        if(x>t1){
            t3=t2;
            t2=t1;
            t1=x;
        }else if(x>t2){
            t3=t2;
            t2=x;
        }else if(x>t3){
            t3=x;
        }
        if(i>=2){
            printf("%d\n",t3);
        }
    }
    return 0;
}
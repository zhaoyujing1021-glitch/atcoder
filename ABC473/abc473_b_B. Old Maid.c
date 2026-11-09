#include <stdio.h>

int main(void){
    int n;
    int a;
    int b[105]={0};
    int sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        b[a]++;
    }
    for(int i=0;i<101;i++){
        if(b[i]%2!=0){
            sum+=i;
        }
    }
    printf("%d\n",sum);
    return 0;
}
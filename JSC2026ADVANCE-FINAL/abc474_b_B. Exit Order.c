#include <stdio.h>


int main(void){
    int a[105];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        int g = i / 10;
        int min= g * 10 + 1;
        int max = (g + 1) * 10;
        if (max > n) {
            max = n;
        }
        if (a[i] < min || a[i] > max) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;

}
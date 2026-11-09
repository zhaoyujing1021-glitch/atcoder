#include <stdio.h>
#include <stdlib.h>

int cmp_asc(const void *a,const void *b){
    int x=*(const int *)a;
    int y=*(const int *)b;

    if(x<y){
        return -1;
    }
    if(x>y){
        return 1;
    }
    return 0;

}
int main(void){
    int n,k; 
    scanf("%d %d",&n,&k);
    int a[200000];
    int b[200000];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    qsort(b,n,sizeof(int),cmp_asc);

    int l=-1,r=-1;

    for(int i=0;i<n;i++){
        if(a[i] != b[i]){
            if(l==-1){
                l=i; 
            }
            r=i;
        }
    }

    if(l==-1){
        printf("Yes");
    }else{
        if(r-l+1<=k){
            printf("Yes");
        }else{
            printf("No");
        }
    }
    return 0;
}
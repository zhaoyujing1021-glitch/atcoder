#include <stdio.h>
#include <stdlib.h>

struct A{
    int id;
    int x;
};


int cmp_x(const void *a,const void *b){
    struct A *p1=(const struct A*)a;
    struct A *p2=(const struct A*)b;

    if(p1->x < p2->x){
        return -1;
    }
    if(p1->x > p2->x){
        return 1;
    }
    return 0;
}
//int id(並び変えた後)　比較
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
    int n,d; 
    scanf("%d %d",&n,&d);
    struct A p[105];
    for(int i=0;i<n;i++){
        p[i].id=i+1;
        scanf("%d",&p[i].x);
    }
    qsort(p,n,sizeof(struct A),cmp_x);

    int output[105];
    int count=0;

    for(int i=0;i<n;i++){
        int ok=1;
        //左側から
        if(i>0){
            if(p[i].x-p[i-1].x<d){
                ok=0;
            }
        }
        //右側から
        if(i<n-1){
            if(p[i+1].x-p[i].x<d){
                ok=0;
            }
        }
        if(ok==1){
            output[count]=p[i].id;
            count++;
        }
    }
    //番号並び替え
    qsort(output,count,sizeof(int),cmp_asc);
    printf("%d\n",count);
    for(int i=0;i<count;i++){
        printf("%d\n",output[i]);
    }
    return 0;
}
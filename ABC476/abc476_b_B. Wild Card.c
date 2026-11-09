#include <stdio.h>

#include <string.h>

int main(void){
    int n;
    char s[105];
    char t[105];
    scanf(" %d",&n);
    scanf(" %s",s);
    scanf(" %s",t);
    for(int i= 0;i<n;i++){
        if(t[i]=='*'){

        }else if(t[i]==s[i]){

        }else{
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    
    return 0;
}
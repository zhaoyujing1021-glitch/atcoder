#include <stdio.h>
#include <string.h>
int main(void){
    char s[15];
    scanf("%s",s);
    int len = strlen(s);
    for(int i =0;i<len;i++){
        printf("%c",s[i]);
        if(i<len-1){
            printf("o");
        }
    }
    printf("\n");
    return 0;
}
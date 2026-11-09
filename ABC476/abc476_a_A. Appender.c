#include <stdio.h>
#include <string.h>
int main(void){
    char s[15];
    scanf(" %s",&s);
    int len=strlen(s);
    if(s[len-1]=='e'){
        printf("%sr\n", s);
    }else{
        printf("%ser\n", s);
    }
    
    return 0;
}
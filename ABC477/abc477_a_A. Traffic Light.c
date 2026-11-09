#include <stdio.h>

int main(void){
    char c;
    scanf(" %c",&c);
    if(c=='B'){
        printf("Y");
    }else if(c=='Y'){
        printf("R");
    }else{
        printf("B");
    }
    return 0;
}
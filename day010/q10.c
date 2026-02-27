#include <stdio.h>
#include <string.h>

int main(){
    char pall[50];
    char *p , *q;
    printf("enter a string: ");
    scanf("%s",pall);
    int len = strlen(pall);
    p = pall;
    q = &pall[len-1];
    for(int i = 0; i<len/2;i++){
        if(*(p+i) != *(q -i)){
            printf("it is not pallindrome");
            return 0;
        }
    }
    printf("it is pallindrome");
    return 0;

}
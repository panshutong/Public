#include<stdio.h>
#include<stdlib.h>
int main(){
    char *s=(char*)malloc(100);
    scanf("%s",s);
    printf("%s\n",s);
    free(s);
    return 0;
}
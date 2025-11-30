#include<stdio.h>
#include<string.h>
int main(){
    const char *s="Hi!";
    const char *t="Hhy?";
    if(*s==*t){ //仅仅比较第一个字母
        printf("Same");
    }
    else{
        printf("Different");
    }
    return 0;
}
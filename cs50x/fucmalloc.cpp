#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    
    const char *s="hello";
    char *t=(char*)malloc(strlen(s)+1);//c++中必须要转换
    if(t==NULL){
        return 1;
    }
    for(int i=0,k=strlen(s);i<=k;i++){
        t[i]=s[i];
    }
    if(strlen(t)>0){
        t[0]=toupper(t[0]);
    }
    printf("%s\n",s);
    printf("%s\n",t);
    free(t);
    
    return 0;
}
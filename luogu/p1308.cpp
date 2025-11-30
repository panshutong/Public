#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
    char tar[11];
    char t;
    int j=0;
    while(t=getchar(),t!=EOF&&j<11){
        if(t=='\n'){
            break;
        }
        tar[j++]=toupper(t);
    }
    tar[j]='\0';
    int lt=strlen(tar);
    char text[1000001];
    int i=0;
    char c;
    while(c=getchar(),c!='\n'&&i<1000001){
        if(c=='\n'){
            break;
        }
        text[i++]=toupper(c);
    }
    text[i]='\0';
    int times=0,first=0;
    for(int x=0;x<=i-lt;x++){
        if(text[x]==' '){
            continue;
        }
        int right=0;
        for(int y=0;y<lt;y++){
            if(text[x+y]==tar[y]){
                right++;
            }
            else{
                break;
            }
        }
        if(right==lt){
            bool left_ok=(x==0)||(text[x-1]==' ');
            bool right_ok=(x+lt==i||text[x+lt]==' ');
            if(left_ok&&right_ok){
                times++;
            }
        }
    }
    if(times!=0){
        printf("%d %d",times,first);
        return 0;
    }
    else{
        printf("-1");
    }
    return 0;
}
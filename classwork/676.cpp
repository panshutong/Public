#include <stdio.h>

void word(char *s){
    int times[26]={0};
    char *pointer=s;
    int isl=1;
    while(*pointer!='\0'){
        int num=0;
        if(*pointer>='a'&&*pointer<='z'){
            num=(int)(*pointer-'a');
        }
        else{
            num=(int)(*pointer-'A');
        }
        times[num]++;
        pointer++;
    }
    int maxnum=0,minnum=100;
    for(int i=0;i<26;i++){
        if(times[i]>=1){
            if(times[i]>maxnum){
                maxnum=times[i];
            }
            if(times[i]<minnum){
                minnum=times[i];
            }
        }
    }
    int checkans=maxnum-minnum;
    if(checkans<=1){
        printf("No Answer\n0");
        return;
    }
    else if(checkans==2){
        printf("Lucky Word\n%d",checkans);
        return;
    }
    
    else{
        
        if(checkans%2!=0){
            for(int j=3;j<checkans;j++){
                if(checkans%j==0){
                    isl=0;
                    break;
                }
            }
        }
        else{
            isl=0;
        }
    }
    if(isl==0){
        printf("No Answer\n0");
        return;
    }
    else{
        printf("Lucky Word\n%d",checkans);
        return;
    }
}
int main(void){
    char s[102];
    scanf("%s",s);
    word(s);
    return 0;
}

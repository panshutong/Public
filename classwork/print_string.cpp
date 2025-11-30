#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    char str[202],com[102];
    fgets(str,202,stdin);
    fgets(com,102,stdin);
    int num=2;
    while(num<101&&(com[num]!=' '&&com[num]!='\n')){
        num++;
    }
    num-=2;
    int num_1=0;
    if(com[num+2]==' '){
        num_1=2+num;
        while(com[num_1]!='\n'){
            num_1++;
        }
    }
    num_1-=num+3;
    int str_len=0;
    while(str[str_len]!='\n'){
        str_len++;
    }
    if(com[0]=='C'){
        int n=0;
        for(int i=0;i<str_len;i++){
            int right=0;
            for(int j=0;j<num;j++){
                if(str[i+j]==com[2+j]){
                    right++;
                }
                else{
                    break;
                }
            }
            if(right==num){
                n++;
                for(int j=0;j<num;j++){
                    str[i+j]='\0';
                }
            }
            
    
        }
        cout<<n<<endl;
        return 0;
    }
    if(com[0]=='D'){
        for(int i=0;i<str_len;i++){
            int right=0;
            for(int j=0;j<num;j++){
                if(str[i+j]==com[j+2]){
                    right++;
                }
                else{
                    break;
                }
            }
            if(right==num){
                int K;
                for(K=0;K<str_len;K++){
                    if(K!=i){
                        cout<<str[K];
                    }
                    else{
                        K=K+num-1;
                    }
                    
                }
                cout<<endl;
                return 0;
            }
            
        }
        for(int i=0;i<str_len;i++){
            cout<<str[i];
        }
        cout<<endl;
        return 0;
    }
    if(com[0]=='I'){
        int times=-1;
        for(int i=0;i<str_len;i++){
            int right=0;
            
            for(int j=0;j<num;j++){
                if(str[i+j]==com[2+j]){
                    right++;
                }
                else{
                    break;
                }
            }
            if(right==num){
                times=i;
            }

        }
        if(times>=0){
            for(int i=0;i<str_len;i++){
                if(i<times||i>times){
                    cout<<str[i];
                }
                else{
                    for(int m=0;m<num_1;m++){
                        cout<<com[3+num+m];
                    }
                    cout<<str[times];
                }
            }
            return 0;
        }
        else{
            for(int i=0;i<str_len;i++){
                cout<<str[i];
            }
            return 0;
        }
        
    }
    if(com[0]=='R'){
        int x=0;
        for(int i=0;i<str_len;i++){
            int right=0;
            for(int j=0;j<num;j++){
                if(str[i+j]==com[j+2]){
                    right++;
                }
                else{
                    break;
                }
            }
            if(right==num){
                str[i]='?';
                for(int j=i+1;j<i+num;j++){
                    str[j]='!';
                }
                
                x++;
            }
            
        }
        if(x==0){
            for(int i=0;i<str_len;i++){
                cout<<str[i];
            }
            return 0;
        }
        else{
            if(num>=num_1){
                for(int i=0;i<str_len;i++){
                    if(str[i]=='?'){
                        for(int m=0;m<num_1;m++){
                            str[i+m]=com[3+num+m];
                        }
                    }
                }
                for(int f=0;f<str_len;f++){
                    if(str[f]!='!'){
                        cout<<str[f];
                    }
                }
                return 0;
            }
            else{
                char str_1[400];
                int y=0;
                for(int i=0;i<str_len+1;i++){
                    if(str[i]!='?'){
                        str_1[y]=str[i];
                        y++;
                    }
                    else{
                        for(int m=0;m<num_1;m++){
                            
                            str_1[y+m]=com[3+num+m];
                            
                        }
                        y+=num_1;
                    }
                }
                for(int e=0;str_1[e]!='\n';e++){
                    if(str_1[e]!='!'){
                        cout<<str_1[e];
                    }
                }
                return 0;
            }
        }
    }
}

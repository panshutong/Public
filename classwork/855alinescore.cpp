#include<iostream>
#include<cstring>
using namespace std;
typedef struct{
    char in[100];
    int len=0;
}score;
int compar(char num1[],char num2[],char sam[],int x,int y){
    for(int i=0;i<x;i++){
        if(num1[i]==num2[i]){
            continue;
        }
        else{
            int a=-1,b=-1;
            for(int j=0;j<y;j++){
                if(a!=-1&&b!=-1){
                    break;
                }
                if(num1[i]==sam[j]){
                    a=j;
                    
                }
                if(num2[i]==sam[j]){
                    b=j;
                    
                }
            }
            if(a>b){
                return 1;
            }
            else{
                return -1;
            }
        }
    }
    return 0;
}
int main(){
    int n;
    char sam[25]={0};
    score s[100];
    cin>>n>>sam;
    int y=strlen(sam);
    for(int i=0;i<n;i++){
        cin>>s[i].in;
        s[i].len=strlen(s[i].in);
        if(s[i].in[0]==sam[0]){
            int de=0;
            while(s[i].in[de]==sam[0]){
                de++;
            }
            char mid[100]={0};
            strncpy(mid,s[i].in+de,s[i].len);
            strcpy(s[i].in,mid);
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(s[i].len<s[j].len){
                score midd=s[i];
                s[i]=s[j];
                s[j]=midd;
            }
            else if(s[i].len==s[j].len){
                int b=compar(s[i].in,s[j].in,sam,s[i].len,y);
                    if(b==-1){
                        score middd=s[i];
                        s[i]=s[j];
                        s[j]=middd;
                    }
                
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<s[i].in<<' ';
    }
    cout<<'\n';
    long long ans=0;
    for(int i=0;i<s[n-1].len;i++){
        ans*=y;
        int m;
        for(m=0;m<y;m++){
            if(sam[m]==s[n-1].in[i]){
                break;
            }
        }
        ans+=m;
    }
    cout<<ans;
    return 0;
}
#include<iostream>
#include<cstring>
using namespace std;
int addingnumber(int i,int m,char s[],int gap,int flag[],int tmpans,int ans){
    if(i==m){
        int seperate[15]={0};
        int y=0;
        for(int j=0;j<gap;j++){
            if(flag[j]==1){
                seperate[y]=j;
                y++;
            }
        }
        for(int j=0;j<y;j++){
            if(j==0){
                int num=0;
                for(int k=0;k<=seperate[j];k++){
                    num=num*10+(s[k]-'0');
                }
                tmpans+=num;
            }
        
            else{
                int num=0;
                for(int k=seperate[j-1]+1;k<=seperate[j];k++){
                    num=num*10+(s[k]-'0');
                }
                tmpans+=num;
            }
        }
        int num=0;
        for(int k=seperate[y-1]+1;k<strlen(s);k++){
            num=num*10+(s[k]-'0');
        }
        tmpans+=num;
        if(tmpans>ans){
            ans=tmpans;
        }
        tmpans=0;
        return ans;
    }
    else{
        for(int j=0;j<gap;j++){
            if(flag[j]==0){
                flag[j]=1;
                int mid=addingnumber(i+1,m,s,gap,flag,tmpans,ans);
                ans=mid;
                flag[j]=0;
            }
        }
        return ans;
    }
}
char s[16];
int main(){
    int m=0;
    cin>>m>>s;
    int gap=strlen(s)-1;
    int flag[14]={0};
    int ans=0,tmpans=0;
    ans=addingnumber(0,m,s,gap,flag,tmpans,ans);
    cout<<ans;
    return 0;
}
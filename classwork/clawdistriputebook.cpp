#include<iostream>
using namespace std;
int ans[5]={0};
int flag[5]={0};
int like[5][5]={{0,1,1,0,1},
                {1,0,0,1,0},
                {1,1,0,0,1},
                {0,1,1,0,0},
                {1,0,1,1,0}};
void trybook(int i,int k,int flag[5],int ans[]){
    if(i==k){
        for(int j=0;j<5;j++){
            cout<<j<<':'<<ans[j]<<' ';

        }
        cout<<'\n';
        return;
    }
    for(int j=0;j<5;j++){
        if(like[i][j]==1&&flag[j]==0){
            flag[j]=1;
            ans[i]=j;
        }
        else{
            continue;
        }
        trybook(i+1,k,flag,ans);
        flag[j]=0;
        
        
    }
    return;
}
int main(){
    trybook(0,5,flag,ans);
    return 0;
}
#include<iostream>
using namespace std;
int like[10][10]={0};
int flag[10]={0};
int ans[5000][10]={0};
int tmpans[10]={0};
int deliverbook(int i,int n,int like[][10],int flag[],int ans[][10],int times,int tmpans[]){
    
    if(i==n){
        for(int j=0;j<n;j++){
            ans[times][j]=tmpans[j];
        }
        times++;
        return times;
    }
    for(int j=0;j<n;j++){
        if(like[i][j]==1&&flag[j]==0){
            flag[j]=1;
            tmpans[i]=j;
            int mid=deliverbook(i+1,n,like,flag,ans,times,tmpans);
            times=mid;
            
            flag[j]=0;
        }
        else{
            continue;
        }
    }
    return times;
}
int main(){
    int n=0;
    cin>>n;
    
    char tmp_input[10][11]={0};
    for(int i=0;i<n;i++){
        cin>>tmp_input[i];
        for(int j=0;j<n;j++){
            like[i][j]=(int)(tmp_input[i][j]-'0');
        }
    }
    int i=0;
    int times=0;
    int final_times=deliverbook(i,n,like,flag,ans,times,tmpans);
    if(final_times==0){
        cout<<"NO";
        return 0;
    }
    cout<<final_times<<'\n';
    for(int i=0;i<final_times;i++){
        for(int j=0;j<n;j++){
            cout<<'B'<<ans[i][j]+1;
        }
        cout<<'\n';
    }
    return 0;
}
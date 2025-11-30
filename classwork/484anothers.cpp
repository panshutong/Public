#include<iostream>
using namespace std;
int ans[1000000]={0};
int N=100000;
int main(){
    int n;
    cin>>n;
    int num;
    
    for(int i=0;i<n;i++){
        cin>>num;
        ans[num+N]++;
    }
    int flag=0;
    for(int i=0;i<1000000;i++){
        if(ans[i]!=1&&ans[i]!=0){
            flag=1;
            cout<<i-N<<":"<<ans[i]<<'\n';
        }
    }
    if(flag==0){
        cout<<"NO";
        
    }
    return 0;
}
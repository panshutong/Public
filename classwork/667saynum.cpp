#include<iostream>
using namespace std;
int main(){
    int m,n;
    cin>>n>>m;
    int num[4]={0};
    int rank=1;
    int flag=0;
    while(rank<=n){
    for(int i=0;i<4;i++){
        if(rank>n){
            flag=1;
            break;
        }
        if(rank%m==0){
            num[i]++;
        }
        rank++;
    }
    if(flag==1){
        break;
    }
}
    
    cout<<num[0]<<' '<<num[1]<<' '<<num[2]<<' '<<num[3]<<'\n';
    return 0;
}
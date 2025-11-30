#include<iostream>
using namespace std;
int main(){
    int l=0,m=0;
    cin>>l>>m;
    int num[100][2]={0};
    int flag[l+1]={0};
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            cin>>num[i][j];
        }
        for(int k=num[i][0];k<=num[i][1];k++){
            flag[k]=1;
        }
    }
    int sum=0;
    for(int i=0;i<=l;i++){
        if(flag[i]==0){
            sum++;
        }
    }
    cout<<sum<<endl;
    return 0;
}
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int matr[100][100]={0};
    int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    int t=0;
    int rank=1;
    int ans[n][n]={0};
    for(t=0;t<n;t++){
        if(t==0){
            ans[0][0]=rank;
            rank++;
        }
        else if(t%2==1){
            for(int i=0;i<t;i++){
                ans[i][t]=rank;
                rank++;
            }
            
            for(int i=t;i>=0;i--){
                ans[t][i]=rank;
                rank++;
            }
        }
        else{
            for(int i=0;i<t;i++){
                ans[t][i]=rank;
                rank++;
            }
            for(int i=t;i>=0;i--){
                ans[i][t]=rank;
                rank++;
            }
        }
        
    }
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            if(j!=t-1){
                cout<<ans[i][j]<<' ';
            }
            else{
                cout<<ans[i][j]<<'\n';
            }
        }
    }
    return 0;
}
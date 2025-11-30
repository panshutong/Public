#include<iostream>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int num[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>num[i][j];
        }
    }
    int tnum[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            tnum[i][j]=num[j][i];
            if(j!=m-1){
                cout<<tnum[i][j]<<" ";
            }
            else{
                cout<<tnum[i][j]<<'\n';
            }
        }
    }
    return 0;
}
#include<iostream>
using namespace std;
int travel[8][8]={0};
int step[8][8]={0};
int dir[3][2]={{1,0},{0,1},{0,-1}};
int max_trea=-1000;
int curr_trea=0;
void starttravel(int i,int j,int n,int m){
    if(i==n-1&&j==m-1){
        if(curr_trea>max_trea){
            max_trea=curr_trea;
        }
        return;
        
    }
    else{
    for(int d=0;d<3;d++){
        int ni=i+dir[d][0];
        int nj=j+dir[d][1];
        if(ni<0||ni>=n||nj<0||nj>=m||step[ni][nj]!=0){
            continue;
        }
        curr_trea+=travel[ni][nj];
        step[ni][nj]=1;
        starttravel(ni,nj,n,m);
        step[ni][nj]=0;
        curr_trea-=travel[ni][nj];
    }
}
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>travel[i][j];
        }
    }
    curr_trea+=travel[0][0];
    step[0][0]=1;
    starttravel(0,0,n,m);
    cout<<max_trea;
    return 0;
}
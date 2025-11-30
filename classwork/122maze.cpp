#include<iostream>
using namespace std;
int maze[11][11]={0};
int step[11][11]={0};
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int found=0;
void startmaze(int i,int j,int n,int m){
    if(found==1){
        return;
    }
    for(int d=0;d<4;d++){
        int ni=i+dir[d][0];
        int nj=j+dir[d][1];
        if(maze[ni][nj]==1&&step[ni][nj]==0){
            if(ni==n&&nj==m){
                cout<<"YES";
                found=1;
                return;
            }
            step[ni][nj]=1;
            startmaze(ni,nj,n,m);
            step[ni][nj]=0;
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            cin>>maze[i][j];
        }
    }
    startmaze(1,1,n,m);
    if(found==0){
        cout<<"NO";
    }
    return 0;
}
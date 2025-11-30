#include<iostream>
using namespace std;
int skii[52][52]={0};
int times[52][52]={0};
int max_len=0;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int startSkii(int i,int j){
    if(times[i][j]!=0){
        return times[i][j];
    }
    int len=1;
    for(int d=0;d<4;d++){
        int ni=i+dir[d][0];
        int nj=j+dir[d][1];
        if(skii[ni][nj]<skii[i][j]){
            int next_len=startSkii(ni,nj);
            if(len<next_len+1){
                len=next_len+1;
            }
        }
    }
    times[i][j]=len;
    if(max_len<len){
        max_len=len;
    }
    return len;

}
int main(){
    int C,R;
    cin>>R>>C;
    for(int i=1;i<R+1;i++){
        for(int j=1;j<C+1;j++){
            cin>>skii[i][j];
        }
    }
    for(int j=0;j<C+2;j++){
        skii[0][j]=10001;
        skii[R+1][j]=10001;
    }
    for(int i=0;i<R+2;i++){
        skii[i][0]=10001;
        skii[i][C+1]=10001;
    }
    for(int i=1;i<R;i++){
        for(int j=1;j<C;j++){
            int mid=startSkii(i,j);
        }
    }
    cout<<max_len;
    return 0;
}
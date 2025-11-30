#include<iostream>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int matr[100][100];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matr[i][j];
        }
    }
    int max=-1;
    int dir[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
    int ans[100][100];
    int times=0;
    int output[100][2];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int temp=0;
            int sum=matr[i][j];
            for(int d=0;d<4;d++){
                int ni=i+dir[d][0];
                int nj=j+dir[d][1];
                if(ni!=-1&&ni!=m&&nj!=-1&&nj!=n){
                    sum+=matr[ni][nj];
                }
            }
            ans[i][j]=sum;
            if(sum>max){
                max=sum;
                times=0;
                output[times][0]=i;
                output[times][1]=j;
                times++;
            }
            else if(sum==max){
                output[times][0]=i;
                output[times][1]=j;
                times++;
            }
        }
    }
    cout<<max<<' '<<times<<'\n';
    for(int i=0;i<times;i++){
        cout<<output[i][0]<<' '<<output[i][1]<<'\n';
    }
    return 0;
}
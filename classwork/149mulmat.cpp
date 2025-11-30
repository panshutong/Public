#include<iostream>
using namespace std;
int main(){
    int m,n,p;
    cin>>n>>p>>m;
    int matr1[5][5]={0};
    int matr2[5][5]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            cin>>matr1[i][j];
        }
    }
    for(int i=0;i<p;i++){
        for(int j=0;j<m;j++){
            cin>>matr2[i][j];
        }
    }
    int ans[5][5]={0};
    int j=0;
    for(int i=0;i<n;i++){

        for(j=0;j<m;j++){
            int temp=0;
            for(int x=0;x<p;x++){
                temp+=matr1[i][x]*matr2[x][j];
            }
            ans[i][j]=temp;
            
        }
    }
    for(int i=0;i<n;i++){
        int times=0;
        for(j=0;j<m;j++){
            cout<<ans[i][j];
            if(times!=m-1){
            cout<<' ';
            times++;
        }
        else{
            cout<<'\n';
        }
        }
        
    }
    return 0;

}
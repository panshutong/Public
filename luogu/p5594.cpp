#include<iostream>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int peo[n][m];
    int num[n][k]={0};
    for(int i=0;i<n;i++){
        int x=1;
        for(int j=0;j<m;j++){
            cin>>peo[i][j];
        }
        for(int y=0;y<k;y++){
            num[i][y]=0;  //people i day y problem set num[i][y]=1,2,3....
        }
        for(int j=0;j<m;j++){
            num[i][peo[i][j]-1]=x;
            x++;
        }
    }
    int day[k]; //total k days
    for(int i=0;i<k;i++){
        day[i]=0;
    }
    for(int i=0;i<k;i++){  //each day
        int flag[m]={0};  //the problem set
        for(int j=0;j<n;j++){  //each person
            
            if(num[j][i]!=0){
                flag[num[j][i]-1]=1;
                
            }
        }
        int d=0;
        for(int y=0;y<m;y++){
            
            if(flag[y]==1){
                d++;              
            }
        }
        day[i]=d;
    }
    for(int i=0;i<k-1;i++){
        cout<<day[i]<<" ";
    }
    cout<<day[k-1];
    return 0;
    

}
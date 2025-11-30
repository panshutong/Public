#include<iostream>
using namespace std;
int classroom[1000][1000]={0};
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>classroom[i][j];
        }
    }
    int num=0;
    int columnis1[1000]={0};
    
    int y=0;
    for(int c=0;c<m;c++){
        if(classroom[0][c]==1){
            columnis1[y]=c;
            y++;
        }
    }
    int graph1,graph2;
    if(n%2==1){
        graph1=(n+1)/2;
        graph2=n/2;
    }
    else{
        graph1=n/2;
        graph2=graph1;
    }
    if(y==0){
        num+=(m/2)*(graph1+graph2);
        if(m%2!=0){
            num+=graph1;
        }
        cout<<num;
        return 0;

    }
    int a=columnis1[0]-0;
    num+=(a/2)*(graph1+graph2);
    if(a%2!=0){
        num+=graph1;
    }
    for(int m=0;m<y-1;m++){
        a=columnis1[m+1]-columnis1[m]-1;
        num+=(a/2)*(graph1+graph2);
        if(a%2!=0){
            num+=graph1;
        }
    }
    a=m-columnis1[y-1]-1;
    num+=(a/2)*(graph1+graph2);
    if(a%2!=0){
        num+=graph1;
    }
    cout<<num;
    return 0;
}
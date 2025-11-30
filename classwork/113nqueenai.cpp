#include<iostream>
#include<cmath>
using namespace std;
int pos[15]={0};
int ans=0;
bool isSafe(int row,int col,int pos[]){
    for(int i=0;i<row;i++){
        if(pos[i]==col||abs(pos[i]-col)==abs(i-row)){
            return false;
        }
    }
    return true;
}
void putqueen(int row,int n,int pos[]){
    if(row==n){
        ans++;
        return;
    }
    else{
        for(int col=0;col<n;col++)
        if(isSafe(row,col,pos)){
            pos[row]=col;
            putqueen(row+1,n,pos);
            pos[row]=-1;
        }
    }
}
int main(){
    int n=0;
    cin>>n;
    int row=0;
    putqueen(row,n,pos);
    cout<<ans;
    return 0;
}
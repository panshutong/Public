#include<iostream>
using namespace std;
int pos[15];
bool conflict(int pos[],int n){
    for(int j=0;j<n;j++){
        for(int m=0;m<n;m++){
            if(broad[j][m]==1){
                for(int k=0;k<n;k++){
                    if(k!=m&&broad[j][k]==1){
                        return 1;
                    }
                    if(k!=j&&broad[k][m]==1){
                        return 1;
                    }
                }
                for(int x=-n;x<n;x++){
                    if(j+x>=0&&j+x<n&&m+x>=0&&m+x<n){
                        if(x!=0&&broad[j+x][m+x]==1){
                            return 1;
                        }
                    }
                    if(j+x>=0&&j+x<n&&m-x>=0&&m-x<n){
                        if(x!=0&&broad[j+x][m-x]==1){
                            return 1;
                        }
                    }
                }
                
            }
        }
    }
    return 0;
}
int putqueen(int broad[][12],int i,int n,int num){
    if(i==n){
        num++;
        return num;
    }
    else{
        for(int j=0;j<n;j++){
            for(int m=0;m<n;m++){
                if(broad[j][m]!=1){
                    broad[j][m]=1;
                    if(comflict(broad,n)==0){
                        int mid=putqueen(broad,i+1,n,num);
                        num=mid;
                        broad[j][m]=0;
                    }
                    else{
                        broad[j][m]=0;
                    }
                }
            }
        }
    }
    return num;
}
int main(){
    int n=0;
    cin>>n;
    int i=0;
    int num=0;
    num=putqueen(broad,i,n,num);
    cout<<num;
    return 0;
}
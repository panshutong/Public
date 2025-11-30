#include<iostream>
using namespace std;
int main(){
    int a,b,n,k,m;
    cin>>a>>b>>n>>k>>m;
    int i=0;
    int j=0;
    int num=0;
    for(i=a;i<=b;i++){
        int mid=i;
        if(mid%10==n){
            if(mid%k==0){
                while(mid!=0){
                    mid/=10;
                    j++;
                }
                    if(j==m){
                        
                        num++;
                    }
                
            }
        }
        j=0;

    }
    cout<<num<<endl;
    return 0;
}
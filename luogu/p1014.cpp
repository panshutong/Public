#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i,s=0;
  
    
    for(i=1;s<n;i++){
        s+=i;
    }
    int k=0;
    if((i-1)%2==0){
        if(s==n){
            cout<<i-1<<'/'<<1<<endl;
            return 0;
        }
        k=s-n;
        cout<<i-k-1<<'/'<<1+k<<endl;
    }
    else{
        if(s==n){
            cout<<1<<'/'<<i-1<<endl;
            return 0;
        }
        k=s-n;
        cout<<1+k<<'/'<<i-k-1<<endl;
    }
    return 0;
    
}
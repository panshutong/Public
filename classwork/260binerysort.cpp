#include<iostream>
using namespace std;

int main(){
    int n=0;
    long long num=0;
    cin>>n>>num;
    long long sort[n];
    for(int i=0;i<n;i++){
        cin>>sort[i];
    }
    for(int j=0;j<n;j++){
        for(int k=j+1;k<n;k++){
            if(sort[k]<sort[j]){
                long long mid=sort[j];
                sort[j]=sort[k];
                sort[k]=mid;
            }
        }
    }
    int k,times=0;
    int a=0,b=n-1;
    while(a<=b){
        k=(a+b)/2;
        if(num==sort[k]){
        times++;
        cout<<k<<endl<<times;
        return 0;
    }
    else if(num>sort[k]){
        a=k+1;
        times++;
    }
    else{
        b=k-1;
        times++;
    }
    }
    cout<<-1<<endl<<times;
    return 0;
    
}


 
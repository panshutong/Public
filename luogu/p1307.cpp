#include<iostream>
using namespace std;
int main(){
    long long n=0;
    long long k=0;
    cin>>n;
    long long mid=n;
    int num[20]={0};
    int i=0;
    while(mid!=0){
        num[i]=mid%10;
        if(num[i]<0){
            num[i]=-num[i];
        }
        mid/=10;
        i++;
    }
    if(n==0){
        cout<<0<<endl;
    }
    else{
        if(n<0){
            cout<<'-';
        }
    for(int j=0;j<i;j++){
        
        k=k*10+num[j];
    }

    cout<<k<<endl;
    }
    return 0;
}


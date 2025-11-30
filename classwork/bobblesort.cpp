#include<iostream>
using namespace std;
int main(){
    long long num[1000]={0};
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
        
    }
    int swap=-1;
    while(swap!=0){
        swap=0;
        for(int i=0;i<n-1;i++){
            if(num[i]>num[i+1]){
            long long temp=num[i+1];
            num[i+1]=num[i];
            num[i]=temp;
            swap++;
            }
        }
    }
    for(int i=0;i<n-1;i++){
        cout<<num[i]<<" ";
    }
    cout<<num[n-1]<<endl;
    return 0;
    

}
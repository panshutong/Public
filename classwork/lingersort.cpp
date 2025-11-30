#include<iostream>
using namespace std;
int main(){
    long long num[1000]={0};
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
        
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(num[j]<=num[i]){
                int mid=num[i];
                num[i]=num[j];
                num[j]=mid;
            }
        }
    }
    for(int i=0;i<n-1;i++){
        cout<<num[i]<<" ";
    }
    cout<<num[n-1]<<endl;
    return 0;
}
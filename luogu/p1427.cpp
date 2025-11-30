#include<iostream>
using namespace std;
int main(){
    long long a[100]={0};
    int i=0;
    for(i=0;i<100;i++){
        cin>>a[i];
        if(a[i]==0){
            break;
        }
    }
    for(int j=i-1;j>0;j--){
        cout<<a[j]<<" ";
    }
    cout<<a[0]<<endl;
    return 0;
}
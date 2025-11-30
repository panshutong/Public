#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    char c;
    if(n<=9){
        c=(char)('0'+n);
    }
    else{
        c=(char)('A'+(n-10));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<' ';
        }
        for(int j=0;j<n-i-1;j++){
            cout<<c;
        }
        for(int j=0;j<n-i;j++){
            cout<<c;
        }
        cout<<'\n';
    }
    return 0;
}
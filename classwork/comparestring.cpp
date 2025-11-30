#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    char a[102],b[102];
    int i=0,j=0;
    fgets(a,102,stdin);
    fgets(b,102,stdin);
    for(i=0;i<102;i++){
        if(a[i]!=b[i]){
            cout<<(int)(a[i]-b[i])<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
    
}
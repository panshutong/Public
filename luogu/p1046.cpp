#include<iostream>
using namespace std;
int main(){
    int num[10]={0};
    for(int i=0;i<10;i++){
        cin>>num[i];
    }
    int n=0;
    cin>>n;
    int m=0;
    for(int j=0;j<10;j++){
        if(num[j]<=(n+30)){
            m++;
        }
    }
    cout<<m<<endl;
    return 0;
}
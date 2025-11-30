#include<iostream>
using namespace std;
int main(){
    int num=0;
    cin>>num;
    int mid=num;
    int x=0;
    int a[10]={0};
    while(mid!=0){
        a[x]=mid%10;
        mid/=10;
        cout<<a[x]<<",";
        x++;
    }
    cout<<x;
    if(num==0){
        cout<<','<<1;
    }
    return 0;
}
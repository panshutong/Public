#include<iostream>
using namespace std;
int GCD(int a,int b){
    int ans=0;
    if(a==0||b==0){
        return max(a,b);
    }
    else{
        if(a>b) a%=b;
        else if(a<b) b%=a;
        else return a;
        return GCD(a,b);
    }
}
int main(){
    cout<<GCD(3,3);
    return 0;
}
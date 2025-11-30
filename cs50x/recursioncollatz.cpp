#include<iostream>
using namespace std;
int collatz(int n,int stp);
int main(){
    int n=0;
    cin>>n;
    int stp=0;
    
    cout<<collatz(n,stp)<<endl;
    return 0;
}
int collatz(int n,int stp){
    
    if(n==1){
        return stp;
    }
    else if(n%2==0){
        stp++;
        return collatz(n/2,stp);
    }
    else{
        stp++;
        return collatz(3*n+1,stp);
    }
}
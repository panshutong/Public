#include<iostream>
using namespace std;
int arr(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        return arr(n-1)+arr(n-2);
    }
}
int main(){
    cout<<arr(10);
    return 0;
}
#include<iostream>
using namespace std;
int cal(int a,int b);
int main(){
    int a=0,b=0;
    cin>>a>>b;
    cout<<cal(a,b)<<endl;
    return 0;
}
int cal(int a,int b){
    int outcome=0,mid=1;
    if(a==1){
        return 1;
    }
    else{
        for(int i=0;i<b;i++){
            mid*=a;
        }
        return cal(a-1,b)+mid;
        
    }
    
}
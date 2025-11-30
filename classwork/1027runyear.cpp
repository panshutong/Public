#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int times=0;
    for(int i=a;i<=b;i++){
        if(i%4==0){
            if(i%100==0){
                if(i%400==0){
                    times++;
                }
                
            }
            else{
                times++;
            }
        }
    }
    cout<<times;
    return 0;
}
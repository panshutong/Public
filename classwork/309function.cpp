#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int main(){
    float x=0;
    cin>>x;
    if(x<0){
        printf("%.2f",(-1.0)*x);
        
    }
    else if(x>=0&&x<=1){
        printf("%.2f",sqrt(x));
    }
    else{
        printf("%.2f",x*x*1.0);
    }
    return 0;
}
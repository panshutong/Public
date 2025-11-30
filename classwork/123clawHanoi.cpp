#include<iostream>
#include<stdio.h>
using namespace std;
int move(int n,char a,char b,char c,int step){
    
    if(n==1){
        
        printf("[step %d] move plate %d# from %c to %c\n",step,n,a,c);
        step++;
        return step;
        
    }
    else{
        step=move(n-1,a,c,b,step);
        
        printf("[step %d] move plate %d# from %c to %c\n",step,n,a,c);
        step++;
        int tmp=0;
        tmp=move(n-1,b,a,c,step);
        step=tmp;
        return step;
        
    }
}
int main(){
    int n=0;
    int step=1;
    cin>>n;
    step=move(n,'a','b','c',step);
    cout<<step-1;
    return 0;
}
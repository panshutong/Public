#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    char str[1010];
    int i=0;
    fgets(str,1010,stdin);
    while(str[i]!='\0'){
        i++;
    }
    i-=1;
    int n=0;
    int right=0;
    if(i==0){
        cout<<"No"<<endl;
        return 0;
    }
    if((i+1)%2==0){
        n=(i+1)/2;
        for(int j=0;j<n;j++){
            if(str[0+j]==str[i-j]){
                right++;
            }
        }
    }
    else{
        n=i/2;
        for(int j=0;j<n;j++){
            if(str[0+j]==str[i-j]){
                right++;
            }
        }
    }
    if(right==n){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    return 0;

}
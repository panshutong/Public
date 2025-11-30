#include<iostream>
#include<string>
#include<cstdlib>
#include<stdio.h>
using namespace std;
typedef struct{
    long long num;
    double mul;
}period;
int main(){
    int n;
    cin>>n;
    period p[100];
    for(int i=0;i<n;i++){
        cin>>p[i].num;
        cin>>p[i].mul;
    }
    string input;
    long long mon=0;
    cin>>input;
    if(input[0]=='N'){
        cout<<"NO";
        return 0;
    }
    else{
        mon=stol(input);
    }

    int max=0;
    for(int i=0;i<n;i++){
        if(p[i].num<=mon){
            max=i;
        }
        else{
            break;
        }
    }
    double ans=0;
    if(max<n-1){
    for(int i=0;i<=max;i++){
        if(i==0){
            ans+=p[i].num*p[i].mul;
        }
        else{
            ans+=(p[i].num-p[i-1].num)*p[i].mul;
        }
    }
    ans+=(mon-p[max].num)*p[max+1].mul;
}
    else{
        if(n==1){
            ans=mon*p[0].mul;
            printf("%.2lf",ans);
    return 0;
        }
        for(int i=0;i<n-1;i++){
            if(i==0){
                ans+=p[i].num*p[i].mul;
            }
            else{
            ans+=(p[i].num-p[i-1].num)*p[i].mul;
        }
        }
        ans+=(mon-p[n-2].num)*p[n-1].mul;
    }
    printf("%.2lf",ans);
    return 0;

}
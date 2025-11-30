#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
typedef struct{
    int r;
    double a;
    double b;
    double s;
}goods;
goods g[10000];
int main(){
    int n;
    cin>>n;
    
    int fa=0;
    for(int i=0;i<n;i++){
        cin>>g[i].r;
        cin>>g[i].a;
        cin>>g[i].b;
        g[i].s=g[i].b-g[i].a;
        if(g[i].s>=0){
            fa++;
        }
    }
    double per=fa/(n*1.0)*100;
    for(int i=0;i<n;i++){
        if(g[i].s>=0){
            cout<<g[i].r<<" ";
            printf("%.2lf\n",g[i].s);
        }
    }
    char c='%';
    printf("%.2lf%c",per,c);
    return 0;
}
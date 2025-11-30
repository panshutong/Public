#include<iostream>
#define PI 3.141592
using namespace std;

long double g_fact(int m);
long double g_pow(long double x,int m);
int main(){
    long double x,epxi;
    cin>>x>>epxi;
    long double y=0,z=0;
    while(x>2*PI){
        x-=2*PI;
    }
    
    
    int rank=1;
    
    int m=1;
    do{
        if(rank%2==1){
        y+=g_pow(x,m)/g_fact(m);
        rank++;
        m+=2;
        }
        else{
            y-=g_pow(x,m)/g_fact(m);
            rank++;
            m+=2;
        }
    }while(g_pow(x,m+1)/g_fact(m)>=epxi);
    cout<<y<<endl;
    rank=1;
    m=0;
    do{
        if(rank%2==1){
        z+=g_pow(x,m)/g_fact(m);
        rank++;
        m+=2;
        }
        else{
            z-=g_pow(x,m)/g_fact(m);
            rank++;
            m+=2;
        }
    }while(g_pow(x,m+1)/g_fact(m)>=epxi);
    cout<<z<<endl;
    return 0;
    
    

    
}

long double g_fact(int m){
    long double n=1;
    for(int i=1;i<=m;i++){
        n*=i;
    }
    return n;
}
long double g_pow(long double x,int m){
    int i=0;
    long double f=1;
    for(i=0;i<m;i++){
        f*=x;
    }
    return f;

}

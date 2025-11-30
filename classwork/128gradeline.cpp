#include<iostream>
using namespace std;
typedef struct{
    int k=0;
    int s=0;
    int rank=0;
}par;
int main(){
    int n,m;
    cin>>n>>m;
    float m_=m*1.5;
    int g_m=m_/1;
    par pers[n];
    for(int i=0;i<n;i++){
        cin>>pers[i].k>>pers[i].s;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(pers[j].s>pers[i].s){
                par mid=pers[i];
                pers[i]=pers[j];
                pers[j]=mid;
            }
            else if(pers[j].s==pers[i].s&&pers[j].k<pers[i].k){
                par mid_=pers[i];
                pers[i]=pers[j];
                pers[j]=mid_;
            }
        }
    }
    pers[0].rank=1;
    for(int i=1;i<n;i++){
        if(pers[i].s==pers[i-1].s){
            pers[i].rank=pers[i-1].rank;
        }
        else{
            pers[i].rank=pers[i-1].rank+1;
        }
    }
    while(pers[g_m-1].s==pers[g_m].s){
        g_m++;
    }
    cout<<pers[g_m-1].s<<" "<<g_m<<endl;
    for(int i=0;i<g_m;i++){
        cout<<pers[i].k<<" "<<pers[i].s<<endl;
    }
    return 0;
}
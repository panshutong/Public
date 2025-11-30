#include<iostream>
#include<cmath>
using namespace std;
typedef struct{
    int len;
    int p[100];
    int period[16]={0};
}song;
double pow(int a,int b){
    return (a-b)*(a-b);
};
int main(){
    //freopen("error (2).in","r",stdin);
    song sample;
    cin>>sample.len;
    for(int i=0;i<sample.len;i++){
        cin>>sample.p[i];
        int mid=sample.p[i]/16;
        sample.period[mid]++;
    }
    int n,k;
    cin>>n>>k;
    song com[100];
    for(int i=0;i<n;i++){
        cin>>com[i].len;
        for(int j=0;j<com[i].len;j++){
            cin>>com[i].p[j];
            int tmp=com[i].p[j]/16;
            com[i].period[tmp]++;
        }
    }
    double simil[100][2];
    for(int i=0;i<n;i++){
        double ans=0;
        for(int j=0;j<16;j++){
            ans+=pow(com[i].period[j],sample.period[j]);
        }
        simil[i][1]=i;
        simil[i][0]=sqrt(ans);
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(simil[j][0]<simil[i][0]){
                double m=simil[i][0];
                simil[i][0]=simil[j][0];
                simil[j][0]=m;
                int f=simil[i][1];
                simil[i][1]=simil[j][1];
                simil[j][1]=f;
            }
            else if(simil[j][0]==simil[i][0]&&simil[j][1]<simil[i][1]){
                double m=simil[i][0];
                simil[i][0]=simil[j][0];
                simil[j][0]=m;
                int f=simil[i][1];
                simil[i][1]=simil[j][1];
                simil[j][1]=f;
            }
        }
    }
    for(int i=0;i<k;i++){
        cout<<simil[i][1]<<' ';
    }
    return 0;
}
#include<iostream>
#include<stdio.h>
using namespace std;
typedef struct{
    int peo=0;
    int init=0;
}period;
int main(){
    //freopen("error (3).in","r",stdin);
    int n,m,g;
    cin>>n>>m>>g;
    int sco[5000]={0};
    for(int i=0;i<n;i++){
        cin>>sco[i];
    }
    
        int gap=100/m;
        period p[10];
        for(int j=0;j<m;j++){
            p[j].init=j*gap;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j!=m-1){
                if(sco[i]>=j*gap&&sco[i]<(j+1)*gap){
                        p[j].peo++;
                        break;
                    }
                }
                else{
                    if(sco[i]>=j*gap&&sco[i]<=(j+1)*gap)
                    p[j].peo++;
                    break;
                }
            }
        }
    if(g==1||g==0){
        period p_1[10];
        for(int i=0;i<m;i++){
            p_1[i]=p[i];
        }
        for(int i=0;i<m-1;i++){
            for(int j=i+1;j<m;j++){
                if(p_1[j].peo>p_1[i].peo){
                    period mid=p_1[i];
                    p_1[i]=p_1[j];
                    p_1[j]=mid;
                }
                else if(p_1[j].peo==p_1[i].peo&&p_1[j].init<p_1[i].init){
                    period mid=p_1[i];
                    p_1[i]=p_1[j];
                    p_1[j]=mid;
                }
            }
        }
        for(int j=0;j<m;j++){
            if(p_1[j].peo==0){
                continue;
            }
            else if(p_1[j].init!=100-gap){
                printf("[%2d,%3d): %d\n",p_1[j].init,p_1[j].init+gap,p_1[j].peo);
            }
            else{
                printf("[%2d,%3d]: %d\n",p_1[j].init,p_1[j].init+gap,p_1[j].peo);
            }
        }
    }
    if(g==0){
        cout<<'\n';
    }
    if(g==0||g==2){
        int flag=0;
        int max=0;
        for(int i=0;i<m;i++){
            if(p[i].peo>50){
                flag=1;
                if(p[i].peo>max){
                    max=p[i].peo;
                }
            }
        }
        if(flag!=0){
            /** 1*:max/50 people per star
             *  peo_1/max*50 how many star
             * e.g. 100/50=1 star=2 people
             * 20people=10 star=20/100*50
             */
            
            for(int i=0;i<m;i++){
                p[i].peo=p[i].peo*50/max;
            }
            
        }
        for(int i=0;i<m;i++){
            if(i!=m-1){
                printf("[%2d,%3d):",p[i].init,p[i].init+gap);
                
                for(int j=0;j<p[i].peo;j++){
                    cout<<'*';
                }
                cout<<endl;
            }
            else{
                printf("[%2d,%3d]:",p[i].init,p[i].init+gap);
                for(int j=0;j<p[i].peo;j++){
                    cout<<'*';
                }
                cout<<endl;
            }
        }
        
    }
    return 0;
}
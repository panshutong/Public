#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int num[4][3];
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            cin>>num[i][j];
        }
    }
    int xm=num[0][0],xmax=num[0][0],ymin=num[0][1],ymax=num[0][1],zmin=num[0][2],zmax=num[0][2];
    for(int i=0;i<4;i++){
        if(num[i][0]<xm){
            xm=num[i][0];
        }
        if(num[i][0]>xmax){
            xmax=num[i][0];
        }
        if(num[i][1]<ymin){
            ymin=num[i][1];
        }
        if(num[i][1]>ymax){
            ymax=num[i][1];
        }
        if(num[i][2]<zmin){
            zmin=num[i][2];
        }
        if(num[i][2]>zmax){
            zmax=num[i][2];
        }
    }
    int min=10000000;
    int times=0;
    int tans[1000][3];
    for(int x=xm;x<=xmax;x++){
        for(int y=ymin;y<=ymax;y++){
            
            for(int z=zmin;z<=zmax;z++){
               double me=0;
              int ans=0;
              for(int i=0;i<4;i++){
                  me+=(int)(floor(sqrt(1.0*(x-num[i][0])*(x-num[i][0])+1.0*(y-num[i][1])*(y-num[i][1])+1.0*(z-num[i][2])*(z-num[i][2]))));
              }
              
              ans=me;
              if(ans<min){
                min=ans;
                times=0;
                tans[times][0]=x;
                tans[times][1]=y;
                tans[times][2]=z;
                times++;
              } 
              else if(ans==min){
                tans[times][0]=x;
                tans[times][1]=y;
                tans[times][2]=z;
                times++;
              }

            }
        }
    }
    cout<<min<<" "<<times<<'\n';
    for(int i=0;i<times;i++){
        cout<<tans[i][0]<<' '<<tans[i][1]<<' '<<tans[i][2]<<'\n';
    }
    
    return 0;
}
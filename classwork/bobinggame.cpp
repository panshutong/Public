#include<iostream>
#include<stdio.h>
typedef struct{
    int a[6];
    int s;
    int r;
}mode;
using namespace std;
int main(){
    mode prize[12];
    int arr[12][6]={{4,4,4,4,1,1},{4,4,4,4,4,4},{1,1,1,1,1,1},{2,2,2,2,2,2},
    {4,4,4,4,4,-1},{2,2,2,2,2,-1},{4,4,4,4,-1,-1},{4,1,2,3,5,6},
    {4,4,4,-1,-1,-1},{2,2,2,2,-1,-1},{4,4,-1,-1,-1,-1},{4,-1,-1,-1,-1,-1}};
    for(int x=0;x<6;x++){
        prize[0].a[x]=arr[0][x];
    }
    prize[0].s=2048;
    prize[0].r=6;
    
    for(int x=0;x<6;x++){
        prize[1].a[x]=arr[1][x];
    }
    prize[1].s=1024;
    prize[1].r=6;
    
    for(int x=0;x<6;x++){
        prize[2].a[x]=arr[2][x];
    }
    prize[2].s=512;
    prize[2].r=6;
    
    for(int x=0;x<6;x++){
        prize[3].a[x]=arr[3][x];
    }
    prize[3].s=256;
    prize[3].r=6;
    
    for(int x=0;x<6;x++){
        prize[4].a[x]=arr[4][x];
    }
    prize[4].s=128;
    prize[4].r=5;
    
    for(int x=0;x<6;x++){
        prize[5].a[x]=arr[5][x];
    }
    prize[5].s=64;
    prize[5].r=5;
    
    for(int x=0;x<6;x++){
        prize[6].a[x]=arr[6][x];
    }
    prize[6].s=32;
    prize[6].r=4;
    
    for(int x=0;x<6;x++){
        prize[7].a[x]=arr[7][x];
    }
    prize[7].s=16;
    prize[7].r=6;
    
    for(int x=0;x<6;x++){
        prize[8].a[x]=arr[8][x];
    }
    prize[8].s=8;
    prize[8].r=3;
    
    for(int x=0;x<6;x++){
        prize[9].a[x]=arr[9][x];
    }
    prize[9].s=4;
    prize[9].r=4;
    
    for(int x=0;x<6;x++){
        prize[10].a[x]=arr[10][x];
    }
    prize[10].s=2;
    prize[10].r=2;
    
    for(int x=0;x<6;x++){
        prize[11].a[x]=arr[11][x];
    }
    prize[11].s=1;
    prize[11].r=1;
    int n=0;
    cin>>n;
    int num[n][6];
    int score=0;
    int flag[n]={0};
    for(int i=0;i<n;i++){//每一组输入数据
        for(int j=0;j<6;j++){
            cin>>num[i][j];
        }
        
        for(int m=0;m<12;m++){ 
            int right=0;//官级
            for(int j=0;j<6;j++){ //num中存储每个数
                for(int k=0;k<6;k++){
                    if(num[i][j]==arr[m][k]){
                        arr[m][k]=0;
                        right++;
                        break;
                    }
                } //官中特征数
            }
            for(int j=0;j<6;j++){
                if(arr[m][j]==0){
                    arr[m][j]=prize[m].a[j];
                }
            }
            if(right==prize[m].r){
                score+=prize[m].s;
                flag[i]=1;
                break;
            }
        }
        if(flag[i]==0){
           break; 
        }    
    }

    printf("%x\n",score);
    return 0;
}
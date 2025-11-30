#include<iostream>
using namespace std;
int main(){
    int num[6]={0};
    for(int i=27;i<64;i++){
        for (int m = 0; m < 6; m++)
    {
        num[m] = 0;
    } // 清空数组
    int mid = i;
    for (int j = 0; j < 6; j++)
    {
        num[j] = mid % 2;
        mid /= 2; // 每个人可能犯罪的情况
    }
        int a,b,c,d,e,f;
        num[0]+num[1]>0?a=1:a=0;
        num[0]+num[3]!=2?b=1:b=0;
        num[0]+num[4]+num[5]>=2?c=1:c=0;
        (num[1]+num[2]==0||num[1]+num[2]==2)?d=1:d=0;
        num[2]+num[3]==1?e=1:e=0;
        num[3]==0&&(num[3]+num[4]==0)?f=1:f=0;
        if(a+b+c+d+e+f==6){
            for(int n=0;n<6;n++){
                cout<<num[n];
            }
            cout<<endl;
            return 0;
        }  
    }
    return 0;
}

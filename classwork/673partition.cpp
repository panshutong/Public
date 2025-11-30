#include<iostream>
using namespace std;

int partition(int ary[],int left,int right){
    int compare=ary[left];
    int x=left,y=right;
    do{
        while(ary[y]>compare&&x<y){
            y--;
        }
        if(x<y){
            ary[x]=ary[y];
            x++;
        }
        while(ary[x]<compare&&x<y){
            x++;
        }
        if(x<y){
            ary[y]=ary[x];
            y--;
        }
    }while(x!=y);
    ary[x]=compare;
    return x;
}

int main(){
    int ary[10]={3,5,2,7,1,9,4,6,8,0};
    int ans=partition(ary,0,9);
    cout<<ans;
    return 0;
}
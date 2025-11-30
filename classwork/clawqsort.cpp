#include<iostream>
using namespace std;
int main(){
    int arr[10]={3,5,2,7,1,9,4,6,8,0};
    int z=0,y=9;
    int k=arr[z];
    do{
        while(z<y&&arr[y]>=k){
            y--;
        }
        if(z<y){
            arr[z]=arr[y];
            z++;
        }
        while(z<y&&arr[z]<=k){
            z++;
        }
        if(z<y){
            arr[y]=arr[z];
            y--;
        }
    }while(z!=y);
    arr[z]=k;
    return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;
int num1[1000000]={0};
int b_search(int arr[],int len,int a){
    int x=0,y=len-1;
    while(x<=y){
        int mid=(x+y)/2;
        if(arr[mid]==a){
            return mid;
        }
        else if(arr[mid]>a){
            y=mid-1;
        }
        else{
            x=mid+1;
        }
    }
    return -1;
}
int main(){
    int arr[5]={2,4,10,89,678};
    int a=b_search(arr,5,4);
    cout<<a;
    return 0;
}
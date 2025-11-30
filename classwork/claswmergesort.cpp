#include<iostream>
using namespace std;
void merge(int a[],int low,int mid,int high,int b[]);
void sort(int a[],int low,int high, int b[]){
    if(low<high){
        int mid=(low+high)/2;
        sort(a,low,mid,b);
        sort(a,mid+1,high,b);
        merge(a,low,mid,high,b);
    }
}
void merge(int a[],int low,int mid,int high,int b[]){
    int i=low,j=mid+1,k=0;
    while(i<=mid&&j<=high){
        if(a[i]<=a[j]){
            b[k++]=a[i++];
        }
        else{
            b[k++]=a[j++];
        }
    }
    while(i<=mid){
        b[k++]=a[i++];
    }
    while(j<=high){
        b[k++]=a[j++];
    }
    for(int p=low;p<=high;p++){
        a[p]=b[p-low];
    }
}
int main(){
    int b[10]={12,17,8,20,4,777,95,253,72,16},a[10]={0};
    int low=0,high=9;
    sort(b,low,high,a);
    for(int i=0;i<10;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
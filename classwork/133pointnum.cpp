#include<iostream>
using namespace std;
void seperate(int a,int d,int k,int i,int arr[]){
    if(a==0){
        return;
    }
    else if(i-k==50){
        int arr_[10]={0};
        for(int m=k;m<i;m++){
            arr_[arr[m]]++;
        }
        int times[51][10]={0};
        for(int m=0;m<10;m++){
            times[arr_[m]]
        }
    }
    else{
        a*=10;
        int b=a/d;
        arr[i]=b;
        i++;
        a%=d;
        seperate(a,d,k,i,arr);
    }
}
int main(){
    int n,d;
    cin>>n>>d;
    int arr[100]={0};
    int a=n/d;
    int i=0;
    int tmp=a;
    if(tmp!=0){
    while(tmp>0){
        arr[i]=tmp%10;
        tmp/=10;
        i++;
    }
}
else{
    arr[0]=0;
    i++;
}
    a=n%d;
    int k=i;
    seperate(a,d,k,i,arr);
    return 0;
}
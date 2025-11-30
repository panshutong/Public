#include<iostream>
using namespace std;
int arr[10]={0};
int flag[10]={0};
int tmp[10]={0};
int found=0;
bool check(int arr[],int sum,int len,int tmp[],int N){
    if(len==N){
            for(int j=0;j<N;j++){
                tmp[j]=arr[j];
            }
    }
    while(len>1){
            for(int j=0;j<len-1;j++){
                tmp[j]=tmp[j]+tmp[j+1];
            }
            len--;
    }
    if(len==1){
        return tmp[0]==sum;
    }
    return false;
        
    
        
}
void sortarr(int arr[],int N,int i,int flag[],int sum){
    if(found==1){
        return;
    }
    if(i==N){
        if(check(arr,sum,N,tmp,N)){
            for(int j=0;j<N;j++){
                cout<<arr[j]<<' ';
            }
            found=1;
            return;
        }
        
    }
    
        for(int j=0;j<N;j++){
            if(flag[j]==0){
                arr[i]=j+1;
                flag[j]=1;
                sortarr(arr,N,i+1,flag,sum);
                flag[j]=0;
            }
        }
    
}

int main(){
    int N,sum;
    cin>>N>>sum;
    sortarr(arr,N,0,flag,sum);
    
    return 0;
}
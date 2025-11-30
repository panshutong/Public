#include<iostream>
using namespace std;
typedef struct{
    long long in;
    int sep[100]={0};
    int t=0;
    long long loop=0;
}num;
int isloop(int arr[],int len){
    int mid=len/2;
    
        int right=0;
        for(int i=0;i<mid;i++){
            if(arr[i]==arr[len-1-i]){
                right++;
            }
        }
        if(right==mid){
            return 1;
        }
        else{
            return 0;
        }   
}
int sepnum(int arr[],long long x){
    long long tmp=x;
    int j=0;
    while(tmp!=0){
            arr[j]=tmp%10;
            tmp/=10;
            j++;
        } 
    return j;
}
void setzero(int arr[],int len){
    for(int i=0;i<len;i++){
        arr[i]=0;
    }
}
int main(){
    num n[10];
    for(int i=0;i<10;i++){
        cin>>n[i].in;
        long long tmp=n[i].in;
        int j=sepnum(n[i].sep,n[i].in);
        int x=0;
        n[i].loop=n[i].in;
        while(x==0){
            x=isloop(n[i].sep,j);
            
            if(x==1){
                break;
            }
            long long up=0;
            for(int k=0;k<j;k++){
                up*=10;
                up+=n[i].sep[k];
            }
            long long mid=up+n[i].loop;
            setzero(n[i].sep,j);
            j=sepnum(n[i].sep,mid);
            n[i].loop=mid;
            n[i].t++;
            
        }
        
    }
    for(int i=0;i<9;i++){
        for(int j=i+1;j<10;j++){
            if(n[j].t>n[i].t){
                num mi=n[i];
                n[i]=n[j];
                n[j]=mi;
            }
            else if(n[j].t==n[i].t&&n[j].loop<n[i].loop){
                num midd=n[i];
                n[i]=n[j];
                n[j]=midd;
            }
            else if(n[j].t==n[i].t&&n[j].loop==n[i].loop&&n[j].in<n[i].in){
                num middd=n[i];
                n[i]=n[j];
                n[j]=middd;
            }
        }
    }
    for(int i=0;i<10;i++){
        cout<<n[i].in<<' '<<n[i].t<<' '<<n[i].loop<<'\n';
    }
    return 0; 
}
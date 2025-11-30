#include<iostream>
#include<algorithm>
using namespace std;
int num1[1000000]={0},num2[10000]={0};
int in_arr[1000000]={0};
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
    int n=0;
    cin>>n;
    int x=0,y=0;
    
    for(int i=0;i<n;i++){
        int num;
        
        if(i==0){
            cin>>num;
            x=num;
            for(int j=0;j<num;j++){
                cin>>in_arr[j];
                num1[j]=in_arr[j];
                
            }
            sort(num1,num1+x);
        }
        else {
            num=0;
            cin>>num;
            for(int j=0;j<num;j++){
                y=0;
                cin>>in_arr[j];
                
                int tmp=b_search(num1,x,in_arr[j]);
                if(tmp!=-1){
                    num1[tmp]=num1[x-1];
                    
                    x--;
                    
                }
                else{
                    num1[x]=in_arr[j];
                    x++;
                    sort(num1,num1+x);
                }
                
            }
            
            
        }
    }
    long long ans=0;
    for(int i=0;i<x;i++){
        ans+=num1[i];
    }
    return 0;
}
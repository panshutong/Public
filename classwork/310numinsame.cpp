#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int ans=0;
    for(int i=a;i<=b;i++){
        int num_in[5]={0};
        int mid=i;
        int x=0;
        while(mid!=0){
            num_in[x]=mid%10;
            mid/=10;
            x++;
        }
        
        long long b=i*i;
        int num_out[10]={0};
        long long tmp=b;
        int y=0;
        while(tmp!=0){
            num_out[y]=tmp%10;
            tmp/=10;
            y++;
        }
        
        int right=0;
        for(int j=0;j<x;j++){
            if(num_in[j]==num_out[j]){
                right++;
            }
        }
        if(right==x){
            ans+=i;
        }
    }
    cout<<ans;
    return 0;
}
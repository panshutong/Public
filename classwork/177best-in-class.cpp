#include<iostream>

using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    long long num[n];
    int flag[n]={0};
    int s_num[n][10];
    int sum[n]={0};
    int m=0;
    for(int i=0;i<n;i++){
        cin>>num[i];
        long long mid=num[i];
        while(mid!=0){
            int h=0;
            s_num[i][h]=mid%10;
            sum[i]+=s_num[i][h];
            mid/=10;
            h++;
            
        }
        if(sum[i]%k==0){
            flag[i]=1;
            m++;
        }    
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(flag[i]==1&&flag[j]==1){
                if(num[j]<num[i]){
                    long long mid_=num[i];
                    num[i]=num[j];
                    num[j]=mid_;
                }
            }
        }
    }
    cout<<m<<endl;
    for(int i=0;i<n;i++){
        if(flag[i]==1){
            cout<<num[i]<<endl;
        }
    }
    
    
    return 0;
}
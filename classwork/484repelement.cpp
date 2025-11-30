#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int num[n];
    int times[n][2];
    int flag[n]={0};
    for(int i=0;i<n;i++){
        cin>>num[i];
        times[i][0]=num[i];
        times[i][1]=1;
    }
    for(int i=0;i<n;i++){
        if(flag[i]!=1){
            for(int j=i+1;j<n;j++){
                if(num[j]==num[i]){
                flag[j]=1;
                times[i][1]++;
                
                }
            }
            
        }

    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(times[j][0]<times[i][0]){
                int mid=times[i][0];
                times[i][0]=times[j][0];
                times[j][0]=mid;
                mid=times[i][1];
                times[i][1]=times[j][1];
                times[j][1]=mid;
            }
        }
    }
    int a=0;
    for(int i=0;i<n;i++){
        if(times[i][1]>1){
            cout<<times[i][0]<<':'<<times[i][1]<<endl;
            a++;
        }
    }
    if(a==0){
        cout<<"NO"<<endl;
    }
    return 0;
}
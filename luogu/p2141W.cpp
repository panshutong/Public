#include<iostream>
using namespace std;
int main(){
    int n=0;
    cin>>n;
    int num[n];
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(num[j]<num[i]){
                int mid=num[i];
                num[i]=num[j];
                num[j]=mid;
            }
        }
    }
    int times=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(num[i]+num[j]==num[k]){
                    times++;
                }
            }
        } //wrong appears when there are negative numbers like -1 1 3; 
        //O(n^3)can be upgrated
    }
    cout<<times<<endl;
    return 0;
}
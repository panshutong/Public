#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool check(vector<int>arr,int n,int sum){
    while(n>1){
        for(int i=0;i<n-1;i++){
            arr[i]=arr[i]+arr[i+1];
        }
        n--;
    }
    return arr[0]==sum;
}
int main(){
    int N,sum;
    if(cin>>N>>sum){
        vector<int>arr(N);
        for(int i=0;i<N;i++){
            arr[i]=i+1;
        }
        do{
            if(check(arr,N,sum)){
                for(int i=0;i<N;i++){
                    cout<<arr[i]<<' ';
                }
                return 0;
            }
        }while(next_permutation(arr.begin(),arr.end()));

    }
    return 0;
}
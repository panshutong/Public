#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    int count=0;
    do{
        count++;
        for(int i=0;i<5;i++){
            cout<<arr[i]<<" ";
        }
        if(count%5==0){
            cout<<endl;
        }
        
    }while(next_permutation(arr,arr+5));
    return 0;
}
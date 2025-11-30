#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n=0;
    cin>>n;
    int arr[]={1,2,3,4,5};
    int count=0;
    int num[120][5];
    do{
        
        for(int i=0;i<5;i++){
            num[count][i]=arr[i];
        }
        count++;
        
        
    }while(next_permutation(arr,arr+5));
    for(int j=0;j<120;j++){
        if(num[j][0]+4*num[j][1]+6*num[j][2]+4*num[j][3]+num[j][4]==n){
            cout<<num[j][0]<<" "<<num[j][1]<<" "<<num[j][2]<<" "<<num[j][3]<<" "<<num[j][4]<<endl;
            return 0;
        }
    }
    
}
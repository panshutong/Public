#include<iostream>
using namespace std;
int main(){
    int l=0,m=0;
    cin>>l>>m;
    int num[100][2]={0};
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            cin>>num[i][j];
        }
    }
    int arr_num[100][2]={0};
    arr_num[0][0]=num[0][0];
    arr_num[0][1]=num[0][1];
    int z=1;
    for(int i=1;i<m;i++){
        for(int j=0;j<i;j++){
            if(num[i][0]<=arr_num[j][1]&&num[i][0]>=arr_num[j][0]){
            if(num[i][1]>arr_num[j][1]){
                arr_num[j][1]=num[i][1];
            }

        }
        else if(num[i][1]<=arr_num[j][1]&&num[i][1]>=arr_num[j][0]){
            if(num[i][0]<arr_num[j][0]){
                arr_num[j][0]=num[i][0];
            }
        }
        else{
            arr_num[z][0]=num[i][0];
            arr_num[z][1]=num[i][1];
            z++;
        }
        }

    }
    int sum=0;
    for(int k=0;k<z;k++){
        sum+=arr_num[k][1]-arr_num[k][0]+1;
    }
    cout<<(l+1-sum)<<endl;
    return 0;
    

}
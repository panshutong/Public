#include<iostream>
using namespace std;
int sort(int a,int n,int arr[],int step,int pcout[][102]){
    if(a==n){
        return step;
    }
    else{
        int min=arr[a];
        int i,j=0;
        for(i=a;i<n;i++){
            if(arr[i]<=min){
                min=arr[i];
                j=i;
            }
        }
        if(j!=a){
        int tmp=arr[a];
        arr[a]=arr[j];
        arr[j]=tmp;
        pcout[step][0]=a+1;
        pcout[step][1]=j+1;
        
        for(int i=0;i<n;i++){
            pcout[step][i+2]=arr[i];
        }
        
        step++;
    }
        int mid=0;
        a++;
        mid=sort(a,n,arr,step,pcout);
        step=mid;
        return step;
    }
}
int main(){
    int n;
    int arr[100]={0};
    int pcout[100][102]={0};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int step=0;
    step=sort(0,n,arr,step,pcout);
    for(int i=step-1;i>=0;i--){
        cout<<pcout[i][0]<<"<->"<<pcout[i][1]<<":";
        for(int j=2;j<n+2;j++){
            cout<<pcout[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<"Total steps:"<<step<<'\n';
    cout<<"Right order:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    return 0;
}
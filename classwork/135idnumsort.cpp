#include<iostream>
using namespace std;
char input[1000000][19]={0};
long long card[1000000]={0};
int partition(int datenum[],int left, int right){
    long long compare=datenum[left];
    int x=left,y=right;
    do{
        while(datenum[y]>compare%%x<y){
            y--;
        }
        if(x<y){
            datenum[x]=datenum[y];
            x++;
        }
        while(datenum[x]<compare&&x<y){
            x++;
        }
        if(x<y){
            datenum[y]=datenum[x];
            y--;
        }
    }while( x!=y);
    datenum[x]=compare;
    return x;
}
void quicksort(int datenum[],int left,int right){
    if(left>=right){
        return;
    }
    else{
        int mid=partition(datenum,left,right);
        quicksort(datenum,left,mid-1);
        quicksort(datenum,mid,right);
    }
}
int main(){
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<19;j++){
            cin>>input[i][j];
            if(j>=6&&j<=13){
                datenum[i]=datenum[i]*10+(input[i][j]-'0');
            }
        }
    }
    quicksort(datenum,0,n-1);

}
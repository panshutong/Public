#include<iostream>
#include<cstring>
using namespace std;
int selectarr[100000]={0};
int outputarr[100]={0};
int main(){
    int N,D;
    cin>>N>>D;
    int integerpart=N/D;
    int decimalpart=N%D;
    if(N%D==0){
        cout<<integerpart<<'.'<<0;
        return 0;
    }
    else{
        cout<<integerpart<<'.';
        memset(selectarr,-1,100000*sizeof(int));
        int y=0;
        while(decimalpart!=0){
            int mid=decimalpart*10/D;
            if(selectarr[decimalpart]==-1){
                selectarr[decimalpart]=mid;
                outputarr[y]=mid;
                y++;
                decimalpart=decimalpart*10%D;
            }
            else{
                int loopstart=mid;
                int x=0;
                for(int i=0;i<y;i++){
                    if(outputarr[i]==loopstart){
                        x=i;
                        break;
                    }
                }
                for(int j=0;j<x;j++){
                    cout<<outputarr[j];
                }
                cout<<'(';
                for(int k=x;k<y;k++){
                    cout<<outputarr[k];
                }
                cout<<')';
                return 0;
            }
        }
        for(int i=0;i<y;i++){
            cout<<outputarr[i];
        }
        return 0;
    }

}
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int num[6]={0};
    int i=0;
    for(i=0;i<6;i+=2){
        cin>>num[i]>>num[i+1];
    }
    int j=0,k=1;
    i=0;
    int amout[3]={0};
    int last=0;
    for(j=0;j<3;j++){
        amout[j]=n/num[i];
        last=n%num[i];
        if(last!=0){
            amout[j]+=1;
        }
        else{
            amout[j]=amout[j];
        }
        amout[j]=amout[j]*num[k];
        i+=2;
        k+=2;
        last=0;
    }
    j=0,i=0;
    for(j=0;j<3;j++){
        if(amout[j]<amout[0]){
            amout[0]=amout[j];
        }
        else{
            amout[0]=amout[0];
        }
    }
    cout<<amout[0]<<endl;
    return 0;
}
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long n;
    cin>>n;
    int j=0;
   
    int num[20]={0};

    long long temp=n;
    do{
        num[j]=temp%10;
        temp=temp/10;
        j++;
    }while(temp>0);
    int i,k;
    int odd=0,even=0;
    int hhh=0;
    for(i=1;i<=j;i+=2){
        hhh=num[i]*2;
        if(hhh>=10){
            odd+=hhh%10+hhh/10;
            hhh=0;
        }
        else{
            odd+=hhh;
        }
    }
    for (k=0;k<=j;k+=2){
        even=even+num[k];
    }    
    
    
    int sum=odd+even;
    int end_sum=sum%10;
    if(end_sum!=0){
        cout<<"INVALID"<<endl;
    }else{
        if(j==15){
            cout<<"AMS"<<endl;
        }
        else if(j==16&&num[j-1]==4){
            cout<<"VISA"<<endl;
        }
        else{
            cout<<"MASTER"<<endl;
        }
    }
return 0;
}

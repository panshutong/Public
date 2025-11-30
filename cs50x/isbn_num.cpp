#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    char n[14];
    int num[14];
    for(int i=0;i<14;i++){
        scanf("%c",&n[i]);
    }
    for(int j=0;j<14;j++){
        num[j]=(int)(n[j]-48);
    }
    int cal=0;
    cal=num[0]*1+num[2]*2+num[3]*3+num[4]*4+num[6]*5+num[7]*6+num[8]*7+num[9]*8+num[10]*9;
    if(cal%11==10){
        if(n[12]=='X'){
            cout<<"Right"<<endl;

        }
        else{
            for(int s=0;s<12;s++){
            cout<<n[s];
        }
        cout<<'X'<<endl;
        }
    }
    
    else{ 
        if(num[12]==cal%11){
        cout<<"Right"<<endl;
    }
    else{
        for(int s=0;s<12;s++){
            cout<<n[s];
        }
        cout<<cal%11<<endl;
    }
}
    return 0;
}
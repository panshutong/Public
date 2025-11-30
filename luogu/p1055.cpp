#include<iostream>
using namespace std;
int main(){
    char num[14]={0};
    cin>>num;
    int num_[10]={0};
    num_[0]=(int)num[0]-'0';
    for(int i=1;i<4;i++){
        num_[i]=(int)num[i+1]-'0';
    }
    for(int i=4;i<9;i++){
        num_[i]=(int)num[i+2]-'0';
    }
    int sum=0;
    for(int i=0;i<10;i++){
        sum+=num_[i]*(i+1);
    }
    sum%=11;
    char ans;
    if(sum<10){
        ans=sum+'0';
    }
    else{
        ans=sum+('X'-10);
    }
    
    if(ans==num[12]){
        cout<<"Right"<<endl;
    }
    else{
        for(int i=0;i<12;i++){
            cout<<num[i];
        }
        cout<<ans;
    }
    return 0;
}
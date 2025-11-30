#include<iostream>
using namespace std;
# define m_m 300
int main(){
    int month[12]={0};
    int i;
    for(i=0;i<12;i++){
        cin>>month[i];
    }
    int last=0;
    int m_left=0;
    int n=0;
    int j=0;
    
    for(i=0;i<12;i++){
        n+=last/100;
        m_left=last%100;
        last=m_left+(m_m-month[i]);
        if(last<0){
            cout<<-(i+1)<<endl;
            j=1;

            break;
            
        }
        

    }
    if(j==0){
        n+=last/100;
    cout<<n*120+(last%100)<<endl;}
    return 0;
}
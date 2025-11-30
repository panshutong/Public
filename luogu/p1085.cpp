#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int num[14]={0};
    int i;
    for(i=0;i<14;i++){
        cin>>num[i];
    }
    int j;
    i=0;
    int time[7]={0};
    int day[7]={0};
    for(j=0;j<7;j++){
        time[j]=num[i]+num[i+1];
        
        day[j]=j+1;
    
        i+=2;
    }
    for(j=0;j<7;j++){
        if(time[j]>time[0]){
            time[0]=time[j];
            day[0]=day[j];
        }
    }
    if(time[0]<=8){
        cout<<"0"<<endl;
    }else{
        cout<<day[0]<<endl;
    }
    
    
    return 0;

}
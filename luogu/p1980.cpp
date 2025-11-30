#include<iostream>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    int i,j=1;
    int time=0;
    
    for(i=1;i<=n;i++){
        if(j/10!=0){
            if(j%10==x){
                time+=1;
            }
            while(j/10!=0){
                j=j/10;
                if(j%10==x){
                time+=1;
            }
            }
        }
        else{
            if(j%10==x){
                time+=1;
            }
        }
        j=i+1;
        
    }
    cout<<time<<endl;
    return 0;

}
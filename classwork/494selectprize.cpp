#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n;
    int m_p[n]={0};
    for(int i=0;i<n;i++){
        cin>>m_p[i];
    }
    cin>>m;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(m_p[i]+m_p[j]==m){
                cout<<i+1<<" "<<j+1<<endl;
                return 0;
            }
        }
    }
}
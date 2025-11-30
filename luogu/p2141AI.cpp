#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n=0;
    cin>>n;
    int num[n];
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    
    int times=0;
    sorT(num,num+n);
    
    for(int i=0;i<n;i++){
        int r=0,l=n-1;
        while(r<l){
            if(r==i){
                r++;
                continue;
            }
            if(l==i){
                l--;
                continue;
            }
            if(num[r]+num[l]==num[i]){
                times++;
                r++;
                l--;
                break;
            }
            else if(num[r]+num[l]<num[i]){
                r++;
            }
            else{
                l--;
            }
        }
    }
    cout<<times<<'\n';
    return 0;
}
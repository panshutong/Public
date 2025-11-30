#include<iostream>
#include<cmath>
using namespace std;
int y=1;
bool is_prime_fast[1001]={false};
bool isPrime(int i){
    if(i<=1) return false;
    if(i==2) return true;
    if(i%2==0){
            return false;
        }
        
        for(int t=3;t<=sqrt(i);t++){
            if(i%t==0){
                return false;
            }
        }
    
    return true;
        
}
int main(){
    int prime_arr[200]={0};
    prime_arr[0]=2;
    is_prime_fast[0]=true;

    
    for(int i=3;i<=1000;i++){
        if(isPrime(i)){
            prime_arr[y]=i;
            is_prime_fast[i]=true;
            y++;
        }
    }
    int N;
    cin>>N;
    int arr[50];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int checkans=0;
    for(int i=0;i<N;i++){
        int times=0;
        if(arr[i]%2==0){
            for(int x=0;x<y&&prime_arr[x]<arr[i];x++){
                int p1=2;
                int p2=prime_arr[x];
                int tmp=arr[i]-p1-p2;
                if(tmp<=p2){
                    break;
                }
                if(tmp<=1000&&is_prime_fast[tmp]){
                    times++;
                }
            }
        }
        else{
        for(int x=1;x<y&&prime_arr[x]<=arr[i]/3;x++){
            for(int m=x+1;m<y&&prime_arr[m]<arr[i];m++){
                int p1=prime_arr[x];
                int p2=prime_arr[m];
                int tmp=arr[i]-p1-p2;
                if(tmp<=p2){
                    break;
                }
                if(tmp<=1000&&is_prime_fast[tmp]){
                    times++;
                }
            }
        
        }
    }
        cout<<times<<' ';
    }
    return 0;
}

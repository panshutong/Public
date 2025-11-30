#include<iostream>
using namespace std;
long long matrix[2][2]={0};
void multmatrix(int N){
    if(N==1){
        matrix[0][0]=1;
        matrix[0][1]=1;
        matrix[1][0]=1;
        matrix[1][1]=0;
    }
    else{
        multmatrix(N/2);
        long long a=matrix[0][0];
        long long b=matrix[0][1];
        long long c=matrix[1][0];
        long long d=matrix[1][1];
        matrix[0][0]=(a*a+b*c)%1000000;
        matrix[0][1]=(a*b+b*d)%1000000;
        matrix[1][0]=(c*a+d*c)%1000000;
        matrix[1][1]=(c*b+d*d)%1000000;
        if(N%2==1){
            long long t0=matrix[0][0];
            long long t1=matrix[0][1];
            long long t2=matrix[1][0];
            long long t3=matrix[1][1];
            matrix[0][0]=(t0+t2)%1000000;
            matrix[0][1]=(t1+t3)%1000000;
            matrix[1][0]=t0;
            matrix[1][1]=t1;
        }
    }
}
int main(){
    long long N;
    cin>>N;
    if(N==0){
        cout<<0;
        return 0;
    }
    multmatrix(N);
    cout<<matrix[0][1]%10000;
    return 0;
}
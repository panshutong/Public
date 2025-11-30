#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int f;
    cin>>f;
    float c=(f-32)*5/9.0;
    cout<<fixed<<setprecision(2)<<c<<endl;
    return 0;
}
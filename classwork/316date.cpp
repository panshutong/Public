#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int num=n%7;
    char date[7][4]={"SAT","SUN","MON","TUE", "WED", "THU", "FRI",};
    cout<<date[num]<<'\n';
    return 0;
}
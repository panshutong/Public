#include<iostream>
#include<string>
using namespace std;
int main(){
    int d1,d2;
    cin>>d1>>d2;
    string dat[9]={"Sunday","Monday","Tuesday","Wednesday", "Thursday", "Friday","Saturday","Sunday","Monday"};
    cout<<dat[d1+1]<<endl<<dat[d2-1]<<endl;
    return 0;
}
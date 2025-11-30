#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

bool compareID(string a, string b){
    for(int i=6;i<=13;i++){
        if(a[i]!=b[i]){
            return a[i]>b[i];        
        }
    }
    for(int i=0;i<19;i++){
        if(a[i]!=b[i]){
            return a[i]>b[i];
        }
    }
    return 0;
}
int main(){
    int n=0;
    cin>>n;
    cin.ignore();
    string s;
    vector<string> input;
    for(int i=0;i<n;i++){
        getline(cin,s);
        input.push_back(s);
    }
    sort(input.begin(),input.end(),compareID);
    for(int i=0;i<n;i++){
        cout<<input[i]<<'\n';
    }
    return 0;
}
#include<iostream>
#include<string.h>
using namespace std;
int main(){
    char s[16];
    scanf("%s",&s);
    int n=strlen(s);
    long long ans[364],l=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n-1;k++){
                long long sum=0,cur=0;
                for(int p=0;p<=i;p++){
                    cur*=10;
                    cur+=s[p]-'0';
                }
                sum+=cur;
                cur=0;
                for(int p=i+1;p<=j;p++){
                    cur*=10;
                    cur+=s[p]-'0';
                }
                sum+=cur;
                cur=0;
                
            }
        }
    }
    return 0;

}
#include<bits/stdc++.h>

using namespace std;
int main(){
    char ans[5]={0};
    int a=0;
    for(int i=0;i<5;i++){
        scanf("%c",&ans[i]);
        if(ans[i]==' '||ans[i]=='\n'||ans[i]=='\0'){
            continue;
        }
        a++;
    }
    cout<<a<<endl;
    
    return 0;
}

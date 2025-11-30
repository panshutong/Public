#include <bits/stdc++.h>
using namespace std;
int a[8],n,m,maxn=-1,maxm=-1;
int main(){
    for(int i=1;i<=7;i++){
        scanf("%d%d",&n,&m);
        a[i]=n+m;
        if(a[i]>8 and a[i]>maxn){  //在一个for函数中完成多个任务，不需要一步一步的走了
            maxn=a[i];
            maxm=i;
        }
    }
    if(maxn==-1)printf("0");
    else printf("%d",maxm);
    return 0;
}
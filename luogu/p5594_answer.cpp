#include<bits/stdc++.h>
using namespace std;
bool a[1005][1005];
int ans;
int main()
{
    
    int n,m,k;
    memset(a,0,sizeof(a));
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int x;
            cin>>x;
            a[x][j]=1;
        }
    }
    for(int i=1;i<=k;i++)
    {
    	ans=0;
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]) ans++;
        }
        cout<<ans<<" ";
    }
}/*观赏即可，逻辑有点太复杂了*/

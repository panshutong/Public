#include <bits/stdc++.h>
using namespace std; 
int main() {
	int n,k=1;
	cin>>n;
	while (n>k) { //使用累减，简洁，并且同步计算k的加法
		n=n-k;
		k++;
	}
	if(k%2==0) cout<<n<<"/"<<(k+1-n);
	else cout<<k+1-n<<"/"<<n;
	return 0;
} 

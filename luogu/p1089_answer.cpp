#include<bits/stdc++.h>
using namespace std;
int n=0,s=0,y=0;
int main()
{
	for(int i=1;i<=12;i++)
	{
		cin >> y;
		n=n+300-y; 
		if(n < 0)//如果出现钱不够用，输出月份并跳出
		{
			cout << "-" << i; //直接return 0，不会再进行下一步运算
            //可以将‘-’看作字符，不是数字输出
			return 0;	
		} 
		while(n>=100) //在for函数内部进行计算，减去100，是每月后进行结算，更加贴近自然状态，更简洁
		{
			n-=100;
			s+=100;
		}
	}
	cout << s*1.2+n;
	return 0;
 } 

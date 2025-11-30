#include<iostream>
#include<cstring>
using namespace std;
void jia(char a[],char b[],int la,int lb,int d[])
{
	for(int i=0;i<max(la,lb);i++)
	{
		if(i<min(la,lb))
		{
			d[i]=d[i]+a[la-i-1]+b[lb-i-1]-2*'0';
			if(d[i]>=10) {d[i+1]++;d[i]-=10;}
		}
		else if(i<la)
		{
			d[i]=d[i]+a[la-i-1]-'0';
			if(d[i]>=10) {d[i+1]++;d[i]-=10;}
		}
		else if(i<lb)
		{
			d[i]=d[i]+b[lb-i-1]-'0';
			if(d[i]>=10) {d[i+1]++;d[i]-=10;}
		}
	}
}
void jian(char a[],char b[],int la,int lb,int d[])
{
	for(int i=0;i<max(la,lb);i++)
	{
		if(i<min(la,lb))
		{
			d[i]=d[i]+a[la-i-1]-b[lb-i-1];
			if(d[i]<0) {d[i+1]--;d[i]+=10;}
		}
		else if(i<la)
		{
			d[i]=d[i]+a[la-i-1]-'0';
			if(d[i]<0) {d[i+1]--;d[i]+=10;}
		}
	}
}
int com(char a[],char b[])
{
	if(strcmp(a,b)>=0) return 1;
	else return 0;
}
int main()
{
	char a[2002]={},b[2002]={},c;
	int d[1002]={0},fu=0,ia=0,ib=0,bi;
	cin>>c>>a>>b;
	int la=strlen(a),lb=strlen(b);
	if(a[0]=='-') {la--;ia=1;}
	if(b[0]=='-') {lb--;ib=1;}
	if(la>lb) bi=1;
	else if(la<lb) bi=0;
	else bi=com(a+ia,b+ib);
	if(a[0]=='-'&&b[0]=='-'&&c=='-')//---
	{
		if(bi==0) jian(b+ib,a+ia,lb,la,d);
		else {jian(a+ia,b+ib,la,lb,d);fu=-1;}
	}
	if(a[0]=='-'&&b[0]=='-'&&c=='+') {jia(a+ia,b+ib,la,lb,d);fu=-1;}//-+-
	if(a[0]!='-'&&b[0]=='-'&&c=='-') jia(a+ia,b+ib,la,lb,d);//+--
	if(a[0]!='-'&&b[0]=='-'&&c=='+')//++-
	{
		if(bi==1) jian(a+ia,b+ib,la,lb,d);
		else {jian(b+ib,a+ia,lb,la,d);fu=-1;}
	}
	if(a[0]=='-'&&b[0]!='-'&&c=='-') {jia(a+ia,b+ib,la,lb,d);fu=-1;}//--+
	if(a[0]=='-'&&b[0]!='-'&&c=='+')//-++
	{
		if(bi==0) jian(b+ib,a+ia,lb,la,d);
		else {jian(a+ia,b+ib,la,lb,d);fu=-1;}
	}
	if(a[0]!='-'&&b[0]!='-'&&c=='-')//+-+
	{
		if(bi==1) jian(a+ia,b+ib,la,lb,d);
		else {jian(b+ib,a+ia,lb,la,d);fu=-1;}
	}
	if(a[0]!='-'&&b[0]!='-'&&c=='+') jia(a+ia,b+ib,la,lb,d);//+++
	int x=max(la,lb);
	for(;d[x]==0;x--);
	if(fu==-1) cout<<"-";
	for(int i=x;i>=0;i--)
	{
		cout<<d[i];
	}
	cout<<endl;
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define ll long long
#define inf 1000000000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,block,cnt,ans;
int l[605],r[605];
int a[20005],b[20005],t[20005],disc[20005],belong[20005];
inline int lowbit(int x){return x&(-x);}
inline void update(int x,int val)
{
	for(int i=x;i<=n;i+=lowbit(i))
		t[i]+=val;
}
inline int query(int x)
{
	int sum=0;
	for(int i=x;i;i-=lowbit(i))
		sum+=t[i];
	return sum;
}
inline int disc_find(int x)
{
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(disc[mid]==x)return mid;
		else if(disc[mid]<x)l=mid+1;
		else r=mid-1;
	}
}
int finddown(int l,int r,int x)
{
	int ans=l-1,t=l;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[mid]<x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans-t+1;
}
int findup(int l,int r,int x)
{
	int ans=r+1,t=r;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[mid]>x)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return t-ans+1;
}
void rebuild(int x)
{
	for(int i=l[x];i<=r[x];i++)
		a[i]=b[i];
	sort(a+l[x],a+r[x]+1);
}
void solve(int x,int y)
{
	if(x==y)return;
	int L=r[belong[x]],R=l[belong[y]];
	if(b[x]<b[y])ans++;
	if(b[x]>b[y])ans--;
	if(belong[x]==belong[y])
	{
		for(int i=x+1;i<y;i++)
		{
			if(b[i]>b[x])ans++;
			if(b[i]<b[x])ans--;
			if(b[i]>b[y])ans--;
			if(b[i]<b[y])ans++;
		}
	}
	else 
	{
		for(int i=x+1;i<=L;i++)
		{
			if(b[i]>b[x])ans++;
			if(b[i]<b[x])ans--;
			if(b[i]>b[y])ans--;
			if(b[i]<b[y])ans++;
		}
		for(int i=R;i<y;i++)
		{
			if(b[i]>b[x])ans++;
			if(b[i]<b[x])ans--;
			if(b[i]>b[y])ans--;
			if(b[i]<b[y])ans++;
		}
		for(int i=belong[x]+1;i<belong[y];i++)
		{
			ans-=finddown(l[i],r[i],b[x]);
			ans+=finddown(l[i],r[i],b[y]);
			ans+=findup(l[i],r[i],b[x]);
			ans-=findup(l[i],r[i],b[y]);
		}
	}
	swap(b[x],b[y]);
	rebuild(belong[x]);rebuild(belong[y]);
}
int main()
{
	n=read();m=read();
	block=sqrt(n);
	if(n%block)cnt=n/block+1;
	else cnt=n/block;
	for(int i=1;i<=cnt;i++)
		l[i]=(i-1)*block+1,r[i]=i*block;
	r[cnt]=n;
	for(int i=1;i<=n;i++)
		belong[i]=(i-1)/block+1;
	for(int i=1;i<=n;i++)a[i]=b[i]=i;
	printf("%d\n",ans);
	
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		if(x>y)swap(x,y);
		solve(x,y);
		printf("%d\n",ans);
		for (int j=1;j<=n;j++)printf("%d",b[j]);puts("");
	}
	return 0;
}

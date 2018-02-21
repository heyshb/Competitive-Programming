#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>

typedef long long LL;

using namespace std;

int n,T,a[110],b[30010],f[30010],g[30010],sum[310],len;

int search(int x)
{
	int l=0,r=len,mid;
	while(l!=r-1)
	{
		mid=(l+r)>>1;
		if (g[mid]<=x) l=mid;
		else r=mid;
	}
	return l;
}

int main()
{

	int ans=0;
	g[1]=1000000000;
	memset(sum,0,sizeof(sum));
	scanf("%d%d",&n,&T);
	for (int i=1;i<=n;i++){scanf("%d",&a[i]);sum[a[i]]++;}
	for (int i=1;i<=300*n;i++)
	if (i<=n) b[i]=a[i];else b[i]=b[i-n];
	
	g[0]=0;
	for (int i=1;i<=300*n;i++)g[i]=1000000000;
		
	for (int i=1;i<=300*n;i++)
	{
		f[i]=search(b[i])+1;
		g[f[i]]=min(g[f[i]],b[i]);
	}
	
	
	if (T<=300) 
	{
		len=T*n;
		for (int i=1;i<=len;i++)
		{
			f[i]=search(b[i])+1;
			g[f[i]]=min(g[f[i]],b[i]);
			ans=max(ans,f[i]);
		}
		printf("%d\n",ans);
		return 0;
	}
	else len=n*300;
	


}

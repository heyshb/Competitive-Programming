#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map> 
typedef long long LL;

using namespace std;
map<int,int> sum;

int ans[510],tot=0,v[250010],now,n;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n*n;i++){scanf("%d",&v[i]);sum[v[i]]++;}
	sort(v+1,v+n*n+1);
	now=n*n;
	v[0]=-1;
	while(now)
	{
		int sumnow=0;
		while (v[now-1]==v[now]) now--;
		if (sum[v[now]])
		{
		}
	}
}

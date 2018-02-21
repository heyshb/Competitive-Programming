#include <bits/stdc++.h>
#define D 12
#define CNT 10
using namespace std;

typedef long long LL;
LL ans = 0;
int cnt = 0;


bool vis[12];
int digit[110];

bool check(LL x)
{
	
	for (int d = D-1; d>=2;d--)
	{
		memset(vis,false,sizeof(vis));
		int len = 0;
		LL tmp =  x;
		do
		{
			digit[++len] = tmp%d;
			tmp/=d;
		}while(tmp);
		for (int i = 1;i<=len;i++) vis[digit[i]] = true;
		for (int i = 0;i<d;i++) if (!vis[i]) return false;
	}
	return true;
}

bool used[20];
void dfs(int dep,LL v)
{
	if (dep==D+1)
	{
		if (check(v))
		{
			ans+=v;
			cnt++;
		}
		return;
	}
	int down = (dep==1?1:0);
	for (int i=down;i<D;i++)
	if (!used[i])
	{
		used[i] = true;
		dfs(dep+1,v*D+i);
		if (cnt==CNT) return;
		used[i] = false;
	}
}

int main()
{
	memset(used,false,sizeof(used));
	dfs(1,0);
	printf("%lld\n",ans);
}

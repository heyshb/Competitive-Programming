#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
LL a[210]; 
bool e[210][210];
int pos[210];
int book[210];
bool choose[210];
LL sum = 0;

void dfs(int x)
{
	sum += a[x]; 
	choose[x] = true;
	for (int i=1;i<=N;i++)
	if (e[x][i] && !choose[i])
	{
		dfs(i);
	}
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%lld",&a[i]),pos[i] = i,book[i] = i;
	int M;
	scanf("%d",&M);
	memset(e,false,sizeof(e));
	while(M--)
	{
		int type;
		scanf("%d",&type);
		if (type == 0)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			pos[++N] = x;
			a[N] = y;
			book[x] = N;
		}
		else
		{
			int x,l,r;
			scanf("%d%d%d",&x,&l,&r);
			for (int i=l;i<=r;i++)
			{
				e[book[x]][book[i]] = true;
			}
		}
	}
	LL ans = 1e18;
	for (int i=1;i<=N;i++)
	{
		memset(choose,false,sizeof(choose));
		sum = 0;
		dfs(i);
		ans = min(ans,sum);
	}
	printf("%lld\n",ans);
}

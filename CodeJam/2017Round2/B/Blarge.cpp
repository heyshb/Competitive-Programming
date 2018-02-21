#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,C,M;

struct ticket
{
	int seat,p;
}t[1010],cp[1010];

bool cmp(ticket a,ticket b)
{
	return a.seat < b.seat;
}
int f[1010];

int main()
{
	freopen("Blarge.in","r",stdin);
	//freopen("Blarge.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int _=1;_<=T;_++)
	{
		printf("Case #%d: ",_);
		scanf("%d%d%d",&N,&C,&M);
		int ans;
		for (int i=1;i<=M;i++)
		{
			scanf("%d%d",&t[i].seat,&t[i].p);
			
		}
		sort(t+1,t+M+1,cmp);
		for (int i=1;i<=M;i++)
			cp[i] = t[i];
		int ans1 = M, ans2 = 0;
		memset(f,0,sizeof(f));
		//puts("");
		//for (int i=1;i<=M;i++)printf("%d %d\n",t[i].seat,t[i].p);
		for (int i=1;i<=M;i++)
		if (t[i].seat > 1)
		{
			for (int j=1;j<i;j++)
				if (f[j] != -1 && t[j].seat > t[i].seat)
				{
					f[i] = f[j] = -1;
					ans1--;
				}
		}
		for (int i=1;i<=M;i++)
		if (t[i].seat > 1 && f[i] != -1)
			for (int j=1;j<=M;j++)
			if (f[j] != -1 && t[j].seat == t[i].seat)
			{
				f[i] = f[j] = -1;
				ans1--;
				ans2++;
			}
		printf("%d %d\n",ans1,ans2);
	}
}

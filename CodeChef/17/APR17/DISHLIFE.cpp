#include <bits/stdc++.h>

using namespace std;

int N,K;
int cnt[100010];
vector<int>v[100010];

int main()
{
	int Casi;
	scanf("%d",&Casi);
	while(Casi--)
	{
		memset(cnt,0,sizeof(cnt));
		scanf("%d%d",&N,&K);
		for (int i=1;i<=N;i++)
		{
			v[i].clear();
			int P,tmp;
			scanf("%d",&P);
			while(P--)
			{
				scanf("%d",&tmp);
				v[i].push_back(tmp);
				cnt[tmp]++;
			}
		}
		bool flag1 = true;
		for (int i=1;i<=K;i++)if (!cnt[i])
		{
			flag1 = false;
		}
		if (!flag1) puts("sad");
		else
		{
			bool flag2 = false;
			for (int i=1;i<=N;i++)
			{
				bool tmp2 = true;
				for (int j=0;j<v[i].size();j++)
					if (cnt[v[i][j]] <= 1) tmp2 = false;
				if (tmp2) flag2 = true;
			}
			puts(flag2?"some":"all");
		}
	}
}

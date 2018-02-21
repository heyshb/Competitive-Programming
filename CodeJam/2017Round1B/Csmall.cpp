#include <bits/stdc++.h>

using namespace std;

int N,Q;
int d[110][110];
int E[110],S[110];
double f[110];
double sum[110];

int main()
{
	freopen("Cs.in","r",stdin);
	freopen("Cs.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int _=1;_<=T;_++)
	{
		scanf("%d%d",&N,&Q);
		for (int i=1;i<=N;i++)scanf("%d%d",&E[i],&S[i]);
		for (int i=1;i<=N;i++)
			for (int j=1;j<=N;j++)scanf("%d",&d[i][j]);
		sum[1] = 0;
		for (int i=2;i<=N;i++)
			sum[i] = sum[i-1] + d[i-1][i];
		vector<double>ans;
		ans.clear();
		while(Q--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			f[1] = 0;
			for (int i=2;i<=N;i++)
			{
				f[i] = 1e15;
				for (int j=1;j<i;j++)
				if (E[j] > sum[i] - sum[j] - 1e-5)
					f[i] = min(f[i],f[j] + (sum[i]-sum[j])/S[j]);
			}
			ans.push_back(f[N]);
		}
		printf("Case #%d:",_);
		for (auto t:ans) printf(" %.10lf",t);
		puts("");
	}
}

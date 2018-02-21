#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
int P[20];
LL K;

vector<int>P1,P2,pp;
vector<LL>ans1,ans2;
double upbound = 1e18 + 0.5;

void dfs2(int dep,LL V,vector<LL>&ans)
{
	if (dep == pp.size())
	{
		ans.push_back(V);
		return;
	}
	while(true)
	{
		dfs2(dep+1,V,ans);
		if (1.0 * V * pp[dep] > upbound) break;
		V *= pp[dep];
	}
}

void gao(vector<int>PP,vector<LL>&ans)
{
	pp = PP;
	dfs2(0,1,ans);
}

LL calc(LL x)
{
	int Rnode = ans2.size() - 1;
	LL res = 0;
	for (int i=0;i<ans1.size();i++)
	{
		while(Rnode >= 0 && 1.0 * ans1[i] * ans2[Rnode] > x) Rnode--;
		if (Rnode == -1) break;
		//printf("%d %d\n",i,Rnode);
		res += Rnode + 1;
	}
	return res;
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d",&P[i]);
	scanf("%lld",&K);
	if (K == 1) return 0 * puts("1");
	int N1 = N/4, N2 = N-N1;
	if (2 * (N2 - N1 + 1) > N) N2++;
	for (int i=1;i<=N1;i++)P1.push_back(P[i]);
	for (int i=N2;i<=N;i++)P1.push_back(P[i]);
	for (int i=N1+1;i<N2;i++)P2.push_back(P[i]);
	//for (auto t:P1)printf("%lld ",t);puts("");
	//for (auto t:P2)printf("%lld ",t);puts("");
	gao(P1,ans1);
	gao(P2,ans2);
	sort(ans1.begin(),ans1.end());
	sort(ans2.begin(),ans2.end());
	//for (auto t:ans1)printf("%lld ",t);puts("");
	//for (auto t:ans2)printf("%lld ",t);puts("");
	//printf("%d %d\n",ans1.size(),ans2.size());
	LL L = 1, R = 1e18;
	while(L < R - 1)
	{
		//printf("%lld %lld\n",L,R);
		LL mid = (L + R) >> 1;
		if (calc(mid) >= K)
			R = mid;
		else
			L = mid;
	}
	printf("%lld\n",R);
	return 0;
}

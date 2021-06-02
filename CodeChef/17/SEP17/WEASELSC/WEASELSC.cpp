#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

typedef pair<long long,long long> PLL;
int N,K;
LL H[100010],H0[100010];
LL f[102][100010],g[102][100010];
int pre[100010]; 
const LL INF = 1e18;
vector<int>e[100010];
vector<pair<LL,LL> >stk[100010];
int top;
int step,node,nxt[100010];
LL nowans;

LL B(int j)
{
	return f[step][j] - LL(j) * H[j];
}

bool biu(PLL L1,PLL L2,PLL L3)
{
	LL K1,K2,K3,B1,B2,B3;
	K1=L1.first,B1=L1.second;
	K2=L2.first,B2=L2.second;
	K3=L3.first,B3=L3.second;
	//printf("%lld %lld\n",(B3-B1)*(K2-K3),(B3-B2)*(K1-K3));
	return (B3-B1)*(K2-K3)<=(B3-B2)*(K1-K3);
}

void add(LL KK,LL BB)
{
	PLL pp = make_pair(KK,BB);
	//printf("TOP = %d\n",top);
	//while(top>=2 && biu(pp,stk[top].back(),stk[top-1].back()))top--;
	if (top >= 2 && biu(pp,stk[top].back(),stk[top-1].back()))
	{
		if (biu(pp,stk[2].back(),stk[1].back()))
		{
			top = 1;
		}
		else
		{
			int L = 2, R = top, mid;
			while(L != R - 1)
			{
				int mid = (L + R) >> 1;
				if (biu(pp,stk[mid].back(),stk[mid-1].back()))
					R = mid;
				else
					L = mid;
			}
			top = L;
		}
	}
	stk[++top].push_back(pp);
}

void poptop()
{
	assert(top);
	stk[top].pop_back();
	top--;
}

LL calc(LL x,PLL L)
{
	return L.first * x + L.second; 
}

void dfs(int x)
{
	//if (K==50 && x%10000==1) printf("dfs %d\n",x);
	//f[i] = g[pre[i]] + H[i] * (i - pre[i]); 
	//printf("solve %d %d\n",step,x);
	//if (x==100000) puts("???");
	add(H[x],f[step][x]-LL(x)*H[x]);
	while(node < top && calc(x,stk[node].back()) < calc(x,stk[node+1].back())) node++;
	g[step][x] = calc(x,stk[node].back());
	//printf("g[%d][%d]=%lld\nf[%d][%d]=%lld\n",step,x,g[step][x],step,x,f[step][x]);
	int topnow = top,nodenow = node;
	for (auto t:e[x])
	{
		//if (x==100000) printf("??? %d\n",t);
		f[step][t]= g[step-1][x] + H[t] * (t - x);
		dfs(t);
		top = topnow;
		node = nodenow;
	}
	poptop();
}

void printstk()
{
	puts("stk");
	for (int i=1;i<=top;i++)
	{
		for (auto t:stk[i]) printf("%d ",t);
		puts("");
	}
}

LL solve()
{
	//puts("??");
	for (int i=0;i<=N;i++)stk[i].clear(),e[i].clear();
	for (int i=1;i<=N;i++)
	{
		int last = i-1;
		while(last != 0 && H[last] >= H[i]) last = pre[last];
		pre[i] = last;
		//printf("%d-->%d\n",pre[i],i);
		e[pre[i]].push_back(i);
		assert(pre[i] < i);
	}
	for (int i=N;i>=1;i--)
	{
		int last = i+1;
		while(last != N+1 && H[last] >= H[i]) last = nxt[last];
		nxt[i] = last;
		//printf("%d %d\n",i,nxt[i]);
	}
	//puts("done");
	for (int i=0;i<=N;i++)f[0][i] = -INF,g[0][i] = 0;
	f[0][0] = 0;
	nowans = -INF;
	for (step=1;step<=K+1;step++)
	{
		//printf("Step = %d\n",step);
		node = 1;
		top = 0;
		dfs(0);
		//printstk();
		for (int i=1;i<=N;i++)
			nowans = max(nowans,f[step][i] + H[i] * LL(nxt[i] - i - 1));
	}
	return nowans;
}

int main()
{
	//freopen("WEA.in","r",stdin);
	//freopen("W.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		//puts("solve new case");
		scanf("%d%d",&N,&K);
		for (int i=1;i<=N;i++)scanf("%lld",&H[i]),H0[i] = H[i];
		LL ans = solve();
		//for (int i=1;i<=N;i++)printf("%lld ",f[1][i]);puts("");
		for (int i=1;i<=N;i++)H[i] = H0[i];
		reverse(H+1,H+N+1);
		ans = max(ans,solve());
		printf("%lld\n",ans);
	}
}

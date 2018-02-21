#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct Graph
{
	vector<int>e[200010];
	vector<LL>d[200010];
	void add(int u,int v,LL w)
	{
		e[u].push_back(v);
		d[u].push_back(w);
	}
	void add2(int u,int v,LL w)
	{
		add(u,v,w);
		add(v,u,w);
	}
}G1,G2,G3;
int S,T,N,M;
int p[200010];

const int MOD = 1000000007;
LL dis[200010];
LL f1[200010],f2[200010];
bool inq[200010];
const LL INF = 1e17;
bool cmp(int a,int b)
{
	return dis[a] < dis[b];
}
queue<int>q;

void upd(LL &x){
	if (x < 0) x += MOD;
	if (x >= MOD) x -= MOD;
}
int main()
{
	//freopen("E.in","r",stdin);
	scanf("%d%d",&N,&M);
	scanf("%d%d",&S,&T);
	for (int i=1;i<=M;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		G1.add2(u,v,w);
	}
	q.push(S);
	for (int i=1;i<=N;i++)dis[i] = INF,inq[i] = false;
	inq[S] = true;
	dis[S] = 0;
	while(!q.empty())
	{
		int now = q.front();
		for (int i=0;i<G1.e[now].size();i++)
		if (dis[now] + G1.d[now][i] < dis[G1.e[now][i]])
		{
			dis[G1.e[now][i]] = dis[now] + G1.d[now][i];
			if (!inq[G1.e[now][i]])
			{
				q.push(G1.e[now][i]);
				inq[G1.e[now][i]] = true;
			}
		}
		inq[now] = false;
		q.pop();
	}
	//for (int i=1;i<=N;i++)printf("%d %lld\n",i,dis[i]);
	for (int i=1;i<=N;i++)
		for (int j=0;j<G1.e[i].size();j++)
			if (dis[i] + G1.d[i][j] == dis[G1.e[i][j]])
			{
				//printf("add %d %d %d\n",i,G1.e[i][j],G1.d[i][j]);
				G2.add(i,G1.e[i][j],G1.d[i][j]);
				G3.add(G1.e[i][j],i,G1.d[i][j]);
			}
	for (int i=1;i<=N;i++)p[i] = i;
	sort(p+1,p+N+1,cmp);
	assert(p[1] == S);
	memset(f1,0,sizeof(f1));
	memset(f2,0,sizeof(f2));
	f1[S] = 1;
	f2[T] = 1;
	
	for (int i=1;i<=N;i++)
	{
		int P = p[i];
		for (int j=0;j<G2.e[P].size();j++)
			upd(f1[G2.e[P][j]] += f1[P]);
	}
	for (int i=N;i>=1;i--)
	{
		int P = p[i];
		for (int j=0;j<G3.e[P].size();j++)
			upd(f2[G3.e[P][j]] += f2[P]);
	}
	
	//for (int i=1;i<=N;i++)printf("%d %d\n",f1[i],f2[i]);
	LL ans = 1LL * f1[T] * f1[T] % MOD;
	//printf("%d\n",ans);
	for (int i=1;i<=N;i++)
		if (dis[i] * 2LL == dis[T])
			upd(ans -= (1LL * f1[i] * f2[i] % MOD * f1[i] % MOD * f2[i] % MOD));
	for (int i=1;i<=N;i++)
	if (2LL * dis[i] < dis[T])
		for (int j=0;j<G2.e[i].size();j++)
		{
			int P = G2.e[i][j];
			if (2LL * dis[P] > dis[T])
			{
				upd(ans -= (1LL * f1[i] * f1[i] % MOD * f2[P] % MOD * f2[P] % MOD));
			}
		}
	ans %= MOD;
	if (ans < 0) ans += MOD;
	printf("%lld\n",ans);
}

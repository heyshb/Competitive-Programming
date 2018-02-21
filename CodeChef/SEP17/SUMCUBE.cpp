#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 300000;
LL fac[MAXN+10];
LL inv[MAXN+10];
const int MOD = 1000000007;
LL N,M,K;
LL d[100010];
vector<int>e[100010];

LL quick_pow(LL a,LL x)
{
	if (x < 0) return 0;
	LL res = 1;
	while(x)
	{
		if (x & 1) res = res * a % MOD;
		a = a * a % MOD;
		x >>= 1;
	}
	return res;	
}

LL C(LL N,LL M)
{
	if (N < M) return 0;
	return fac[N] * inv[M] % MOD * inv[N - M] % MOD;
}

LL solve1()
{
	return M * quick_pow(2LL,N-2) % MOD;
}

LL solve2()
{
	LL ans = 0;
	LL c1 = 0, c2;
	for (int i=1;i<=N;i++)
		c1 = (c1 + C(d[i],2)) % MOD;
	c2 = C(M,2) - c1;
	//printf("%lld %lld\n",c1,c2);
	ans += c1 * quick_pow(2LL,N-3) * 2LL % MOD;
	ans += c2 * quick_pow(2LL,N-4) * 2LL % MOD;
	ans %= MOD;
	ans += M * quick_pow(2LL,N-2) % MOD;
	ans %= MOD;
	return ans;
}

vector<int>lo,hi;
unordered_set<LL>edges;
bool vis[MAXN+10];
bool has(int L,int R){return edges.count(1LL*N*L + R) > 0;}
LL solve3()
{
	LL ans = 0;
	
	LL P3 = 0,P4 = 0,P5 = 0,P6 = 0;//Px:3 edges with x points
	
	//Solve P3: triple circle
	lo.clear();
	hi.clear();
	edges.clear();
	int lim = int(sqrt(M));
	for (int i=1;i<=N;i++)
	if (d[i] <= lim)
		lo.push_back(i);
	else
		hi.push_back(i);
	for (int i=1;i<=N;i++)
		for (auto t:e[i])//hash
		{
			edges.insert(1LL*N*i + t);
			edges.insert(1LL*N*t + i);
		}
		
	int NN = hi.size();//All big points
	for (int i=0;i<NN;i++)
		for (int j=i+1;j<NN;j++)
			for (int k=j+1;k<NN;k++)
			if (has(hi[i],hi[j]) && has(hi[i],hi[k]) && has(hi[j],hi[k]))
				P3++;
				
	for (int i=1;i<=N;i++)vis[i] = false;
	for (auto u:lo)
	{
		vis[u] = true;
		for (int i=0;i<e[u].size();i++)
		if (!vis[e[u][i]])
			for (int j=i+1;j<e[u].size();j++)
			if (!vis[e[u][j]])
			{
				if (has(e[u][i],e[u][j])) P3++;
			}
	}
	
	//printf("P3 = %lld\n",P3);
	
	//Solve P4: Chain or Star
	for (int i=1;i<=N;i++)//Star
		P4 += C(d[i],3);
	
	//printf("P4 star = %lld\n",P4);
		
	LL Chain = 0;//Chain
	for (int i=1;i<=N;i++)
		for (auto t:e[i])
		{
			Chain += (d[i]-1) * (d[t]-1);
			//printf("%d %d %lld\n",i,t,d[i]*d[t]);
		}
	//printf("chain = %lld\n",Chain); 
	Chain /= 2;
	Chain -= 3LL*P3;
	P4 += Chain;
	//printf("P4 Chain = %lld\n",Chain);
	
	//Solve P5: Double chain + single edge
	for (int i=1;i<=N;i++)
	{
		P5 += C(d[i],2) * (M - d[i]); 
		//printf("%d %lld\n",i,C(d[i],2) * (M - d[i]));
	}
	P5 -= 3LL * P3;
	P5 -= Chain * 2LL;
	//printf("P5 = %lld\n",P5);
	
	//Solve P6: Three single edges
	P6 = C(M,3) - P3 - P4 - P5;
	//printf("P6 = %lld\n",P6);
	
	//Done!
	P3 = ((P3 % MOD) + MOD) % MOD;
	P4 = ((P4 % MOD) + MOD) % MOD;
	P5 = ((P5 % MOD) + MOD) % MOD;
	P6 = ((P6 % MOD) + MOD) % MOD;
	
	ans = (ans + P3 * 6LL * quick_pow(2LL,N-3) % MOD) % MOD;
	ans = (ans + P4 * 6LL * quick_pow(2LL,N-4) % MOD) % MOD;
	ans = (ans + P5 * 6LL * quick_pow(2LL,N-5) % MOD) % MOD;
	ans = (ans + P6 * 6LL * quick_pow(2LL,N-6) % MOD) % MOD;
	
	LL c1 = 0, c2 = 0;
	for (int i=1;i<=N;i++)
		c1 = (c1 + C(d[i],2)) % MOD;
	c2 = C(M,2) - c1;
	//printf("%lld %lld\n",c1,c2);
	ans += c1 * quick_pow(2LL,N-3) * 6LL % MOD;
	ans += c2 * quick_pow(2LL,N-4) * 6LL % MOD;
	ans %= MOD;
	ans += M * quick_pow(2LL,N-2) % MOD;
	ans %= MOD;
	return ans;
}

int main()
{
	freopen("SUMCUBE.in","r",stdin);
	fac[0] = 1;
	for (int i=1;i<=MAXN;i++)fac[i] = fac[i-1] * LL(i) % MOD;
	inv[MAXN] = quick_pow(fac[MAXN],MOD-2);
	for (int i=MAXN-1;i>=0;i--)
		inv[i] = inv[i+1] * LL(i+1) % MOD;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&N,&M,&K);
		for (int i=1;i<=N;i++)e[i].clear(),d[i] = 0;
		for (int i=1;i<=M;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
			d[u]++;
			d[v]++;
		}
		//for (int i=1;i<=N;i++)printf("%lld\n",d[i]);
		if (K == 1) printf("%lld\n",solve1());
		else if (K == 2) printf("%lld\n",solve2());
		else printf("%lld\n",solve3());
	}
}

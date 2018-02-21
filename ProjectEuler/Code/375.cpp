#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL MOD = 50515093;
const LL cycle = 6308948;
const LL N = 2000000000;
const LL D = N / cycle;
const LL M = N % cycle;
LL v[cycle + 10]; 
pair<LL,int> p[cycle + 10];

int main()
{
	v[0] = 290797;
	for (int i=1;i<=cycle;i++) v[i] = v[i-1] * v[i-1] % MOD;
	for (int i=1;i<=cycle;i++) p[i] = make_pair(v[i],i);
	sort(p+1,p+cycle+1);
	printf("%lld\n",p[1].first);
	LL ans = 0;
	const LL INF = 100000000;
	set<LL>st; 
	st.insert(INF);
	st.insert(-INF);
	LL ma = -INF, mi = INF;
	for (int i=1;i<=cycle;i++)
	{
		LL V = p[i].first;
		LL pos = p[i].second;
		mi = min(mi,pos);
		ma = max(ma,pos);
		st.insert(pos);
		auto it = st.lower_bound(V);
		LL pred = (*(--it));
		LL succ = (*st.upper_bound(V));
		if (pred == -INF && succ == INF)
		{
			ans += (D - 2) * cycle * cycle;
			ans += cycle * pos;
			ans += cycle * (cycle - pos + 1);
		}
		else if (pred == -INF)
		{
			ans += (D - 1) * (pos - (ma - cycle)) * (succ - pos);
			ans += pos * (succ - pos);
		}
		else if (succ == INF)
		{
			ans += (D - 1) * (pos - pred) * (mi + cycle - pos);
			ans += (cycle - pos + 1) * (pos - pred);
		}
		else
		{
			ans += D * (pos - pred) * (succ - pred);
		}
	}
	ans += 3LL * (N - M);
	printf("%lld\n",ans);
}

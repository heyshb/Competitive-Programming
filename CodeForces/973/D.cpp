#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

char s[100010];
int N;
int ans[100010],K[100010],L[100010];
char ss[100010][310];
char S[100010];
LL MOD1 = 2333333333;
LL hash1[100010];
LL seed1 = 233;
int num[100010];
LL HS[100010];
vector<int>pos[100010];
map<LL,int>mp;
LL po(LL a,LL x,LL MOD)
{
	LL ret = 1;
	while(x)
	{
		if (x & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		x >>= 1;
	}
	return ret;
}

LL p[100010];

LL rev(LL x,LL MOD)
{
	return po(x,MOD - 2,MOD);
}

LL gethash(LL L,LL R)
{
	LL ret = (hash1[R] - hash1[L-1] * p[R-L+1] % MOD1)%MOD1;
	if (ret < 0) ret += MOD1;
	return ret;
}

int main()
{
	
	scanf("%s",s+1);
	N = strlen(s+1);
	p[0] = 1;
	for (int i=1;i<=N;i++) p[i] = p[i-1]*seed1%MOD1;
	for (int i=1;i<=N;i++)hash1[i] = (hash1[i-1]*seed1+s[i])%MOD1;
	int Q;
	scanf("%d",&Q);
	int split = 320;
	for (int _=1;_<=Q;_++)
	{
		int k;
		scanf("%d",&k);
		scanf("%s",S+1);
		int len = strlen(S+1);
		if (len <= split)
		{
			L[_] = len;
			K[_] = k;
			LL H = 0;
			for (int i=1;i<=len;i++)H = (H * seed1 + S[i]) % MOD1;
			HS[_] = H;
			mp[H] = _;
			//q[len].push_back(_);
		}
		else
		{
			LL H = 0;
			for (int i=1;i<=len;i++)H = (H * seed1 + S[i]) % MOD1;
			vector<int>tmp;
			tmp.clear();
			for (int i=1;i<=N-len+1;i++)
			if (gethash(i,i+len-1) == H) tmp.push_back(i);
			if (tmp.size() < k)
			{
				ans[_] = -1;
				continue;
			}
			ans[_] = 1e9;
			for (int i=0;i+k-1<tmp.size();i++)
				ans[_] = min(ans[_],tmp[i+k-1]-tmp[i]+len);
		}
	}
	for (int len=1;len<=split;len++)
	{
		for (int i=1;i<=N;i++)num[i] = 0;
		for (int i=1;i+len-1<=N;i++)
		{
			LL v = gethash(i,i+len-1);
			if (mp.find(v) != mp.end()) 
				pos[mp[v]].push_back(i);
		}
	}
	for (int q=1;q<=Q;q++)
	if (L[q])
	{
		if (pos[q].size() < K[q]) ans[q] = -1;
		else
		{
			ans[q] = 1e9;
			for (int i=0;i+K[q]-1<pos[q].size();i++) ans[q] = min(ans[q],pos[q][i+K[q]-1]-pos[q][i]);
			ans[q] += L[q];
		}
	}
	for (int i=1;i<=Q;i++)printf("%d\n",ans[i]);
}

#include <bits/stdc++.h>

using namespace std;

int N,A[110];
typedef long long LL;
const int up = 1e9 + 10;
unordered_map<int,vector<int> > t;
unordered_map<LL,int>sg;
const LL MOD = 1e12+7, seed = 252;
bool vis[40];

void ins(int v,int cnt)
{
	t[v].push_back(cnt);
}

LL calc(vector<int>v)
{
	if (v.empty()) return 0;
	sort(v.begin(),v.end());
	LL hsh = 0;
	for (auto tt:v)
		hsh = (hsh*seed + tt) % MOD; 
	if (sg.find(hsh) != sg.end()) return sg[hsh];
	vector<int>tmp,mex;
	mex.clear();
	for (auto tt:v)
	{
		tmp.clear();
		for (auto it:v)
		{
			if (it < tt) tmp.push_back(it);
			if (it > tt) tmp.push_back(it-tt);
		}
		mex.push_back(calc(tmp));
	}
	memset(vis,false,sizeof(vis));
	for (auto tt:mex) vis[tt] = true;
	for (int i=0;i<=10000;i++)if (!vis[i]) return sg[hsh] = i;
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d",&A[i]);
	for (int i=1;i<=N;i++)
	{
		int tmp = A[i];
		for (int j=2;j*j<=up;j++)
		if (tmp % j == 0)
		{
			int cnt = 0;
			while(tmp % j == 0)
			{
				cnt++;
				tmp /= j;
			}
			ins(j,cnt);
		}
		if (tmp > 1) ins(tmp,1);
	}
	int res = 0;
	for (auto it:t)
	{
		//for (auto tt:it.second) printf("%d ",tt);puts("");
		res ^= calc(it.second);
	}
	puts(res?"Mojtaba":"Arpa");
}

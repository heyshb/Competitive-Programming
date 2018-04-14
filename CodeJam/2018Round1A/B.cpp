#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct cashier
{
	LL M,S,P;
	LL mx;
}c[1010];

int C,R;
LL B;
vector<LL>tmp;

bool check(LL x)
{
	tmp.clear();
	int count = 0;
	for (int i=1;i<=C;i++)
	{
		c[i].mx = min(c[i].M,(x-c[i].P) / c[i].S);
		//printf("!!! %lld\n",c[i].mx);
		if (c[i].mx > 0)
			tmp.push_back(c[i].mx);
	}
	sort(tmp.begin(),tmp.end());
	LL sum = 0;
	int up = min(R,int(tmp.size()));
	for (int i=1;i<=up;i++)
		sum += tmp[tmp.size()-i];
	return sum >= B;
}

int main()
{
	freopen("2.in","r",stdin);
	int T;
	scanf("%d",&T);
	for (int _=1;_<=T;_++)
	{
		scanf("%d%lld%d",&R,&B,&C);
		for (int i=1;i<=C;i++)scanf("%lld%lld%lld",&c[i].M,&c[i].S,&c[i].P);
		printf("Case #%d: ",_);
		LL L = 0, R = 2e18;
		while(L < R - 1)
		{
			LL mid = (L + R) / 2;
			if (check(mid))
				R = mid;
			else 
				L = mid;
		}
		printf("%lld\n",R);
	}
} 

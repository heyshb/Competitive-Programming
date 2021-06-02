#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

vector<LL>neg;

int main()
{
	int N,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		LL cntp = 0, sump = 0, ans = 0;
		neg.clear();
		for (int i=1;i<=N;i++)
		{
			LL x;
			scanf("%lld",&x);
			if (x>=0)
			{
				sump+=x;
				cntp++;
			}
			else
			{
				neg.push_back(-x);
			}
		}
		sort(neg.begin(),neg.end());
		for (int i=0;i<neg.size();i++)
		if ((sump-neg[i])*(cntp+1) >= sump*cntp - neg[i])
		{
			sump -= neg[i];
			cntp++;
		}
		else
		{
			for (int j=i;j<neg.size();j++)
				ans -= neg[j];
			break;
		}
		ans += sump * cntp;
		printf("%lld\n",ans);
	}
}

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,Q;
LL a[300010];
vector<pair<LL,int> >v;
int main()
{
	scanf("%d%d",&N,&Q);
	for (int i=1;i<=N;i++)scanf("%lld",&a[i]);
	while(Q--)
	{
		int L,R;
		scanf("%d%d",&L,&R);
		v.clear();
		for (int i=L;i<=R && i<=L+150;i++)
		{
			v.push_back(make_pair(a[i],i));
		}
		sort(v.begin(),v.end());
		bool find = false;
		for (int i=0;i+2<v.size();i++)
		{
			if (v[i].first + v[i+1].first > v[i+2].first)
			{
				printf("%d %d %d\n",v[i].second,v[i+1].second,v[i+2].second);
				find = true;
				break;
			}
		}
		if (!find) puts("-1");
	}
}

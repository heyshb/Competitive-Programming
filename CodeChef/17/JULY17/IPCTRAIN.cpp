#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
priority_queue<pair<int,int> >heap;
int N,M;
vector<pair<int,int> >d[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		for (int i=1;i<=M;i++)d[i].clear();
		while(!heap.empty()) heap.pop();
		LL ans = 0;
		for (int i=1;i<=N;i++)
		{
			int D,T,S;
			scanf("%d%d%d",&D,&T,&S);
			d[D].push_back(make_pair(S,T));
			ans += LL(T)*LL(S);
		}
		for (int i=1;i<=M;i++)
		{
			for (auto t:d[i])
				heap.push(make_pair(t.first,t.second));
			if (!heap.empty())
			{
				auto now = heap.top();
				heap.pop();
				ans -= LL(now.first);
				if (now.second > 1)
					heap.push(make_pair(now.first,now.second-1));
			}
		}
		printf("%lld\n",ans);
	}
}


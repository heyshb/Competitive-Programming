#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,K;
LL C[300010];
priority_queue<pair<LL,LL> >heap;
int ans[300010]; 

int main()
{
	scanf("%d%d",&N,&K);
	for (int i=1;i<=N;i++)scanf("%lld",&C[i]);
	for (int i=1;i<=K;i++)heap.push(make_pair(C[i],i));
	LL sum = 0;
	for (int i=K+1;i<=N+K;i++)
	{
		if (i <= N) heap.push(make_pair(C[i],i));
		auto p = heap.top();
		sum += p.first * (i-p.second);
		ans[p.second] = i;
		heap.pop();
	}
	printf("%lld\n",sum);
	for (int i=1;i<=N;i++)printf("%d%c",ans[i]," \n"[i==N]);
}

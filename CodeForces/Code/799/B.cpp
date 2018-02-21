#include <bits/stdc++.h>

using namespace std;

multiset<pair<int,int> >s[3];
int p[200010],a[200010],b[200010];
int N;

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d",&p[i]);
	for (int i=1;i<=N;i++)scanf("%d",&a[i]);
	for (int i=1;i<=N;i++)scanf("%d",&b[i]);
	for (int i=1;i<=N;i++)
	{
		s[a[i]].insert(make_pair(p[i],i));
		//printf("INS %d %d %d\n",a[i],p[i],i);
		if (a[i] != b[i])
			s[b[i]].insert(make_pair(p[i],i));
	}
	int M;
	scanf("%d",&M);
	int INF = 1000000007;
	p[0] = INF;
	while(M--)
	{
		int c;
		scanf("%d",&c);
		int pp = 0;
		if(s[c].size()>0)
			pp = (*s[c].begin()).second;
		int w = p[pp];
		if (w == INF) printf("-1 ");
		else
		{
			printf("%d ",w);
			s[a[pp]].erase(s[a[pp]].find(make_pair(w,pp)));
			if (a[pp] != b[pp])
				s[b[pp]].erase(s[b[pp]].find(make_pair(w,pp)));
		}
	}
}

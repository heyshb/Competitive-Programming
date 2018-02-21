#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > f[2];//P,B
vector<pair<int,int> > mini[2];

int N,c,d;
int b[100010],p[100010],type[100010];


int main()
{
	scanf("%d%d%d",&N,&c,&d);
	char tmp[2];
	int maxc = 0,maxd = 0;
	for (int i=1;i<=N;i++)
	{
		scanf("%d%d",&b[i],&p[i]);
		scanf("%s",tmp);
		if (tmp[0] == 'C')
		{
			if (p[i] <= c)
			{
				f[0].push_back(make_pair(p[i],b[i]));
				maxc = max(maxc,b[i]);
			}
		}
		else	
		{
			if (p[i] <= d)
			{
				f[1].push_back(make_pair(p[i],b[i]));
				maxd = max(maxd,b[i]);
			}
		}	
	}
	sort(f[0].begin(),f[0].end());
	sort(f[1].begin(),f[1].end());
	int ans = 0;
	if (maxc && maxd)
		ans = maxc + maxd;
	int head = 1,tail = 1;
	pair<int,int>q[100010];
	if (f[0].size())
		q[1] = f[0][0];
	for (int i=1;i<f[0].size();i++)
	{
		auto t = f[0][i];
		int upc = c - t.first;
		while(head<=tail && q[tail].first>upc) tail--;
		if (tail >= head)
		{
			ans = max(ans, t.second + q[tail].second);
		}
		if (tail<head || t.second > q[tail].second)
			q[++tail] = t;
	}
	head = 1;
	tail = 1;
	if (f[1].size())
		q[1] = f[1][0];
	for (int i=1;i<f[1].size();i++)
	{
		auto t = f[1][i];
		int upd = d - t.first;
		while(head<=tail && q[tail].first>upd) tail--;
		if (tail >= head)
		{
			ans = max(ans, t.second + q[tail].second);
		}
		if (tail<head || t.second > q[tail].second)
			q[++tail] = t;
	}
	printf("%d\n",ans);
}

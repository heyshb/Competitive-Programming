#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct dancer
{
	int x,t,id;
	pair<int,int>des;
};
bool cmp(dancer a,dancer b){return a.x<b.x;}
vector<dancer>g[200010][2];
int N,W,H;
pair<int,int>ans[100010];

int main()
{
	scanf("%d%d%d",&N,&W,&H);
	for (int i=1;i<=N;i++)
	{
		dancer tmp;
		int type;
		scanf("%d%d%d",&type,&tmp.x,&tmp.t);
		type--;
		tmp.id = i;
		g[tmp.x-tmp.t+100000][type].push_back(tmp);
	}
	for (int i=0;i<=200000;i++)
	{
		sort(g[i][0].begin(),g[i][0].end(),cmp);
		sort(g[i][1].begin(),g[i][1].end(),cmp);
		int N1 = g[i][0].size(), N2 = g[i][1].size();
		for (int j=0;j<N1;j++)
		{
			auto &t = g[i][0][j];
			int mo = N1 - j - 1;
			int xx1,yy1,xx2,yy2;
			yy1 = N2 - 1;
			xx1 = yy1 + 1;
			xx2 = N1 - j - 1;
			yy2 = xx2;
			if (xx1 <= N1 - j - 1)
			{
				t.des = make_pair(g[i][0][j+xx1].x,H);
			}
			else
			{
				t.des = make_pair(W,g[i][1][yy2].x);
			}
			ans[t.id] = t.des;
		}
		for (int j=0;j<N2;j++)
		{
			auto &t = g[i][1][j];
			int mo = N2 - j - 1;
			int xx1,yy1,xx2,yy2;
			yy1 = N1 - 1;
			xx1 = yy1 + 1;
			xx2 = N2 - j - 1;
			yy2 = xx2;
			if (xx1 <= N2 - j - 1)
			{
				t.des = make_pair(W,g[i][1][j+xx1].x);
			}
			else
			{
				t.des = make_pair(g[i][0][yy2].x,H);
			}
			ans[t.id] = t.des;
		}
	}
	for (int i=1;i<=N;i++)
		printf("%d %d\n",ans[i].first,ans[i].second);
}

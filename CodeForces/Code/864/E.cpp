#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct item
{
	int t,d,p,id;
}v[110];
int N;
bool cmp(item a,item b){return a.d < b.d;}
int f[2010];
pair<int,int> best[2010][110]; //t,last
int choose[2010];

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d%d%d",&v[i].t,&v[i].d,&v[i].p),v[i].d--,v[i].id = i;
	sort(v+1,v+N+1,cmp);
	memset(f,0,sizeof(f));
	for (int i=1;i<=N;i++)
	{
		for (int j=v[i].d;j>=v[i].t;j--)
		if (f[j-v[i].t] + v[i].p > f[j])
		{
			choose[j] = i;
			best[j][i] = make_pair(j-v[i].t,choose[j-v[i].t]);
			f[j] = f[j-v[i].t] + v[i].p;
		}
		for (int j=1;j<=2000;j++)
		{
			if (f[j-1] > f[j])
			{
				f[j] = f[j-1];
				choose[j] = choose[j-1];
				for (int k=1;k<=N;k++)
					best[j][k] = best[j-1][k];
			}
		}
	}
	printf("%d\n",f[2000]);
	vector<int>ans;
	for (int i=2000,j=choose[2000];i;)
	{
		if (!j) break;
		ans.push_back(v[j].id);
		auto pp = best[i][j];
		i = pp.first;
		j = pp.second;
	}
	printf("%d\n",ans.size());
	if (ans.size())
	{
		reverse(ans.begin(),ans.end());
		for (int i=0;i<ans.size();i++)printf("%d%c",ans[i]," \n"[i==ans.size()-1]);
	}
}

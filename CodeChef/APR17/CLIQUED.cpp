#include <bits/stdc++.h>

using namespace std;

const double INF = 1e18;
typedef long long LL;
int N,M,K,S;
double X;
vector<int>e[100010];
vector<double>len[100010];
double d[100010];
bool inq[100010];

void add(int a,int b,double c)
{
	e[a].push_back(b);
	e[b].push_back(a);
	len[a].push_back(c);
	len[b].push_back(c);
}

queue<int>q;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%lf%d%d",&N,&K,&X,&M,&S);
		N++;
		for (int i=1;i<=N;i++)e[i].clear(),len[i].clear();
		for (int i=1;i<=M;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			add(a,b,c);
		}
		for (int i=1;i<=K;i++)add(N,i,X/2);
		for (int i=1;i<=N;i++)d[i] = INF;
		d[S] = 0;
		memset(inq,false,sizeof(inq));
		q.push(S);
		inq[S] = true;
		while(!q.empty())
		{
			int now = q.front();
			q.pop();
			for (int i=0;i<e[now].size();i++)
			{
				int to = e[now][i];
				if (d[now] + len[now][i] < d[to])
				{
					d[to] = d[now] + len[now][i];
					if (!inq[to])
					{
						inq[to] = true;
						q.push(to);
					}
				}
			}
			inq[now] = false;
		}
		for (int i=1;i<N;i++)printf("%lld%c",LL(d[i]+0.5),i==N-1?'\n':' ');
	}
}

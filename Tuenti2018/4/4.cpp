#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int INF = 1e9;
int dx[8] = {2,2,-2,-2,1,1,-1,-1};
int dy[8] = {1,-1,1,-1,2,-2,2,-2};
int d[1010][1010];
queue<pair<int,int> >q;
int N,M;
char mp[1010][1010];

bool inr(int x,int y)
{
	return x>=1 && x<=N && y>=1 && y<=M;
}

int dist(int sx,int sy,int ex,int ey)
{
	for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++)
			d[i][j] = INF;
	d[sx][sy] = 0;
	q.push(make_pair(sx,sy));
	while(!q.empty())
	{
		auto now = q.front();
		q.pop();
		if (mp[now.X][now.Y] == '*')
		{
			for (int dir=0;dir<8;dir++)
			{
				int nx,ny;
				nx = now.X + 2*dx[dir];
				ny = now.Y + 2*dy[dir];
				if (inr(nx,ny) && d[nx][ny] == INF && mp[nx][ny] != '#')
				{
					d[nx][ny] = d[now.X][now.Y]+1;
					q.push(make_pair(nx,ny));
				}
			}
		}
		else
		{
			for (int dir=0;dir<8;dir++)
			{
				int nx,ny;
				nx = now.X + dx[dir];
				ny = now.Y + dy[dir];
				if (inr(nx,ny) && d[nx][ny] == INF && mp[nx][ny] != '#')
				{
					d[nx][ny] = d[now.X][now.Y]+1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
	return d[ex][ey];
}

int main()
{
	freopen("4.in","r",stdin);
	freopen("4.out","w",stdout);
	int T;
	int Case = 0;
	scanf("%d",&T);
	while(T--)
	{
		
		scanf("%d%d",&N,&M);
		for (int i=1;i<=N;i++)scanf("%s",mp[i]+1);
		int sx,sy,ex,ey,ex2,ey2;
		for (int i=1;i<=N;i++)
			for (int j=1;j<=M;j++)
			{
				if (mp[i][j] == 'S') 
				{
					sx = i;
					sy = j;
				}
				if (mp[i][j] == 'P')
				{
					ex = i;
					ey = j;
				}
				if (mp[i][j] == 'D')
				{
					ex2 = i;
					ey2 = j;
				}
			}
		
		printf("Case #%d: ",++Case);
		int ans = dist(sx,sy,ex,ey) + dist(ex,ey,ex2,ey2);
		if (ans >= INF)
		{
			puts("IMPOSSIBLE");
		}
		else printf("%d\n",ans);
	}
}

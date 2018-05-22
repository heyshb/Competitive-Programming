#include <bits/stdc++.h>
#define mp make_pair
#define X first 
#define Y second
using namespace std;

typedef long long LL;

int N,M;
char c[40][40];
bool vis[40][40];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
bool ok[40][40];
bool inrange(int x,int y)
{
	return x>=1 && x<=N && y>=1 && y<=M;
}
queue<pair<int,int> >q;

int mx,my,mx2,my2;
int bfs(int x,int y,int fuck)
{
	int cnt = 0;
	q.push(mp(x,y));
	vis[x][y] = 1;
	while(!q.empty())
	{
		auto now = q.front();
		q.pop();
		cnt++;
		for (int dir=0;dir<4;dir++)
		{
			int nx,ny;
			nx = now.X + dx[dir];
			ny = now.Y + dy[dir];
			if (!inrange(nx,ny)) continue;
			if (c[nx][ny] != c[now.X][now.Y]) continue;
			if (!fuck)
			{
				if (nx <= mx && ny <= my) continue;
				if (nx >= mx2 && ny >= my2) continue;
			}
			else if (fuck == 1)
			{
				if (!(nx <= mx && ny <= my)) continue;
			}
			else
			{
				if (!(nx >= mx2 && ny >= my2)) continue;
			}
			if (vis[nx][ny]) continue;
			vis[nx][ny] = true;
			q.push(mp(nx,ny));
		} 
	}
	return cnt;
}

int ans;

void solve()
{
	memset(vis,false,sizeof(vis));
	for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++)
		{
			memset(vis,false,sizeof(vis));
			mx = i;
			my = j;
			int ret = bfs(i,j,1);
			for (int k=1;k<=N;k++)
				for (int l=1;l<=M;l++)
				if (!vis[k][l] && c[k][l] != c[i][j] && !(k<=mx && l<=my) && !(k>=mx2 && l>=my2))
				{
					bool neigh = false;
					for (int dir=0;dir<4;dir++)
					neigh |= (vis[k+dx[dir]][l+dy[dir]]);
					if (neigh) ret += bfs(k,l,false);
				}
			ans = max(ans,ret);
		}
	for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++)
			if (inrange(i+1,j+1) && c[i][j] == c[i+1][j+1])
			{
				memset(vis,false,sizeof(vis));
				mx = i;
				my = j;
				mx2 = i+1;
				my2 = j+1;
				int ret = bfs(i,j,true) + bfs(i+1,j+1,2);
				for (int k=1;k<=N;k++)
				for (int l=1;l<=M;l++)
				if (!vis[k][l] && c[k][l] != c[i][j] && !(k<=mx && l<=my) && !(k>=mx2 && l>=my2))
				{
					bool neigh = false;
					for (int dir=0;dir<4;dir++)
					neigh |= (vis[k+dx[dir]][l+dy[dir]]);
					if (neigh) ret += bfs(k,l,false);
				}
				ans = max(ans,ret);
			}
}

char b[40][40];

int main()
{
	//freopen("D.in","r",stdin);
	int T,_=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		for (int i=1;i<=N;i++)scanf("%s",c[i]+1);
		memset(vis,false,sizeof(vis));
		ans = 0;
		mx = my = 0;
		mx2 = N+1;my2 = M+1;
		for (int i=1;i<=N;i++)	
			for (int j=1;j<=M;j++)
			if (!vis[i][j])
			{
				ans = max(ans,bfs(i,j,false));
			}
		solve();
		for (int i=1;i<=M;i++)
			for (int j=1;j<=N;j++)
				b[i][j] = c[j][M+1-i];
		swap(N,M);
		solve();
		for (int i=1;i<=M;i++)
			for (int j=1;j<=N;j++)
				b[i][j] = c[j][M+1-i];
		swap(N,M);
		solve();
		for (int i=1;i<=M;i++)
			for (int j=1;j<=N;j++)
				b[i][j] = c[j][M+1-i];
		swap(N,M);
		solve();
		printf("Case #%d: %d\n",++_,ans);
	}	
}

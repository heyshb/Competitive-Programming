#include <bits/stdc++.h>
#define mp make_pair
#define X first 
#define Y second
using namespace std;

typedef long long LL;
int N,M,Q;
LL down[200010][2];
LL rt[200010][3];
LL dis[200010][3];
bool vis[200010][3];
pair<int,int>pre[200010][3];
map<pair<pair<int,int>,pair<int,int>>,int>num;
map<pair<pair<int,int>,pair<int,int>>,LL>D;
int cnt = 0;
const LL INF = 2e18;
queue<pair<int,int> >q;
const int NLOG = 8000010;
const int MAXDEP = 17;
vector<int>e[NLOG];
int dfn[NLOG],dep[NLOG];
int anc[NLOG][MAXDEP+1];
int l[NLOG],r[NLOG];
LL tr[NLOG],timecnt;
int lowbit(int x){return x&-x;}
void add(int x,LL y){while(x<=cnt){tr[x]+=y;x+=lowbit(x);}}
LL getsum(int x){LL s = 0;while(x){s += tr[x];x-=lowbit(x);}return s;}

void dfs(int x)
{
	dfn[++timecnt] = x;
	l[x] = timecnt;
	for (auto t:e[x])
	{
		anc[t][0] = x;
		for (int i=1;i<=MAXDEP;i++)
			anc[t][i] = anc[anc[t][i-1]][i-1];
		dep[t] = dep[x] + 1;
		dfs(t);
	}
	r[x] = timecnt;
}

int lca(int x,int y)
{
	if (dep[x] < dep[y]) swap(x,y);
	int delta = dep[x] - dep[y];
	for (int i=0;i<=MAXDEP;i++)
	if (delta & (1<<i))
		x = anc[x][i];
	if (x==y) return x;
	for (int i=MAXDEP;i>=0;i--)
	if (anc[x][i] != anc[y][i])
		x = anc[x][i], y = anc[y][i];
	return anc[x][0];
}

bool inrange(int x,int y,int L,int R)
{
	return y>=0 && y<M && x>=L && x<=R;
}
const int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
priority_queue<pair<pair<LL,pair<int,int> >,pair<int,int> > >heap;
void divide(int L,int R)
{
	if (L > R) return;
	int mid = (L + R) >> 1;
	//printf("solve %d %d\n",L,R);
	for (int i=0;i<M;i++)
	{
		//printf("%d %d\n",mid,i);
		for (int j=L;j<=R;j++)
			for (int k=0;k<M;k++)
			{
				num[mp(mp(mid,i),mp(j,k))] = ++cnt;
				dis[j][k] = INF;
				vis[j][k] = false;
			}
		dis[mid][i] = 0;
		vis[mid][i] = true;
		for (int d=0;d<4;d++)
		{
			int nx = mid+dx[d], ny = i+dy[d];
			if (!inrange(nx,ny,L,R)) continue;
			LL len;
			if (d==0) len = down[mid][i];
			if (d==1) len = rt[mid][i];
			if (d==2) len = down[mid][i-1];
			if (d==3) len = rt[mid-1][i];
			//printf("(%d,%d)-->(%d,%d) %lld\n",t.X,t.Y,nx,ny,len);
			heap.push(mp(mp(-len,mp(mid,i)),mp(nx,ny)));
		}
		while(!heap.empty())
		{
			auto t = heap.top().Y;
			//printf("%d %d\n",t.first,t.second); 
			LL dd = -heap.top().X.X;
			auto faq = heap.top().X.Y;
			heap.pop();
			if (vis[t.X][t.Y]) continue;
			dis[t.X][t.Y] = dd;
			vis[t.X][t.Y] = true;
			pre[t.X][t.Y] = faq;
			for (int d=0;d<4;d++)
			{
				int nx = t.X+dx[d], ny = t.Y+dy[d];
				if (!inrange(nx,ny,L,R)) continue;
				if (vis[nx][ny]) continue;
				LL len;
				if (d==0) len = down[t.X][t.Y];
				if (d==1) len = rt[t.X][t.Y];
				if (d==2) len = down[t.X][t.Y-1];
				if (d==3) len = rt[t.X-1][t.Y];
				//printf("(%d,%d)-->(%d,%d) %lld\n",t.X,t.Y,nx,ny,len);
				heap.push(mp(mp(-dis[t.X][t.Y]-len,mp(t.X,t.Y)),mp(nx,ny)));
			}
		}
		/*
		q.push(mp(mid,i));
		while(!q.empty())
		{
			auto t = q.front();
			q.pop();
			vis[t.X][t.Y] = false;
			//printf("d[%d][%d] = %lld\n",t.X,t.Y,dis[t.X][t.Y]);
			for (int d=0;d<4;d++)
			{
				int nx = t.X+dx[d], ny = t.Y+dy[d];
				if (!inrange(nx,ny,L,R)) continue;
				LL len;
				if (d==0) len = down[t.X][t.Y];
				if (d==1) len = rt[t.X][t.Y];
				if (d==2) len = down[t.X][t.Y-1];
				if (d==3) len = rt[t.X-1][t.Y];
				//printf("(%d,%d)-->(%d,%d) %lld\n",t.X,t.Y,nx,ny,len);
				if (dis[t.X][t.Y] + len < dis[nx][ny])
				{
					dis[nx][ny] = dis[t.X][t.Y] + len;
					pre[nx][ny] = t;
					if (!vis[nx][ny]) q.push(mp(nx,ny));
				}
			}
		}*/
		for (int j=L;j<=R;j++)
			for (int k=0;k<M;k++)
			{
				D[mp(mp(mid,i),mp(j,k))] = dis[j][k];
				//printf("dis[%d][%d] = %lld\npre[%d][%d]=(%d,%d)\n",j,k,dis[j][k],j,k,pre[j][k].first,pre[j][k].second);
				//printf("Num((%d,%d),(%d,%d)) = %d\n",mid,i,j,k,num[mp(mp(mid,i),mp(j,k))]);
				if (!(j==mid && k==i))
				{
					e[num[mp(mp(mid,i),pre[j][k])]].push_back(num[mp(mp(mid,i),mp(j,k))]);
					//printf("addedge %d %d\n",num[mp(mp(mid,i),pre[j][k])],num[mp(mp(mid,i),mp(j,k))]);
				}
			}
				
		dfs(num[mp(mp(mid,i),mp(mid,i))]);
	}
	divide(L,mid-1);
	divide(mid+1,R);
}

void modify(int rootx,int rooty,int u1,int v1,int u2,int v2,LL C)
{
	//printf("modify %d %d %d %d %d %d %lld\n",rootx,rooty,u1,v1,u2,v2,C);
	int p1 = num[mp(mp(rootx,rooty),mp(u1,v1))];
	int p2 = num[mp(mp(rootx,rooty),mp(u2,v2))];
	int lc = lca(p1,p2);
	//printf("%d %d %d %d %d %d\n",p1,p2,lc,l[p1],l[p2],l[lc]);
	add(l[p1],C);
	add(l[p2],C);
	add(l[lc],-C);
}

LL getres(int rootx,int rooty,int u,int v)
{
	int p = num[mp(mp(rootx,rooty),mp(u,v))];
	return getsum(r[p]) - getsum(l[p]-1);
}

int main()
{
	//freopen("QGRID.in","r",stdin);
	scanf("%d%d%d",&M,&N,&Q);
	for (int i=0;i<M-1;i++)
		for (int j=1;j<=N;j++)
			scanf("%lld",&down[j][i]);
	for (int i=0;i<M;i++)
		for (int j=1;j<N;j++)
			scanf("%lld",&rt[j][i]);
	/*
	if (M == 1) solve1();
	if (M == 2) solve2();
	if (M == 3) solve3();
	*/
	timecnt = 0;
	divide(1,N);
	//printf("cnt = %d\n",cnt);
	//printf("timecnt = %d\n",timecnt);
	while(Q--)
	{
		int type,u1,v1,u2,v2;
		LL c;
		scanf("%d",&type);
		if (type == 1)
		{
			scanf("%d%d%d%d%lld",&u1,&v1,&u2,&v2,&c);
			swap(u1,v1);
			swap(u2,v2);
			v1--;v2--;
			int L = 1, R = N;
			int rootx,rooty;
			LL mincost = INF;
			while(L <= R)
			{
				int mid = (L + R) >> 1;
				for (int i=0;i<M;i++)
				{
					LL d1 = D[mp(mp(mid,i),mp(u1,v1))], d2 = D[mp(mp(mid,i),mp(u2,v2))];
					if (d1 + d2 < mincost)
					{
						mincost = d1 + d2;
						rootx = mid;
						rooty = i;
					}
				}
				if (u1 > mid && u2 > mid)
				{
					L = mid + 1;
				}
				else if (u1 < mid && u2 < mid)
				{
					R = mid - 1;
				}
				else break;
			}
			modify(rootx,rooty,u1,v1,u2,v2,c);
		}
		else
		{
			scanf("%d%d",&u1,&v1); 
			swap(u1,v1);
			v1--;
			LL res = 0;
			int L = 1, R = N;
			int rootx,rooty;
			while(L <= R)
			{
				int mid = (L + R) >> 1;
				for (int i=0;i<M;i++)
				{
					res += getres(mid,i,u1,v1);
				}
				if (u1 > mid && u2 > mid)
				{
					L = mid + 1;
				}
				else if (u1 < mid && u2 < mid)
				{
					R = mid - 1;
				}
				else break;
			}
			printf("%lld\n",res);
		}
	}
}

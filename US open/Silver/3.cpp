#include <bits/stdc++.h>
#define mp make_pair
#define st first
#define ed second
using namespace std;

int N;
vector<int>e[1000010];
int v[251][251];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int num[1000010];
int M;
int fa1[100010],sz[100010];
int fa2[100010],sz2[100010];
int ans1 = 1, ans2 = -1;
vector<pair<pair<int,int> , pair<int,int> > >edge;

int find1(int x)
{
	return x==fa1[x]?x:fa1[x] = find1(fa1[x]);
}

void uno1(int x,int y)
{
	x = find1(x);
	y = find1(y);
	if (x == y) return;
	sz[x] += sz[y];
	ans1 = max(ans1,sz[x]);
	fa1[y] = x;
}

int find2(int x)
{
	return x==fa2[x]?x:fa2[x] = find2(fa2[x]);
}

bool debug;

void uno2(int x,int y)
{
	x = find2(x);
	y = find2(y);
	if (x == y) return;
	sz2[x] += sz2[y];
	//if (debug) printf("uno %d %d %d\n",x,y,sz2[x]);
	ans2 = max(ans2,sz2[x]);
	fa2[y] = x;
}

bool inr(int x,int y)
{
	return x>=0&&x<N&&y>=0&&y<N;
}

int get(int x,int y)
{
	return x*N+y;
}

int main()
{
	freopen("multimoo.in","r",stdin);
	freopen("multimoo.out","w",stdout);
	scanf("%d",&N);
	M = 0;
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
		{
			int tmp;
			scanf("%d",&tmp);
			if (!num[tmp]) num[tmp] = ++M;
			v[i][j] = num[tmp];
			e[v[i][j]].push_back(get(i,j));
		}
	for (int i=0;i<N*N;i++)fa1[i] = i, sz[i] = 1;
	/*
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)printf("%d",v[i][j]);
		puts("");
	}*/
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
			for (int k=0;k<4;k++)
			{
				int ni = i + dx[k], nj = j + dy[k];
				if (!inr(ni,nj)) continue;
				int x = v[i][j], y = v[ni][nj];
				int p1 = get(i,j), p2 = get(ni,nj);
				if (x == y)
				{
					uno1(p1,p2);
				}
				else if (x < y) 
				{
					edge.push_back(mp(mp(x,y),mp(p1,p2)));
				}
				else
				{
					edge.push_back(mp(mp(y,x),mp(p2,p1)));
				}
			}
	sort(edge.begin(),edge.end());
	for (int i=0;i<edge.size();i++)
	if (i==0 || edge[i].st != edge[i-1].st)
	{
		if (edge[i].st.st == edge[i].st.ed) continue;
		debug = (edge[i].st.st == 3 && edge[i].st.ed == 5);
		for (int j=i;j<edge.size() && edge[j].st == edge[i].st;j++)
		{
			
			int fp1 = find1(edge[j].ed.st), fp2 = find1(edge[j].ed.ed);
			//if (debug) printf("%d %d %d %d\n",fp1,fp2,sz[fp1],sz[fp2]);
			fa2[fp1] = fp1;
			sz2[fp1] = sz[fp1];
			fa2[fp2] = fp2;
			sz2[fp2] = sz[fp2];
		}
		
		for (int j=i;j<edge.size() && edge[j].st == edge[i].st;j++)
		{
			int fp1 = find1(edge[j].ed.st), fp2 = find1(edge[j].ed.ed);
			uno2(fp1,fp2);
		}
	}
	printf("%d\n%d\n",ans1,ans2);
}

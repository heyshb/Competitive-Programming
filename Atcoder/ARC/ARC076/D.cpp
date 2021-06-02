#include <bits/stdc++.h>

using namespace std;

int fa[100010];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);} 
int N;
struct point
{
	int x,y,num;
}p[100010];

bool cmp1(point a,point b){return a.x<b.x;}
bool cmp2(point a,point b){return a.y<b.y;}

struct edge
{
	int l,r,len;
};
vector<edge>e;
bool cmp(edge a,edge b){return a.len<b.len;}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		fa[i] = i;
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].num = i;
	}	
	e.clear();
	sort(p+1,p+N+1,cmp1);
	for (int i=1;i<N;i++)
		e.push_back((edge){p[i].num,p[i+1].num,p[i+1].x-p[i].x});
	sort(p+1,p+N+1,cmp2);
	for (int i=1;i<N;i++)
		e.push_back((edge){p[i].num,p[i+1].num,p[i+1].y-p[i].y});
	sort(e.begin(),e.end(),cmp); 
	int ans = 0;
	for (int i=0;i<e.size();i++)
	{
		if (find(e[i].l) != find(e[i].r))
		{
			ans += e[i].len;
			fa[find(e[i].l)] = find(e[i].r);
		}
	}
	printf("%d\n",ans);
}

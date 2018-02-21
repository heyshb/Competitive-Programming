#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct card
{
	int num,pos;
}c[100010];
bool cmp(card a,card b)
{
	if (a.num==b.num) return a.pos<b.pos;
	return a.num<b.num;
}
vector<int>p[100010];
bool ok[100010];
int N;
int T[100010];
int lowbit(int x){return x&-x;}
void add(int x,int y)
{
	//printf("add %d %d\n",x,y);
	while(x<=N){T[x]+=y;x+=lowbit(x);}
}
int getsum(int x){int s=0;while(x){s+=T[x];x-=lowbit(x);}return s;} 

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		scanf("%d",&c[i].num);
		c[i].pos = i;
	}
	memset(ok,true,sizeof(ok));
	for (int i=1;i<=N;i++)add(i,1);
	sort(c+1,c+N+1,cmp);
	for (int i=1;i<=N;i++)
		p[c[i].num].push_back(c[i].pos);
	c[N+1].num = -1;
	c[N+1].pos = -1; 
	int st = 1;
	LL ans = 0;
	for (int i=1;i<=N;i++)
	if (c[i].pos > c[i+1].pos || (c[i].num == c[i+1].num))
	{
		//printf("%d %d\n",c[i].num,c[i].pos);
		int R = c[i].pos;
		if (i != N)
		{
			int nv = c[i+1].num;
			auto tmp = lower_bound(p[nv].begin(),p[nv].end(),c[i].pos);
			if (tmp != p[nv].end())
			{
				//puts("haha");
				int index = tmp - p[nv].begin();
				R = c[i+p[nv].size()].pos;
				for (int j=index;j<p[nv].size();j++)
				if (ok[i + 1 + j])
				{
					ok[i + 1 + j] = false;
					add(c[i + 1 + j].pos, -1);
				}
			}
			else ans += getsum(N) - getsum(R);
		}
		for (int j=st;j<=i;j++)
		{
			if (ok[j])
			{		
				ok[j] = false;
				add(c[j].pos, -1);
			}
		}
		ans += getsum(R);
		//printf("ans = %lld\n",ans);
		st = i + 1;
	}
	printf("%d\n",ans + N);
}

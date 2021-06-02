#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool flag=true;
int color[100010];
int head[100010],en[200010],next[200010],cnt=0;
int ans1[100010],cnt1,ans2[100010],cnt2;

void add(int x,int y)
{
	cnt++;
	en[cnt]=y;
	next[cnt]=head[x];
	head[x]=cnt;
}

void dfs(int x)
{
	if (!color[x]) color[x]=1;
	for (int i=head[x];i;i=next[i])
	if (!color[en[i]])
	{
		color[en[i]]=3-color[x];
		dfs(en[i]);
		if (!flag) return;
	}
	else if (color[en[i]]==color[x]) {flag=false;return;}
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	for (int i=1;i<=n;i++)if (!color[i]) dfs(i);
	if (flag)
	{
		cnt1=cnt2=0;
		for (int i=1;i<=n;i++)
		if (color[i]==1) ans1[++cnt1]=i;
		else ans2[++cnt2]=i;
		printf("%d\n",cnt1);
		for (int i=1;i<cnt1;i++)printf("%d ",ans1[i]);
		printf("%d\n",ans1[cnt1]);
		
		printf("%d\n",cnt2);
		for (int i=1;i<cnt2;i++)printf("%d ",ans2[i]);
		printf("%d\n",ans2[cnt2]);
	}
	else puts("-1");
}

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;
int n;
int a[200010],cnt,o[200010];
int fa[200010];

int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)fa[i]=i;
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		o[i]=a[i];
		int x=find(i),y=find(a[i]);
		if (x==y){a[i]=x;}
		else {fa[x]=y;}
	}
	//for (int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
	//	for (int i=1;i<=n;i++)printf("%d ",fa[i]);puts("");
	int root=0;
	for (int i=1;i<=n;i++)if (fa[i]==i) root=i;
	for (int i=1;i<=n;i++)if (fa[i]==i && i!=root) a[i]=root;
	for (int i=1;i<=n;i++)if (a[i]!=o[i]) ans++;
	printf("%d\n",ans);
	for (int i=1;i<=n;i++)printf("%d ",a[i]);
} 

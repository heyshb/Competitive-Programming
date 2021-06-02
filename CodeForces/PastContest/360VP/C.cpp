
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring> 
using namespace std;

int n,k;
int c[510]; 
bool ok[510];

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)scanf("%d",&c[i]);
	int cnt=0,ans[510];
	memset(ok,false,sizeof(ok));
	ok[0]=true;
	for (int i=1;i<=n;i++)
		for (int j=k-c[i];j>=0;j--)
		if (ok[j]) ok[j+c[i]]=true;
	for (int i=0;i<=k;i++) if (ok[i]) ans[++cnt]=i;
	printf("%d\n",cnt);
	for (int i=1;i<cnt;i++)printf("%d ",ans[i]);printf("%d\n",ans[cnt]);
}

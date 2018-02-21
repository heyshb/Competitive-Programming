#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring> 
using namespace std;

int k,n,c[1000010];
int cnt,prime[100010],cnt2,prime2[100010],maxtime[100010];
bool flag[1000010];
bool vis[1000010];

int main()
{
	scanf("%d%d",&n,&k);
	int tmp;
	memset(vis,false,sizeof(vis));
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		vis[c[i]]=true;
	}
	memset(flag,true,sizeof(flag));
	flag[1]=false;
	cnt=0;
	for (int i=2;i<=1000000;i++)
	{
		if (flag[i]) prime[++cnt]=i;
		for (int j=1;j<=cnt;j++)
		{
			if (i*prime[j]<=1000000) flag[i*prime[j]]=false;
			else break;
			if (i%prime[j]==0) break;
		}
	}
	cnt2=0;
	for (int i=1;i<=cnt;i++)
		for (int j=1;j*prime[i]<=1000000;j++)
		if (vis[prime[i]*j])
		{
			if (prime2[cnt2]!=prime[i]) prime2[++cnt2]=prime[i];
			int tmp1=prime[i]*j,tmp2=0;
			while (tmp1%prime[i]==0)
			{
				tmp2++;
				tmp1/=prime[i];
			}
			maxtime[cnt2]=max(maxtime[cnt2],tmp2);
		}
	//for (int i=1;i<=cnt2;i++)printf("%d %d\n",prime2[i],maxtime[i]);
	for (int i=1;i<=cnt2;i++)
	{
		int tmp=0;
		while(k%prime2[i]==0) {k/=prime2[i];if (++tmp==maxtime[i]) break;}
		if (k==1) break;
	}
	puts(k==1?"Yes":"No");
}

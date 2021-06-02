#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

int n,f[110][3],a[110];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	memset(f,0,sizeof(f));
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=1;j++)
		if (a[i]&(1<<j))
			f[i][j]=max(f[i-1][2],f[i-1][1-j])+1;
		else
			f[i][j]=-1;
		f[i][2]=max(f[i-1][0],f[i-1][1]);
		f[i][2]=max(f[i][2],f[i-1][2]);
	}
	int ans=0;
	for (int i=0;i<=2;i++)ans=max(f[n][i],ans);
	printf("%d\n",n-ans);
} 

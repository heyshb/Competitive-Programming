#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
int a[100010];
char b[100010];

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d",&a[i]);
	scanf("%s",b + 1);
	int Lmin = -1e9, Rmin = 1e9, Lmax = -1e9, Rmax = 1e9;
	for (int i=5;i<=N;i++)
	{
		int mi = 1e9, ma = -1e9;
		for (int j=0;j<=4;j++)
		{
			mi = min(mi,a[i-j]);
			ma = max(ma,a[i-j]);
		}
		if (b[i] != b[i - 1])
		{
			if (b[i] == '0')
			{
				Rmax = min(Rmax,mi - 1);
			}
			else
			{
				Lmin = max(Lmin,ma + 1);
			}
		}
		else
		{
			bool allsame = true;
			for (int j=1;j<=4;j++)
			if (b[i-j] != b[i]) allsame = false;
			if (!allsame) continue;
			
			//allsame
			
			if (b[i] == '0')
			{
				Lmax = max(Lmax,ma);
			}
			else
			{
				Rmin = min(Rmin,mi);
			}
		}
	}
	//printf("%d %d %d %d\n",Lmin,Lmax,Rmin,Rmax);
	printf("%d %d\n",Lmin,Rmax);
}

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
int P;
int H[110],W[110];
double D[110];
double f[2000010];

int main()
{
	freopen("3.in","r",stdin);
	int T;
	scanf("%d",&T);
	for (int _=1;_<=T;_++)
	{
		printf("Case #%d: ",_);
		scanf("%d%d",&N,&P);
		int S = 0;
		double P0 = 0; 
		for (int i=1;i<=N;i++)
		{
			scanf("%d%d",&H[i],&W[i]);
			S += 4*(H[i] + W[i]);
			P -= 2*(H[i]+W[i]);
			P0 += 2*(H[i]+W[i]);
			if (H[i] > W[i]) swap(H[i],W[i]);
			D[i] = 2.0*sqrt(H[i]*H[i] + W[i]*W[i]);
			H[i] *= 2;
			//printf("%.3lf\n",D[i]);
		}
		S = min(S,P);
		for (int i=0;i<=S;i++)f[i] = 0;
		double ans = 0;
		for (int i=1;i<=N;i++)
			for (int j=S;j>=H[i];j--)
			{
				f[j] = max(f[j],f[j-H[i]] + D[i]);
				//printf("f[%d]=%.3lf\n",j,f[j]);
				ans = max(f[j],ans);
			}
		ans = min(ans,double(P));
		printf("%.8lf\n",ans + P0);
	}
} 

#include <bits/stdc++.h>

using namespace std;

int rd(int l,int r)
{
	return l + rand()%(r-l+1);
}
typedef long long LL;
LL H[100010];

int main()
{
	srand(time(0));
	freopen("WEA.in","w",stdout);
	int T = 5;
	int N = 100000;
	int K;
	printf("%d\n",T);
	while(T--)
	{
		//K = rd(0,min(N-1,50));
		//K = 0;
		K = rd(0,50);
		printf("%d %d\n",N,K);
		//for (int i=1;i<=N;i++)printf("%d ",rd(0,500000));puts("");
		for (int i=1;i<=N;i++)printf("%d ",rd(0,1));puts("");
		//H[0] = 500000;
		//for (int i=1;i<=N;i++)H[i] = H[i-1] - rd(1,5),printf("%lld ",H[i]);puts("");
		//for (int i=1;i<=N;i++)H[i] = 500000-rd(1,5),printf("%lld ",H[i]);puts("");
		//for (int i=1;i<=N;i++)if (i&1) printf("500000 ");else printf("1 ");puts("");
	}
}

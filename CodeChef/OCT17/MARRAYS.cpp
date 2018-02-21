#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int up = 2000000;
LL T1[up + 10], T2[up + 10];
const LL INF = 1e15;
int lowbit(int x){return x&-x;}
void add1(int x,LL y){while(x <= up){T1[x] = max(T1[x],y);x += lowbit(x);}}
LL get1(int x){LL res = -INF;while(x){res = max(res,T1[x]);x-=lowbit(x);}return res;}
void add2(int x,LL y){while(x){T2[x] = max(T2[x],y);x -= lowbit(x);}}
LL get2(int x){LL res = -INF;while(x <= up){res = max(res,T2[x]);x += lowbit(x);}return res;}
void clr(int xx)
{
	int x = xx;
	while(x <= up)T1[x] = T2[x] = -INF, x += lowbit(x);
	x = xx;
	while(x)T1[x] = T2[x] = -INF, x -= lowbit(x);
}
LL f[up + 10];
int A[up + 10],B[up + 10];
int T,N,M;

int main()
{
	//freopen("MAR.in","r",stdin);
	for (int i=0;i<=up;i++)T1[i] = T2[i] = -INF;
	scanf("%d",&T);
	while(T--)
	{
		LL ans = 0;
		scanf("%d",&M);
		vector<int>last;
		for (int r=1;r<=M;r++)
		{
			//printf("round %d\n",r);
			scanf("%d",&N);
			for (int i=1;i<=N;i++)scanf("%d",&A[i]);
			for (int i=1;i<N;i++)B[i] = A[i+1];
			B[N] = A[1];
			if (r > 1)
			{
				for (int i=1;i<=N;i++)
				{
					f[i] = max(get1(B[i]) + LL(r-1) * B[i], get2(B[i]) - LL(r-1) * B[i]);
					ans = max(ans,f[i]);
				}
				//for (int i=1;i<=N;i++) printf("%lld ",f[i]);puts("");
			}
			else for (int i=1;i<=N;i++)f[i] = 0;
			for (auto t:last) clr(t);
			//printf("%d %d????\n",r,N);
			last.clear();
			if (r < M)
			{
				//puts("fuck");
				for (int i=1;i<=N;i++)
				{
					last.push_back(A[i]);
					add1(A[i],LL(-r) * A[i] + f[i]);
					add2(A[i],LL(r) * A[i] + f[i]);
					//add1(A[i],LL(-r * A[i] + f[i]));
					//add2(A[i],LL(r * A[i] + f[i]));
				}
			}
		}
		printf("%lld\n",ans);
	}
}

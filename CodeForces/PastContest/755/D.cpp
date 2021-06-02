#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
LL tr[1000010];
int N,K;
int lowbit(int x){return x&-x;}
LL getsum(int x){LL s=0;while(x){s+=tr[x];x-=lowbit(x);}return s;}
void add(int x,int y){while(x<=N){tr[x]+=y;x+=lowbit(x);}}
int main()
{
	scanf("%d%d",&N,&K);
	if (K>N-K) K=N-K;
 	LL ans=1;
 	int pos=1,L,R;
 	for (int i=1;i<=N;i++)
 	{
 		ans++;
 		L=pos-K+1;
 		R=pos+K-1;
 		if (L<1)
 		{
 			ans+=getsum(N)-(getsum(L+N-1)-getsum(R));
 		}
 		else if (R>N)
 		{
 			ans+=getsum(N)-(getsum(L-1)-getsum(R-N));
 		}
 		else
 		{
 			ans+=getsum(R)-getsum(L-1);
 		}
 		add(pos,1);
 		printf("%I64d",ans);
 		if (i<N) printf(" ");
 		pos+=K;
 		if (pos>N) pos-=N;
 	}
}

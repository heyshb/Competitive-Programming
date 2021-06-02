#include <bits/stdc++.h>

using namespace std;

int N,M,A[100010];
int lb[100010],rb[100010];

int main()
{
	scanf("%d%d",&N,&M);
	for (int i=1;i<=N;i++)scanf("%d",&A[i]);
	A[0] = A[N+1] = -1;
	int tmp;
	for (int i=1;i<=N;i++)
	if (A[i]!=A[i-1])
		lb[i] = (tmp = i);
	else
		lb[i] = tmp;
	for (int i=N;i>=1;i--)
	if (A[i]!=A[i+1])
		rb[i] = (tmp = i);
	else
		rb[i] = tmp;
		
	//for (int i=1;i<=N;i++)printf("%d %d\n",lb[i],rb[i]);
	
	while(M--)
	{
		int L,R,K;
		scanf("%d%d%d",&L,&R,&K);
		int mid = (L+R)>>1;
		int ll,rr;
		ll = max(L,lb[mid]);
		rr = min(R,rb[mid]);
		if (rr-ll+1>=K)
			printf("%d\n",A[mid]);
		else
			puts("-1");
	}
}

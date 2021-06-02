#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,A[1000010]; 

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d",&A[i]);
	sort(A+1,A+N+1);
	int L,R;
	L = 1;
	R = N;
	while(A[L]==A[1] && L<=N) L++;
	while(A[R]==A[N] && R>=1) R--;
	int ans;
	if (L>R) ans = 0;
	else ans = R-L+1;
	printf("%d\n",ans);
}

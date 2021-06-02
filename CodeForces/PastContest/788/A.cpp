#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
LL A[100010];
LL B[100010];
LL S[100010];

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%I64d",&A[i]);
	for (int i=1;i<N;i++)B[i] = abs(A[i]-A[i+1]);
	S[0] = 0;
	LL MA1 = -1e14, MI2 = 0;
	LL ans = -1e14;
	for (int i=1;i<N;i++)
	{
		if (i&1)
			S[i] = S[i-1] + B[i];
		else
			S[i] = S[i-1] - B[i];	
		
		ans = max(ans, S[i] - MI2);
		ans = max(ans, -S[i] + MA1);
		
		if (i&1)
			MA1 = max(MA1, S[i]);
		else
			MI2 = min(MI2, S[i]);
	}
	printf("%I64d\n",ans);
}

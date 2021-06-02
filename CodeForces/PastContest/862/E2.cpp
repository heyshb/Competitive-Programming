#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int N,M,Q;
LL SA,A[100010],B[100010];
LL S[100010];
set<LL>st;

LL calc()
{
	LL res = 1e18;
	LL V = -SA;
	auto t = st.lower_bound(V);
	if (t != st.end())
		res = min(res,(*t) - V);
	if (t != st.begin())
		res = min(res,V - (*(--t)));
	return res;
}

int main()
{
	scanf("%d%d%d",&N,&M,&Q);
	for (int i=1;i<=N;i++)
	{
		scanf("%I64d",&A[i]);
		if (i & 1)
			SA += A[i];
		else
			SA -= A[i];
	}
	for (int i=1;i<=M;i++)scanf("%I64d",&B[i]);
	S[0] = B[0];
	for (int i=1;i<=M;i++)
	{
		S[i] = S[i-1];
		if (i & 1)
			S[i] -= B[i];
		else
			S[i] += B[i];
	}
	for (int i=0;i<=M-N;i++)
	{
		LL D = S[i+N] - S[i];
		if (i & 1)
			D = -D;
		st.insert(D);
	}
	printf("%I64d\n",calc());
	while(Q--)
	{
		int L,R;
		LL V;
		scanf("%d%d%I64d",&L,&R,&V);
		if ((L&1) == (R&1))
		{
			if (L&1)
				SA += V;
			else
				SA -= V;
		}
		printf("%I64d\n",calc());
	}
}
